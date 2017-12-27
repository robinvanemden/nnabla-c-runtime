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

#include <nnablart/functions.h>

#include "../../utilities.h"

#include <assert.h>
#include <math.h>

typedef struct {
  float *input;
  int input_size;
  float *output;
  int output_size;
} sigmoid_local_context_t;

// Sigmoid
void allocate_sigmoid_local_context(rt_function_t *f) {
  WHOAMI("%s\n", __func__);
  sigmoid_local_context_t *c = malloc(sizeof(sigmoid_local_context_t));
  f->config = (void *)c;
  assert(f->num_of_inputs == 1);
  assert(f->num_of_outputs == 1);
  c->input = f->inputs[0]->data;
  c->input_size = calc_shape_size(f->inputs[0]->shape);

  c->output = f->outputs[0]->data;
  c->output_size = calc_shape_size(f->outputs[0]->shape);

  assert(c->input_size == c->output_size);
}

void free_sigmoid_local_context(rt_function_t *f) {
  WHOAMI("%s\n", __func__);
  free(f->config);
}

void exec_sigmoid(rt_function_t *f) {
  WHOAMI("%s\n", __func__);
  sigmoid_local_context_t *c = (sigmoid_local_context_t *)(f->config);

  int i; // Iterator
  for (i = 0; i < c->output_size; i++) {
    float x = *(c->input + i);
    *(c->output + i) = 1.0f / (1.0f + expf(-x));
  }
}
