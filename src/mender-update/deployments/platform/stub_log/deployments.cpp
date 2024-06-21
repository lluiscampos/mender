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

#include <mender-update/deployments.hpp>

#include <algorithm>
#include <string>

#include <common/error.hpp>
#include <common/io.hpp>
#include <common/json.hpp>
#include <common/log.hpp>
#include <common/path.hpp>

namespace mender {
namespace update {
namespace deployments {

using namespace std;

namespace error = mender::common::error;
namespace path = mender::common::path;

error::Error DeploymentLog::PrepareLogDirectory() {
	return error::NoError;
}

error::Error DeploymentLog::BeginLogging() {
	return error::NoError;
}

error::Error DeploymentLog::FinishLogging() {
	return error::NoError;
}

string DeploymentLog::LogFileName() {
	return "deployments.0000." + id_ + ".log";
}

string DeploymentLog::LogFilePath() {
	return path::Join(data_store_dir_, LogFileName());
}

} // namespace deployments
} // namespace update
} // namespace mender
