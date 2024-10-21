#!/usr/bin/env python
# Copyright 2019 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

import argparse
import codecs
import math
import os
import re
import sys
import yaml

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import xngen
import xnncommon


parser = argparse.ArgumentParser(
  description='prelu microkernel test generator')
parser.add_argument("-t", "--tester", metavar="TESTER", required=True,
                    choices=["PReLUMicrokernelTester"],
                    help="Tester class to be used in the generated test")
parser.add_argument("-k", "--ukernel", metavar="FILE", required=True,
                    help="Microkernel type")
parser.add_argument("-o", "--output", metavar="FILE", required=True,
                    help='Output (C++ source) file')
parser.set_defaults(defines=list())


def split_ukernel_name(name):
  match = re.fullmatch(r"xnn_(f16|f32)_prelu_ukernel__(.+)_(\d+)x(\d+)", name)
  print("match : ", match)
  assert match is not None
  row_tile = int(match.group(3))
  channel_tile = int(match.group(4))

  arch, isa, assembly = xnncommon.parse_target_name(target_name=match.group(2))
  return row_tile, channel_tile, arch, isa

PRELU_TEST_TEMPLATE = """\
#define XNN_UKERNEL_WITH_PARAMS(arch_flags, ukernel, row_tile, channel_tile, datatype, params_type, init_params) \
XNN_TEST_PRELU_ROW_EQ(ukernel,arch_flags, ${", ".join(TEST_ARGS)});  
XNN_TEST_PRELU_ROW_DIV(ukernel,arch_flags,  ${", ".join(TEST_ARGS)});
XNN_TEST_PRELU_ROW_LT(ukernel,arch_flags,  ${", ".join(TEST_ARGS)});
XNN_TEST_PRELU_ROW_GT(ukernel,arch_flags,  ${", ".join(TEST_ARGS)});
"""

def main(args):
    options = parser.parse_args(args)
    tester = options.tester
    tester_header = {
    "PReLUMicrokernelTester": "prelu-microkernel-tester.h",
    }[tester]
    ukernel = options.ukernel

    # Assuming the spec file part will be uncommented and used
    # with codecs.open(options.spec, "r", encoding="utf-8") as spec_file:
    #     spec_yaml = yaml.safe_load(spec_file)
    #     if not isinstance(spec_yaml, list):
    #         raise ValueError("expected a list of micro-kernels in the spec")

    tests = """\
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// Auto-generated file. Do not edit!
//   Specification: {specification}
//   Generator: {generator}


#include <gtest/gtest.h>
#include "xnnpack/common.h"
#include "xnnpack/isa-checks.h"
#include "xnnpack/prelu.h"
#include "prelu-microkernel-tester.h"
""".format(specification=options.ukernel, generator=sys.argv[0])
    ukernel_parts = options.ukernel.split("-")
    datatype = ukernel_parts[0]
    op = ukernel_parts[1]
    test_args = ["row_tile"]
    test_args.append("channel_tile")
    test_args.append("init_params")
    tests += xnncommon.make_multiline_macro(xngen.preprocess(
      PRELU_TEST_TEMPLATE,
      {
          "TEST_ARGS": test_args,
          "TESTER": tester,
          "DATATYPE": datatype,
      },
  ))
    folder = datatype + "-" + ("prelu" if datatype.startswith("f") else op)
    print("options",options.ukernel)
    tests += f'#include "{xnncommon._XNNPACK_SRC}/{folder}/{options.ukernel}.h"\n'
    tests += "#undef XNN_UKERNEL_WITH_PARAMS\n"


    # Uncomment when using the spec file
    # for ukernel_spec in spec_yaml:
    #     name = ukernel_spec["name"]
    #     elements_tile, arch, isa = split_ukernel_name(name)

    #     test_case = generate_test_cases(name, elements_tile, isa)
    #     tests += "\n\n" + xnncommon.postprocess_test_case(test_case, arch, isa)

    xnncommon.overwrite_if_changed(options.output, tests)

if __name__ == "__main__":
  main(sys.argv[1:])