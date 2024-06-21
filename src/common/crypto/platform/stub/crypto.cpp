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

#include <common/crypto.hpp>

#include <cstdint>
#include <string>
#include <vector>
#include <memory>

#include <common/io.hpp>
#include <common/error.hpp>
#include <common/expected.hpp>
#include <common/common.hpp>

#include <artifact/sha/sha.hpp>


namespace mender {
namespace common {
namespace crypto {


using namespace std;

namespace error = mender::common::error;
namespace io = mender::common::io;

ExpectedPrivateKey PrivateKey::Load(const Args &args) {
	return PrivateKey {};
}

ExpectedPrivateKey PrivateKey::Generate(const unsigned int bits, const unsigned int exponent) {
	return PrivateKey {};
}

expected::ExpectedString EncodeBase64(vector<uint8_t> to_encode) {
	return "noop";
}

expected::ExpectedBytes DecodeBase64(string to_decode) {
	return vector<uint8_t> {};
}


expected::ExpectedString ExtractPublicKey(const Args &args) {
	return "noop";
}

expected::ExpectedString Sign(const Args &args, const vector<uint8_t> &raw_data) {
	return "signature";
}

expected::ExpectedBool VerifySign(
	const string &public_key_path, const mender::sha::SHA &shasum, const string &signature) {
	return true;
}

error::Error PrivateKey::SaveToPEM(const string &private_key_path) {
	return error::NoError;
}

} // namespace crypto
} // namespace common
} // namespace mender
