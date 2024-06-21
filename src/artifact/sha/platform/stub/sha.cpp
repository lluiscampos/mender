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

#include <cstdint>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>
#include <sstream>
#include <algorithm>

#include <artifact/sha/sha.hpp>

#include <common/common.hpp>
#include <common/io.hpp>


namespace mender {
namespace sha {

namespace log = mender::common::log;
namespace io = mender::common::io;


Reader::Reader(io::Reader &reader, const std::string &expected_sha) :
	wrapped_reader_ {reader} {
}

expected::ExpectedSize Reader::Read(
	vector<uint8_t>::iterator start, vector<uint8_t>::iterator end) {
	return 0;
}

ExpectedSHA Reader::ShaSum() {
	vector<uint8_t> hash = {1, 2, 3, 4, 5, 6, 7};
	return SHA(hash, 8);
}

} // namespace sha
} // namespace mender
