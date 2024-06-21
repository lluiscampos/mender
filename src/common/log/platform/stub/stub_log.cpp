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

#include <common/log.hpp>


#include <string>
#include <fstream>
#include <common/error.hpp>
#include <common/expected.hpp>

namespace mender {
namespace common {
namespace log {

namespace error = mender::common::error;
namespace expected = mender::common::expected;

using namespace std;


const LogErrorCategoryClass LogErrorCategory;

const char *LogErrorCategoryClass::name() const noexcept {
	return "LogErrorCategory";
}

string LogErrorCategoryClass::message(int code) const {
	switch (code) {
	case NoError:
		return "Success";
	case InvalidLogLevelError:
		return "Invalid log level given";
	case LogFileError:
		return "Bad log file";
	default:
		return "Unknown";
	}
}

error::Error MakeError(LogErrorCode code, const string &msg) {
	return error::Error(error_condition(code, LogErrorCategory), msg);
}

ExpectedLogLevel StringToLogLevel(const string &level_str) {
	if (level_str == "fatal") {
		return ExpectedLogLevel(LogLevel::Fatal);
	} else if (level_str == "error") {
		return ExpectedLogLevel(LogLevel::Error);
	} else if (level_str == "warning") {
		return ExpectedLogLevel(LogLevel::Warning);
	} else if (level_str == "info") {
		return ExpectedLogLevel(LogLevel::Info);
	} else if (level_str == "debug") {
		return ExpectedLogLevel(LogLevel::Debug);
	} else if (level_str == "trace") {
		return ExpectedLogLevel(LogLevel::Trace);
	} else {
		return ExpectedLogLevel(expected::unexpected(MakeError(
			LogErrorCode::InvalidLogLevelError, "'" + level_str + "' is not a valid log level")));
	}
}

Logger::Logger(const string &name) :
	Logger {name, global_logger_.Level()} {
}

Logger::Logger(const string &name, LogLevel level) {
}

void Logger::Log_(LogLevel level, const string &message) {
}

void Logger::SetLevel(LogLevel level) {
	this->level_ = level;
}

LogLevel Logger::Level() {
	return this->level_;
}

void Logger::AddField(const LogField &field) {
}

Logger Setup() {
#ifdef NDEBUG
	return Logger("Global", LogLevel::Info);
#else
	return Logger("Global", LogLevel::Debug);
#endif
}

Logger global_logger_ = Setup();

void SetLevel(LogLevel level) {
	global_logger_.SetLevel(level);
}

error::Error SetupFileLogging(const string &log_file_path, bool exclusive) {
	return error::NoError;
}

LogLevel Level() {
	return global_logger_.Level();
}

void Log_(LogLevel level, const string message) {
	global_logger_.Log(level, message);
}

void Fatal(const string &message) {
	global_logger_.Log(LogLevel::Fatal, message);
	std::abort();
}
void Error(const string &message) {
	return global_logger_.Log(LogLevel::Error, message);
}
void Warning(const string &message) {
	return global_logger_.Log(LogLevel::Warning, message);
}
void Info(const string &message) {
	return global_logger_.Log(LogLevel::Info, message);
}
void Debug(const string &message) {
	return global_logger_.Log(LogLevel::Debug, message);
}
void Trace(const string &message) {
	return global_logger_.Log(LogLevel::Trace, message);
}


} // namespace log
} // namespace common
} // namespace mender
