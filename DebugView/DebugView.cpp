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
unsigned int MOONG::DebugView::log_level_ = MOONG::DEBUG_VIEW::LEVEL::TRACE_;

void MOONG::DebugView::trace(const std::string format, ...)
{
	if(MOONG::DebugView::get_log_level() <= MOONG::DEBUG_VIEW::LEVEL::TRACE_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::print_(MOONG::DebugView::TRACE_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DebugView::trace(const std::wstring format, ...)
{
	if(MOONG::DebugView::get_log_level() <= MOONG::DEBUG_VIEW::LEVEL::TRACE_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::print_(MOONG::DebugView::TRACE_, MOONG::ConvertDataType::wstring_to_string(format), arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DebugView::debug(const std::string format, ...)
{
	if(MOONG::DebugView::get_log_level() <= MOONG::DEBUG_VIEW::LEVEL::DEBUG_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::print_(MOONG::DebugView::DEBUG_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DebugView::debug(const std::wstring format, ...)
{
	if(MOONG::DebugView::get_log_level() <= MOONG::DEBUG_VIEW::LEVEL::DEBUG_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::print_(MOONG::DebugView::DEBUG_, MOONG::ConvertDataType::wstring_to_string(format), arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DebugView::info(const std::string format, ...)
{
	if(MOONG::DebugView::get_log_level() <= MOONG::DEBUG_VIEW::LEVEL::INFO_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::print_(MOONG::DebugView::INFO_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DebugView::info(const std::wstring format, ...)
{
	if(MOONG::DebugView::get_log_level() <= MOONG::DEBUG_VIEW::LEVEL::INFO_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::print_(MOONG::DebugView::INFO_, MOONG::ConvertDataType::wstring_to_string(format), arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DebugView::warn(const std::string format, ...)
{
	if(MOONG::DebugView::get_log_level() <= MOONG::DEBUG_VIEW::LEVEL::WARN_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::print_(MOONG::DebugView::WARN_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DebugView::warn(const std::wstring format, ...)
{
	if(MOONG::DebugView::get_log_level() <= MOONG::DEBUG_VIEW::LEVEL::WARN_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::print_(MOONG::DebugView::WARN_, MOONG::ConvertDataType::wstring_to_string(format), arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DebugView::error(const std::string format, ...)
{
	if(MOONG::DebugView::get_log_level() <= MOONG::DEBUG_VIEW::LEVEL::ERROR_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::print_(MOONG::DebugView::ERROR_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DebugView::error(const std::wstring format, ...)
{
	if(MOONG::DebugView::get_log_level() <= MOONG::DEBUG_VIEW::LEVEL::ERROR_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::print_(MOONG::DebugView::ERROR_, MOONG::ConvertDataType::wstring_to_string(format), arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DebugView::fatal(const std::string format, ...)
{
	if(MOONG::DebugView::get_log_level() <= MOONG::DEBUG_VIEW::LEVEL::FATAL_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::print_(MOONG::DebugView::FATAL_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DebugView::fatal(const std::wstring format, ...)
{
	if(MOONG::DebugView::get_log_level() <= MOONG::DEBUG_VIEW::LEVEL::FATAL_)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		MOONG::DebugView::print_(MOONG::DebugView::FATAL_, MOONG::ConvertDataType::wstring_to_string(format), arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DebugView::print(const std::string format, ...)
{
	va_list arg_ptr;

	va_start(arg_ptr, format);
	MOONG::DebugView::print_("", format, arg_ptr);
	va_end(arg_ptr);
}

void MOONG::DebugView::print(const std::wstring format, ...)
{
	va_list arg_ptr;

	va_start(arg_ptr, format);
	MOONG::DebugView::print_("", MOONG::ConvertDataType::wstring_to_string(format), arg_ptr);
	va_end(arg_ptr);
}



const std::string MOONG::DebugView::get_delimiter()
{
	return MOONG::DebugView::delimiter_;
}

void MOONG::DebugView::set_delimiter(const std::string delimiter)
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

void MOONG::DebugView::set_delimiter(const std::wstring wDelimiter)
{
	try
	{
		MOONG::DebugView::set_delimiter(MOONG::ConvertDataType::wstring_to_string(wDelimiter));
	}
	catch (const std::exception& exception)
	{
		throw exception;
	}
}

unsigned int MOONG::DebugView::get_log_level()
{
	return MOONG::DebugView::log_level_;
}

void MOONG::DebugView::set_log_level(unsigned int log_level)
{
	MOONG::DebugView::log_level_ = log_level;

	if (log_level < MOONG::DEBUG_VIEW::LEVEL::TRACE_ || log_level > MOONG::DEBUG_VIEW::LEVEL::FATAL_)
	{
		MOONG::DebugView::fatal("Log Level 설정값이 잘못되어 Log Level이 Error Level로 초기화 됩니다.");
		MOONG::DebugView::log_level_ = MOONG::DEBUG_VIEW::LEVEL::ERROR_;
	}
	else
	{
		MOONG::DebugView::log_level_ = log_level;
	}
}





void MOONG::DebugView::print_(const std::string token, const std::string format, va_list arg_ptr)
{
	std::string build_string = MOONG::StringTool::format(format, arg_ptr);

	std::string debug_string(MOONG::DebugView::get_delimiter());
	debug_string += " ";
	if (token.length() > 0)
	{
		debug_string += token;
		debug_string += " ";
	}
	debug_string += build_string;

	OutputDebugStringA(debug_string.c_str());
}
