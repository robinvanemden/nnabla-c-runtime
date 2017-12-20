// Copyright (c) 2017 Sony Corporation. All Rights Reserved.
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

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <nnablart/network.h>
#include <nnablart/runtime.h>

#include "../runtime/runtime_internal.h"
#include "dump.h"
#include "dump_function.h"

static const char* const typenames[] = {{
{typenames}
}};
  

void dump_function(nn_network_t *net, nn_function_t* func) 
{{
  int i;
  int* list;
  
  printf("NNB: Function type:         %s(%d)\n", typenames[func->type], func->type);
  list = (int*)NN_GET(net, func->inputs.list);
  for(i = 0; i < func->inputs.size; i++ ) {{
    printf("NNB: Function input[%d]:   Variable id:%d\n", i, *(list + i));
  }}
  list = (int*)NN_GET(net, func->outputs.list);
  for(i = 0; i < func->outputs.size; i++ ) {{
    printf("NNB: Function output[%d]:  Variable id:%d\n", i, *(list + i));
  }}
  switch(func->type) {{
{dump}
  }}
}}

  

