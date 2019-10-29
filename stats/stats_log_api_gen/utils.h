/*
 * Copyright (C) 2019, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Collation.h"

#include <map>
#include <set>
#include <vector>

#include <stdio.h>
#include <string.h>

namespace android {
namespace stats_log_api_gen {

using namespace std;

const string DEFAULT_MODULE_NAME = "DEFAULT";
const string DEFAULT_CPP_NAMESPACE = "android,util";
const string DEFAULT_CPP_HEADER_IMPORT = "statslog.h";
const string DEFAULT_JAVA_PACKAGE = "android.util";
const string DEFAULT_JAVA_CLASS = "StatsLogInternal";

const int JAVA_MODULE_REQUIRES_FLOAT = 0x01;
const int JAVA_MODULE_REQUIRES_ATTRIBUTION = 0x02;

string make_constant_name(const string& str);

const char* cpp_type_name(java_type_t type);

const char* java_type_name(java_type_t type);

bool atom_needed_for_module(const AtomDecl& atomDecl, const string& moduleName);

bool signature_needed_for_module(const set<string>& modules, const string& moduleName);

void build_non_chained_decl_map(const Atoms& atoms,
                                std::map<int, set<AtomDecl>::const_iterator>* decl_map);

// Common Java helpers.
void write_java_atom_codes(FILE* out, const Atoms& atoms, const string& moduleName);

void write_java_enum_values(FILE* out, const Atoms& atoms, const string& moduleName);

void write_java_usage(FILE* out, const string& method_name, const string& atom_code_name,
        const AtomDecl& atom);

int write_java_non_chained_methods(FILE* out, const map<vector<java_type_t>,
        set<string>>& signatures_to_modules,
        const string& moduleName
);

int write_java_work_source_methods(
        FILE* out,
        const map<vector<java_type_t>, set<string>>& signatures_to_modules,
        const string& moduleName
);

}  // namespace stats_log_api_gen
}  // namespace android
