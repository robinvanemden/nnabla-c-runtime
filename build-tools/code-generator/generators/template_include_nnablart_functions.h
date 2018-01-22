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
// *WARNING*
// THIS FILE IS AUTO-GENERATED DUMMY CODE BY CODE GENERATOR.

#ifndef H_FUNCTIONS_H__
#define H_FUNCTIONS_H__

#ifdef __cplusplus
extern "C" {{
#endif /* __cplusplus */

#include <stdint.h>
#include <stdio.h>

#include <nnablart/network.h>

typedef enum {{
  RT_FUNCTION_ERROR_UNIMPLEMENTED = -999, ///< Invalid shape. (-999)
  RT_FUNCTION_ERROR_MALLOC, ///< Memory allocation error. (-998)
  RT_FUNCTION_ERROR_INVALID_NUM_OF_INPUTS,  ///< Invalid number of inputs.(-997)
  RT_FUNCTION_ERROR_INVALID_NUM_OF_OUTPUTS, ///< Invalid number of outputs. (-996)
  RT_FUNCTION_ERROR_INVALID_SHAPE,          ///< Invalid shape. (-995)
  RT_FUNCTION_ERROR_NOERROR = 0             ///< No error. (0)
}} rt_function_error_t;

// version of cforwardprop library
#define NNABLART_MAJOR_VERSION (1)
#define NNABLART_MINOR_VERSION (0)

  typedef struct {{
      int size;
      int *data;
  }} rt_list_t;

  typedef enum {{
    RT_BUFFER_ALLOCATE_TYPE_MALLOC = 0, RT_BUFFER_ALLOCATE_TYPE_ALLOCATED,
    RT_BUFFER_ALLOCATE_TYPE_STINGY, RT_BUFFER_ALLOCATE_TYPE_INPUT,
    RT_BUFFER_ALLOCATE_TYPE_OUTPUT, END_OF_RT_BUFFER_ALLOCATE_TYPE
  }} rt_buffer_allocate_type_t;

  typedef struct {{
    rt_list_t shape;
    nn_data_type_t type : 4; ///< Type of param values
    unsigned int fp_pos : 4;
    float coefficient; ///< Coefficient value for convert int to float.
    void *data;
  }} rt_variable_t;

  typedef struct {{
    int num_of_inputs;
    rt_variable_t **inputs;

    int num_of_outputs;
    rt_variable_t **outputs;

    void *local_context;
  }} rt_function_t;

  {FUNCTION_DEFINES}

#ifdef __cplusplus
}}
#endif /* __cplusplus */
#endif // H_FUNCTIONS_H__
