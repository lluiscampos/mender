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

#include <common/http.hpp>

#include <algorithm>

#include <common/common.hpp>
#include <common/crypto.hpp>

namespace mender {
namespace common {
namespace http {

namespace common = mender::common;
namespace crypto = mender::common::crypto;


class StubAsyncReader : virtual public io::AsyncReader {
public:
	StubAsyncReader() {
	}
	~StubAsyncReader() {
	}

	error::Error AsyncRead(
		vector<uint8_t>::iterator start,
		vector<uint8_t>::iterator end,
		io::AsyncIoHandler handler) override {
		return error::NoError;
	}

	void Cancel() override {
	}
};

class StubAsyncReadWriter : virtual public io::AsyncReadWriter {
public:
	StubAsyncReadWriter() {
	}

	~StubAsyncReadWriter() {
	}

	error::Error AsyncRead(
		vector<uint8_t>::iterator start,
		vector<uint8_t>::iterator end,
		io::AsyncIoHandler handler) override {
		return error::NoError;
	}

	error::Error AsyncWrite(
		vector<uint8_t>::const_iterator start,
		vector<uint8_t>::const_iterator end,
		io::AsyncIoHandler handler) override {
		return error::NoError;
	}

	void Cancel() override {
	}
};

Client::Client(
	const ClientConfig &client, events::EventLoop &event_loop, const string &logger_name) :
	event_loop_ {event_loop},
	logger_name_ {logger_name},
	client_config_ {client},
	http_proxy_ {client.http_proxy},
	https_proxy_ {client.https_proxy},
	no_proxy_ {client.no_proxy} {
}

Client::~Client() {
}

error::Error Client::AsyncCall(
	OutgoingRequestPtr req, ResponseHandler header_handler, ResponseHandler body_handler) {
	return error::NoError;
}

io::ExpectedAsyncReaderPtr Client::MakeBodyAsyncReader(IncomingResponsePtr resp) {
	return make_shared<StubAsyncReader>();
}

io::ExpectedAsyncReadWriterPtr Client::SwitchProtocol(IncomingResponsePtr req) {
	return make_shared<StubAsyncReadWriter>();
}

void Client::Cancel() {
}



} // namespace http
} // namespace common
} // namespace mender
