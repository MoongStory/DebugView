#include "DebugView.h"

#include <windows.h>
#include <strsafe.h>

MOONG::DEBUG_VIEW::DebugView::DebugView(const std::string delimiter, const unsigned int log_level)
{
	this->Init(delimiter, log_level);
}

MOONG::DEBUG_VIEW::DebugView::DebugView(const std::wstring wDelimiter, const unsigned int log_level)
{
	size_t delimiter_size = (wcslen(wDelimiter.c_str()) + 1) * 2;
	char *delimiter = new char[delimiter_size];
	size_t convertedChars = 0;
	wcstombs_s(&convertedChars, delimiter, delimiter_size, wDelimiter.c_str(), _TRUNCATE);

	this->Init(delimiter, log_level);

	delete[] delimiter;
}



void MOONG::DEBUG_VIEW::DebugView::Trace(const char * const format, ...) const
{
	if(this->getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_TRACE)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::TRACE_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DEBUG_VIEW::DebugView::Trace(const wchar_t * const format, ...) const
{
	if(this->getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_TRACE)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::TRACE_, format, arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DEBUG_VIEW::DebugView::Debug(const char * const format, ...) const
{
	if(this->getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_DEBUG)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::DEBUG_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DEBUG_VIEW::DebugView::Debug(const wchar_t * const format, ...) const
{
	if(this->getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_DEBUG)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::DEBUG_, format, arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DEBUG_VIEW::DebugView::Info(const char * const format, ...) const
{
	if(this->getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_INFO)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::INFO_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DEBUG_VIEW::DebugView::Info(const wchar_t * const format, ...) const
{
	if(this->getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_INFO)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::INFO_, format, arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DEBUG_VIEW::DebugView::Warn(const char * const format, ...) const
{
	if(this->getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_WARN)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::WARN_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DEBUG_VIEW::DebugView::Warn(const wchar_t * const format, ...) const
{
	if(this->getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_WARN)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::WARN_, format, arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DEBUG_VIEW::DebugView::Error(const char * const format, ...) const
{
	if(this->getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_ERROR)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::ERROR_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DEBUG_VIEW::DebugView::Error(const wchar_t * const format, ...) const
{
	if(this->getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_ERROR)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::ERROR_, format, arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DEBUG_VIEW::DebugView::Fatal(const char * const format, ...) const
{
	if(this->getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_FATAL)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::FATAL_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DEBUG_VIEW::DebugView::Fatal(const wchar_t * const format, ...) const
{
	if(this->getLogLevel() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_FATAL)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::FATAL_, format, arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DEBUG_VIEW::DebugView::Init(const std::string delimiter, const unsigned int log_level)
{
	if (log_level < MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_TRACE || log_level > MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_FATAL)
	{
		this->Fatal("Log Level 설정값이 잘못되어 Log Level이 Error Level로 초기화 됩니다.");
		this->setLogLevel(MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_ERROR);
	}
	else
	{
		this->setLogLevel(log_level);
	}

	if (delimiter.empty())
	{
		this->setDelimiter("[MOONG_DEBUG_DEFAULT]");
	}
	else
	{
		this->setDelimiter(delimiter);
	}
}

void MOONG::DEBUG_VIEW::DebugView::Print(const char* const token, const char* const format, va_list arg_ptr) const
{
	char build_string[kMaxBufSize] = { 0 };

	StringCchVPrintfA(build_string, kMaxBufSize, format, arg_ptr);

	std::string debug_string(this->Get_delimiter());
	debug_string += " ";
	debug_string += token;
	debug_string += " ";
	debug_string += build_string;

	OutputDebugStringA(debug_string.c_str());
}

void MOONG::DEBUG_VIEW::DebugView::Print(const char* const token, const wchar_t* const format, va_list arg_ptr) const
{
	wchar_t build_string[kMaxBufSize] = { 0 };

	StringCchVPrintfW(build_string, kMaxBufSize, format, arg_ptr);

	const size_t convert_string_size = (wcslen(build_string) + 1) * 2;
	char* convert_string = new char[convert_string_size];
	size_t convertedChars = 0;
	wcstombs_s(&convertedChars, convert_string, convert_string_size, build_string, _TRUNCATE);

	std::string debug_string(this->Get_delimiter());
	debug_string += " ";
	debug_string += token;
	debug_string += " ";
	debug_string += convert_string;

	delete[] convert_string;

	OutputDebugStringA(debug_string.c_str());
}

const std::string MOONG::DEBUG_VIEW::DebugView::Get_delimiter() const
{
	return this->delimiter_;
}

void MOONG::DEBUG_VIEW::DebugView::setDelimiter(const std::string delimiter)
{
	this->delimiter_ = delimiter;
}

unsigned int MOONG::DEBUG_VIEW::DebugView::getLogLevel() const
{
	return this->log_level_;
}

void MOONG::DEBUG_VIEW::DebugView::setLogLevel(unsigned int log_level)
{
	this->log_level_ = log_level;
}
