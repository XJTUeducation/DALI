// Copyright (c) 2017-2018, NVIDIA CORPORATION. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "dali/pipeline/operators/reader/coco_reader_op.h"

namespace dali {

DALI_REGISTER_OPERATOR(COCOReader, COCOReader, CPU);
DALI_SCHEMA(COCOReader)
  .NumInput(0)
  .NumOutput(3)
  .DocStr(R"code(Read data from a COCO dataset composed of directory with images
and an anotation files. For each image, with `m` bboxes, returns its bboxes as (m,4)
Tensor (`m` * `[x, y, w, h] or `m` * [left, top, right, bottom]`) and labels as `(m,1)` Tensor (`m` * `category_id`).)code")
  .AddArg("file_root",
      R"code(Path to a directory containing data files.)code",
      DALI_STRING)
  .AddArg("annotations_file",
      R"code(List of paths to the JSON annotations files.)code",
      DALI_STRING_VEC)
  .AddOptionalArg("file_list",
      R"code(Path to the file with a list of pairs ``file label``
(leave empty to traverse the `file_root` directory to obtain files and labels))code",
      std::string())
  .AddOptionalArg("ltrb",
      R"code(If true, bboxes are returned as [left, top, right, bottom], else [x, y, width, height]. Default: False)code",
      false)
  .AddOptionalArg("ratio",
      R"code(If true, bboxes returned values as expressed as ratio w.r.t. to the image width and height. Default: False)code",
      false)
  .AddParent("LoaderBase");

}  // namespace dali
