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

#include <common/error.hpp>
#include <common/events.hpp>

namespace mender {
namespace update {
namespace update_module {
namespace v3 {

namespace error = mender::common::error;
namespace events = mender::common::events;


UpdateModule::StateRunner::StateRunner(
	events::EventLoop &loop,
	State state,
	const string &module_path,
	const string &module_work_path) :
	loop(loop),
	module_work_path(module_work_path),
	proc({module_path, StateToString(state), module_work_path}) {
}

error::Error UpdateModule::StateRunner::AsyncCallState(
	State state, bool procOut, chrono::seconds timeout_seconds, HandlerFunction handler) {
	return error::NoError;
}

void UpdateModule::StateRunner::ProcessFinishedHandler(State state, error::Error err) {
}

error::Error UpdateModule::AsyncSystemReboot(
	events::EventLoop &event_loop, StateFinishedHandler handler) {
	return error::NoError;
}

} // namespace v3
} // namespace update_module
} // namespace update
} // namespace mender
