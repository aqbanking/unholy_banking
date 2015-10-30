/*
 * NodeJS wrapper-plugin for Aqbanking
 * Copyright (C) 2015  Lukas Matt <lukas@zauberstuhl.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <node.h>
#include <v8.h>

#include <iostream>

#include "ab_helpers.h"

using namespace std;
using namespace v8;

void AB_transactions(const v8::FunctionCallbackInfo<Value>& args) {
  UB::Helper helper;
  int rv = helper.close();

  cout << "close() return value: " << rv << endl;
}

void Init(Handle<Object> exports) {
  Isolate* isolate = Isolate::GetCurrent();
  //invalid conversion from
  //‘int (*)(const v8::FunctionCallbackInfo<v8::Value>&)’ to
  //‘v8::FunctionCallback {aka void (*)(const v8::FunctionCallbackInfo<v8::Value>&)}’ [-fpermissive]
  exports->Set(String::NewFromUtf8(isolate, "getTransactions"),
      FunctionTemplate::New(isolate, AB_transactions)->GetFunction());
}

NODE_MODULE(unholy_banking, Init)
