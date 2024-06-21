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

#include <mender-update/update_module/v3/update_module.hpp>

#include <client_shared/conf.hpp>
#include <common/events_io.hpp>
#include <common/io.hpp>
#include <common/log.hpp>
#include <common/path.hpp>
#include <mender-update/context.hpp>

namespace mender {
namespace update {
namespace update_module {
namespace v3 {

using namespace std;

namespace error = mender::common::error;
namespace events = mender::common::events;
namespace expected = mender::common::expected;
namespace conf = mender::client_shared::conf;
namespace context = mender::update::context;
namespace io = mender::common::io;
namespace log = mender::common::log;
namespace path = mender::common::path;

error::Error UpdateModule::PrepareFileTreeDeviceParts(const string &path) {
	return error::NoError;
}

error::Error UpdateModule::CleanAndPrepareFileTree(
	const string &path, artifact::PayloadHeaderView &payload_meta_data) {
	return error::NoError;
}

error::Error UpdateModule::EnsureRootfsImageFileTree(const string &path) {
	return error::NoError;
}

error::Error UpdateModule::DeleteFileTree(const string &path) {
	return error::NoError;
}

expected::ExpectedStringVector DiscoverUpdateModules(const conf::MenderConfig &config) {
	return vector<string> {};
}

error::Error UpdateModule::PrepareStreamNextPipe() {
	return error::NoError;
}

error::Error UpdateModule::OpenStreamNextPipe(ExpectedWriterHandler open_handler) {
	return error::NoError;
}

error::Error UpdateModule::PrepareAndOpenStreamPipe(
	const string &path, ExpectedWriterHandler open_handler) {
	return error::NoError;
}

error::Error UpdateModule::PrepareDownloadDirectory(const string &path) {
	return error::NoError;
}

error::Error UpdateModule::DeleteStreamsFiles() {
	return error::NoError;
}

AsyncFifoOpener::AsyncFifoOpener(events::EventLoop &loop) :
	event_loop_ {loop} {
}

AsyncFifoOpener::~AsyncFifoOpener() {
}

error::Error AsyncFifoOpener::AsyncOpen(const string &path, ExpectedWriterHandler handler) {
	return error::NoError;
}

void AsyncFifoOpener::Cancel() {
}


} // namespace v3
} // namespace update_module
} // namespace update
} // namespace mender
