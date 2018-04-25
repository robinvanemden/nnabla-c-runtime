# Copyright (c) 2017 Sony Corporation. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import json
import hashlib


def generate(filename, info):
    m = hashlib.md5()
    m.update(json.dumps(info).encode('utf-8'))
    defines = []
    enums = []
    for cn, cat in info.items():
        for fn, func in cat.items():
            enums.append(
                '  NN_FUNCTION_{} = {},    ///< {}'.format(func['snake_name'].upper(), func['id'], fn))

            defines.append('/// @brief {} function.'.format(fn))
            defines.append('/// @{')
            defines.append('typedef struct {')
            defines.append(
                '  nn_function_type_t type; ///< Common: type of function.')
            defines.append(
                '  nn_function_implement_t impl; ///< Common: function implementation.')
            defines.append(
                '  nn_list_t inputs;        ///< Common: List of input variables.')
            defines.append(
                '  nn_list_t outputs;       ///< Common: List of output variables.')
            if 'arguments' in func and len(func['arguments']) > 0:
                defines.append('  // End of common part.')
                for an, arg in func['arguments'].items():
                    if arg['type'] == 'bool':
                        defines.append('  uint8_t {};'.format(an))
                    elif arg['type'] == 'double' or arg['type'] == 'float':
                        defines.append('  float {};'.format(an))
                    elif arg['type'] == 'int64':
                        defines.append('  int32_t {};'.format(an))
                    elif arg['type'] == 'repeated int64' or arg['type'] == 'Shape':
                        defines.append(
                            '  nn_list_t {};  ///< Original type is [{}]'.format(an, arg['type']))
                    elif arg['type'] == 'string':
                        defines.append(
                            '  uint32_t {};  ///< Original type is [{}]'.format(an, arg['type']))
            defines.append('}} nn_function_{}_t;'.format(
                func['snake_name']))
            defines.append('')
            defines.append('/// @}')
            defines.append('')

    from mako.template import Template
    from mako import exceptions
    try:
        tmpl = Template(filename=filename)
        output = tmpl.render(BINARY_VERSION=m.hexdigest(),
                         FUNCTION_ENUMS='\n'.join(enums),
                         FUNCTION_DEFINES='\n'.join(defines))
        return output
    except:
        print(exceptions.text_error_template().render())
    return None
