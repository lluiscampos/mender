// Copyright 2023 Northern.tech AS
//
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.

#ifndef MENDER_COMMON_LMDB_HPP
#define MENDER_COMMON_LMDB_HPP

#include <common/error.hpp>
#include <common/expected.hpp>
#include <common/key_value_database.hpp>

#include <iostream>
#include <cstdio>

namespace mender {
namespace common {
namespace key_value_database {

namespace error = mender::common::error;
namespace expected = mender::common::expected;

class KeyValueDatabaseStub : public KeyValueDatabase {
public:
	KeyValueDatabaseStub() {};
	~KeyValueDatabaseStub() {};

	error::Error Open(const string &path) {
		return error::NoError;
	};
	void Close() {};

	expected::ExpectedBytes Read(const string &key) override {
		return vector<uint8_t> {};
	};
	error::Error Write(const string &key, const vector<uint8_t> &value) override {
		return error::NoError;
	};
	error::Error Remove(const string &key) override {
		return error::NoError;
	};
	error::Error WriteTransaction(function<error::Error(Transaction &)> txnFunc) override {
		return error::NoError;
	};
	error::Error ReadTransaction(function<error::Error(Transaction &)> txnFunc) override {
		return error::NoError;
	};
};

} // namespace key_value_database
} // namespace common
} // namespace mender

#endif // MENDER_COMMON_LMDB_HPP
