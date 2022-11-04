#include "DebugView.h"

// https://github.com/MoongStory/ConvertDataType
#include "../../ConvertDataType/ConvertDataType/ConvertDataType.h"

// https://github.com/MoongStory/Exception
#include "../../Exception/Exception/Exception.h"

#include <windows.h>
#include <strsafe.h>

const std::string MOONG::DebugView::TRACE_ = "[TRACE]";
const std::string MOONG::DebugView::DEBUG_ = "[DEBUG]";
const std::string MOONG::DebugView::INFO_ = "[INFO]";
const std::string MOONG::DebugView::WARN_ = "[WARN]";
const std::string MOONG::DebugView::ERROR_ = "[ERROR]";
const std::string MOONG::DebugView::FATAL_ = "[FATAL]";

const unsigned int MOONG::DebugView::max_buf_size_ = 1024;
std::string MOONG::DebugView::delimiter_ = "[MOONG_DEBUG]";
unsigned int MOONG::DebugView::log_level_ = MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_TRACE;

void MOONG::DebugView::Trace(const std::string format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_TRACE)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print(MOONG::DebugView::TRACE_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DebugView::Trace(const std::wstring format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_TRACE)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print(MOONG::DebugView::TRACE_, format, arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DebugView::Debug(const std::string format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_DEBUG)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print(MOONG::DebugView::DEBUG_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DebugView::Debug(const std::wstring format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_DEBUG)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print(MOONG::DebugView::DEBUG_, format, arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DebugView::Info(const std::string format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_INFO)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print(MOONG::DebugView::INFO_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DebugView::Info(const std::wstring format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_INFO)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print(MOONG::DebugView::INFO_, format, arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DebugView::Warn(const std::string format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_WARN)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print(MOONG::DebugView::WARN_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DebugView::Warn(const std::wstring format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_WARN)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print(MOONG::DebugView::WARN_, format, arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DebugView::Error(const std::string format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_ERROR)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print(MOONG::DebugView::ERROR_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DebugView::Error(const std::wstring format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_ERROR)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print(MOONG::DebugView::ERROR_, format, arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DebugView::Fatal(const std::string format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_FATAL)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print(MOONG::DebugView::FATAL_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DebugView::Fatal(const std::wstring format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_FATAL)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print(MOONG::DebugView::FATAL_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

const std::string MOONG::DebugView::Get_delimiter()
{
	return MOONG::DebugView::delimiter_;
}

void MOONG::DebugView::setDelimiter(const std::string delimiter)
{
	if (delimiter.empty())
	{
		MOONG::DebugView::delimiter_ = "[MOONG_DEBUG]";
	}
	else
	{
		MOONG::DebugView::delimiter_ = delimiter;
	}
}

void MOONG::DebugView::setDelimiter(const std::wstring wDelimiter)
{
	MOONG::DebugView::setDelimiter(MOONG::ConvertDataType::wstring_to_string(wDelimiter));
}

unsigned int MOONG::DebugView::getLogLevel()
{
	return MOONG::DebugView::log_level_;
}

void MOONG::DebugView::setLogLevel(unsigned int log_level)
{
	MOONG::DebugView::log_level_ = log_level;

	if (log_level < MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_TRACE || log_level > MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_FATAL)
	{
		MOONG::DebugView::Fatal("Log Level 설정값이 잘못되어 Log Level이 Error Level로 초기화 됩니다.");
		MOONG::DebugView::log_level_ = MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_ERROR;
	}
	else
	{
		MOONG::DebugView::log_level_ = log_level;
	}
}

const unsigned int MOONG::DebugView::getMaxBufSize()
{
	return MOONG::DebugView::max_buf_size_;
}





void MOONG::DebugView::Print(const std::string token, const std::string format, va_list arg_ptr)
{
	char build_string[MOONG::DebugView::max_buf_size_] = { 0 };

	if (FAILED(StringCchVPrintfA(build_string, MOONG::DebugView::max_buf_size_, format.c_str(), arg_ptr)))
	{
		throw MOONG::ExceptionFunctionCallFailed<DWORD>("StringCchVPrintfA");
	}

	std::string debug_string(MOONG::DebugView::Get_delimiter());
	debug_string += " ";
	debug_string += token;
	debug_string += " ";
	debug_string += build_string;

	OutputDebugStringA(debug_string.c_str());
}

void MOONG::DebugView::Print(const std::string token, const std::wstring format, va_list arg_ptr)
{
	wchar_t build_string[MOONG::DebugView::max_buf_size_] = { 0 };

	if (FAILED(StringCchVPrintfW(build_string, MOONG::DebugView::max_buf_size_, format.c_str(), arg_ptr)))
	{
		throw MOONG::ExceptionFunctionCallFailed<DWORD>("StringCchVPrintfW");
	}

	std::string debug_string(MOONG::DebugView::Get_delimiter());
	debug_string += " ";
	debug_string += token;
	debug_string += " ";
	debug_string += MOONG::ConvertDataType::wstring_to_string(build_string);

	OutputDebugStringA(debug_string.c_str());
}