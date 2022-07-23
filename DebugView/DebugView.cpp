#include "DebugView.h"

#include <windows.h>
#include <locale.h>
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
	const size_t delimiter_size = (wDelimiter.length() + 1) * 2;
	char* delimiter = new char[delimiter_size];
#if _MSC_VER > 1200
	size_t convertedChars = 0;
	wcstombs_s(&convertedChars, delimiter, delimiter_size, wDelimiter.c_str(), _TRUNCATE);
#else
	wcstombs(delimiter, wDelimiter.c_str(), delimiter_size);
#endif

	MOONG::DebugView::setDelimiter(delimiter);

	delete[] delimiter;
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

	StringCchVPrintfA(build_string, MOONG::DebugView::max_buf_size_, format.c_str(), arg_ptr);

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

	StringCchVPrintfW(build_string, MOONG::DebugView::max_buf_size_, format.c_str(), arg_ptr);

	size_t convert_string_size = (wcslen(build_string) + 1) * 2;
	char* convert_string = new char[convert_string_size];
	setlocale(LC_ALL, "korean"); // 이 코드가 있어야 wcstombs_s에서 한글이 정상적으로 변환이 된다.
#if _MSC_VER > 1200
	size_t convertedChars = 0;
	wcstombs_s(&convertedChars, convert_string, convert_string_size, build_string, _TRUNCATE);
#else
	wcstombs(convert_string, build_string, convert_string_size);
#endif

	std::string debug_string(MOONG::DebugView::Get_delimiter());
	debug_string += " ";
	debug_string += token;
	debug_string += " ";
	debug_string += convert_string;

	delete[] convert_string;

	OutputDebugStringA(debug_string.c_str());
}