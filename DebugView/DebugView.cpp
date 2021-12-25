#include "DebugView.h"

#include <windows.h>
#include <strsafe.h>

MOONG::DEBUG_VIEW::DebugView::DebugView(const CStringA delimiter, const unsigned int log_level) :
	log_level_(MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_ERROR)
{
	if(log_level < MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_TRACE || log_level > MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_FATAL)
	{
		this->Fatal("Log Level 설정값이 잘못되어 Log Level이 Error Level로 초기화 됩니다.");
		this->Set_log_level(MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_ERROR);
	}
	else
	{
		this->Set_log_level(log_level);
	}

	if(delimiter.IsEmpty())
	{
		this->Set_delimiter("[MOONG_DEBUG_VIEW]");
	}
	else
	{
		this->Set_delimiter(delimiter);
	}
}



void MOONG::DEBUG_VIEW::DebugView::Trace(const char * const format, ...) const
{
	if(this->Get_log_level() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_TRACE)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::TRACE_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DEBUG_VIEW::DebugView::Trace(const wchar_t * const format, ...) const
{
	if(this->Get_log_level() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_TRACE)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::TRACE_, format, arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DEBUG_VIEW::DebugView::Debug(const char * const format, ...) const
{
	if(this->Get_log_level() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_DEBUG)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::DEBUG_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DEBUG_VIEW::DebugView::Debug(const wchar_t * const format, ...) const
{
	if(this->Get_log_level() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_DEBUG)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::DEBUG_, format, arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DEBUG_VIEW::DebugView::Info(const char * const format, ...) const
{
	if(this->Get_log_level() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_INFO)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::INFO_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DEBUG_VIEW::DebugView::Info(const wchar_t * const format, ...) const
{
	if(this->Get_log_level() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_INFO)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::INFO_, format, arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DEBUG_VIEW::DebugView::Warn(const char * const format, ...) const
{
	if(this->Get_log_level() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_WARN)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::WARN_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DEBUG_VIEW::DebugView::Warn(const wchar_t * const format, ...) const
{
	if(this->Get_log_level() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_WARN)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::WARN_, format, arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DEBUG_VIEW::DebugView::Error(const char * const format, ...) const
{
	if(this->Get_log_level() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_ERROR)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::ERROR_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DEBUG_VIEW::DebugView::Error(const wchar_t * const format, ...) const
{
	if(this->Get_log_level() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_ERROR)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::ERROR_, format, arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DEBUG_VIEW::DebugView::Fatal(const char * const format, ...) const
{
	if(this->Get_log_level() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_FATAL)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::FATAL_, format, arg_ptr);
		va_end(arg_ptr);
	}
}

void MOONG::DEBUG_VIEW::DebugView::Fatal(const wchar_t * const format, ...) const
{
	if(this->Get_log_level() <= MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_FATAL)
	{
		va_list arg_ptr;

		va_start(arg_ptr, format);
		this->Print(MOONG::DEBUG_VIEW::TOKEN::FATAL_, format, arg_ptr);
		va_end(arg_ptr);
	}
}



void MOONG::DEBUG_VIEW::DebugView::Print(const char* const token, const char* const format, va_list arg_ptr) const
{
	char build_string[kMaxBufSize] = { 0 };

	StringCchVPrintfA(build_string, kMaxBufSize, format, arg_ptr);

	CStringA debug_string;
	debug_string.Format("%s %s %s", this->Get_delimiter().GetBuffer() , token, build_string);

	OutputDebugStringA(debug_string.GetBuffer());
}

void MOONG::DEBUG_VIEW::DebugView::Print(const char* const token, const wchar_t* const format, va_list arg_ptr) const
{
	wchar_t build_string[kMaxBufSize] = { 0 };

	StringCchVPrintfW(build_string, kMaxBufSize, format, arg_ptr);

	CStringA convert_string(build_string);

	CStringA debug_string;
	debug_string.Format("%s %s %s", this->Get_delimiter().GetBuffer(), token, convert_string.GetBuffer());

	OutputDebugStringA(debug_string.GetBuffer());
}

CStringA MOONG::DEBUG_VIEW::DebugView::Get_delimiter() const
{
	return this->delimiter_;
}

void MOONG::DEBUG_VIEW::DebugView::Set_delimiter(CStringA delimiter)
{
	this->delimiter_ = delimiter;
}

unsigned int MOONG::DEBUG_VIEW::DebugView::Get_log_level() const
{
	return this->log_level_;
}

void MOONG::DEBUG_VIEW::DebugView::Set_log_level(unsigned int log_level)
{
	this->log_level_ = log_level;
}
