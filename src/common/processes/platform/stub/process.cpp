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

#include <common/processes.hpp>

#include <string>
#include <string_view>

#include <common/events_io.hpp>
#include <common/io.hpp>
#include <common/log.hpp>
#include <common/path.hpp>

using namespace std;

namespace mender {
namespace common {
namespace processes {

namespace io = mender::common::io;
namespace log = mender::common::log;
namespace path = mender::common::path;


Process::Process(const vector<string> &args) { /*:
	 args_ {args},
	 max_termination_time_ {MAX_TERMINATION_TIME} {
	 async_wait_data_ = make_shared<AsyncWaitData>();*/
}

Process::~Process() {
}

error::Error Process::Start(OutputCallback stdout_callback, OutputCallback stderr_callback) {
	return error::NoError;
}

error::Error Process::Run() {
	return error::NoError;
}



error::Error Process::Wait() {
	return error::NoError;
}

error::Error Process::Wait(chrono::nanoseconds timeout) {
	return error::NoError;
}

error::Error Process::AsyncWait(events::EventLoop &loop, AsyncWaitHandler handler) {
	return error::NoError;
}

error::Error Process::AsyncWait(
	events::EventLoop &loop, AsyncWaitHandler handler, chrono::nanoseconds timeout) {
	return error::NoError;
}

void Process::Cancel() {
}

void Process::DoCancel() {
}

void Process::SetupAsyncWait() {
}

void Process::AsyncWaitInternalHandler(shared_ptr<AsyncWaitData> async_wait_data) {
}



ExpectedLineData Process::GenerateLineData(chrono::nanoseconds timeout) {
	return vector<string> {};
}

// io::ExpectedAsyncReaderPtr Process::GetProcessReader(events::EventLoop &loop, int &pipe_ref) {
// 	// if (proc_) {
// 	// 	return expected::unexpected(
// 	// 		MakeError(ProcessAlreadyStartedError, "Cannot get process output"));
// 	// }

// 	// if (pipe_ref >= 0) {
// 	// 	close(pipe_ref);
// 	// 	pipe_ref = -1;
// 	// }

// 	// int fds[2];
// 	// int ret = pipe(fds);
// 	// if (ret < 0) {
// 	// 	int err = errno;
// 	// 	return expected::unexpected(error::Error(
// 	// 		generic_category().default_error_condition(err),
// 	// 		"Could not get process stdout reader"));
// 	// }

// 	// pipe_ref = fds[1];

// 	return make_shared<events::io::AsyncFileDescriptorReader>(loop, fds[0]);
// }

int Process::EnsureTerminated() {
	return 0;
}

void Process::Terminate() {
}

void Process::Kill() {
}

// void ProcessReaderFunctor::operator()(const char *bytes, size_t n) {
// 	if (callback_) {
// 		callback_(bytes, n);
// 	}

// 	if (fd_ < 0) {
// 		return;
// 	}

// 	size_t written = 0;
// 	while (written < n) {
// 		auto ret = write(fd_, bytes, n);
// 		if (ret < 0) {
// 			int err = errno;
// 			log::Error(
// 				string {"Error while writing process output to main thread: "} + strerror(err));
// 			fd_ = -1;
// 			return;
// 		}

// 		written += ret;
// 	}
// }

} // namespace processes
} // namespace common
} // namespace mender
