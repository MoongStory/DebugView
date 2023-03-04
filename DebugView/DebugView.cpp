#include "DebugView.h"

#include "../../ConvertDataType/ConvertDataType/ConvertDataType.h"
#include "../../StringTool/StringTool/StringTool.h"

#include <windows.h>
#include <strsafe.h>

const std::string MOONG::DebugView::TRACE_ = "[TRACE]";
const std::string MOONG::DebugView::DEBUG_ = "[DEBUG]";
const std::string MOONG::DebugView::INFO_ = "[INFO]";
const std::string MOONG::DebugView::WARN_ = "[WARN]";
const std::string MOONG::DebugView::ERROR_ = "[ERROR]";
const std::string MOONG::DebugView::FATAL_ = "[FATAL]";

std::string MOONG::DebugView::delimiter_ = "[MOONG_DEBUG]";
unsigned int MOONG::DebugView::log_level_ = MOONG::DEBUG_VIEW::LOG_LEVEL::TRACE_;

void MOONG::DebugView::Trace(const std::string format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::TRACE_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print_(MOONG::DebugView::TRACE_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DebugView::Trace(const std::wstring format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::TRACE_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print_(MOONG::DebugView::TRACE_, MOONG::ConvertDataType::wstring_to_string(format), arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DebugView::Debug(const std::string format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::DEBUG_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print_(MOONG::DebugView::DEBUG_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DebugView::Debug(const std::wstring format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::DEBUG_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print_(MOONG::DebugView::DEBUG_, MOONG::ConvertDataType::wstring_to_string(format), arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DebugView::Info(const std::string format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::INFO_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print_(MOONG::DebugView::INFO_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DebugView::Info(const std::wstring format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::INFO_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print_(MOONG::DebugView::INFO_, MOONG::ConvertDataType::wstring_to_string(format), arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DebugView::Warn(const std::string format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::WARN_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print_(MOONG::DebugView::WARN_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DebugView::Warn(const std::wstring format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::WARN_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print_(MOONG::DebugView::WARN_, MOONG::ConvertDataType::wstring_to_string(format), arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DebugView::Error(const std::string format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::ERROR_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print_(MOONG::DebugView::ERROR_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DebugView::Error(const std::wstring format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::ERROR_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print_(MOONG::DebugView::ERROR_, MOONG::ConvertDataType::wstring_to_string(format), arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DebugView::Fatal(const std::string format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::FATAL_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print_(MOONG::DebugView::FATAL_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DebugView::Fatal(const std::wstring format, ...)
{
	if(MOONG::DebugView::getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::FATAL_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::Print_(MOONG::DebugView::FATAL_, MOONG::ConvertDataType::wstring_to_string(format), arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DebugView::Print(const std::string format, ...)
{
	va_list arg_ptr;

	va_start(arg_ptr, format);
	MOONG::DebugView::Print_("", format, arg_ptr);
	va_end(arg_ptr);
}

void MOONG::DebugView::Print(const std::wstring format, ...)
{
	va_list arg_ptr;

	va_start(arg_ptr, format);
	MOONG::DebugView::Print_("", MOONG::ConvertDataType::wstring_to_string(format), arg_ptr);
	va_end(arg_ptr);
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
	try
	{
		MOONG::DebugView::setDelimiter(MOONG::ConvertDataType::wstring_to_string(wDelimiter));
	}
	catch (const std::exception& exception)
	{
		throw exception;
	}
}

unsigned int MOONG::DebugView::getLogLevel()
{
	return MOONG::DebugView::log_level_;
}

void MOONG::DebugView::setLogLevel(unsigned int log_level)
{
	MOONG::DebugView::log_level_ = log_level;

	if (log_level < MOONG::DEBUG_VIEW::LOG_LEVEL::TRACE_ || log_level > MOONG::DEBUG_VIEW::LOG_LEVEL::FATAL_)
	{
		MOONG::DebugView::Fatal("Log Level 설정값이 잘못되어 Log Level이 Error Level로 초기화 됩니다.");
		MOONG::DebugView::log_level_ = MOONG::DEBUG_VIEW::LOG_LEVEL::ERROR_;
	}
	else
	{
		MOONG::DebugView::log_level_ = log_level;
	}
}





void MOONG::DebugView::Print_(const std::string token, const std::string format, va_list arg_ptr)
{
	std::string build_string = MOONG::StringTool::format(format, arg_ptr);

	std::string debug_string(MOONG::DebugView::Get_delimiter());
	debug_string += " ";
	if (token.length() > 0)
	{
		debug_string += token;
		debug_string += " ";
	}
	debug_string += build_string;

	OutputDebugStringA(debug_string.c_str());
}
