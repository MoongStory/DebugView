#include "DebugView.h"

#include <windows.h>
#include <cstdio>
#include <cstdarg>
#include <tchar.h>
#include <strsafe.h>

DEBUG_VIEW::DebugView::DebugView(const char * const delimiter, const unsigned int log_level) :
	start_(0),
	end_(0),
	log_level_(DEBUG_VIEW::LOG_LEVEL::LEVEL_ERROR)
{
	if(log_level < DEBUG_VIEW::LOG_LEVEL::LEVEL_TRACE || log_level > DEBUG_VIEW::LOG_LEVEL::LEVEL_FATAL)
	{
		this->Fatal("Log Level 설정값이 잘못되어 Log Level이 Error Level로 초기화 됩니다.");
		this->log_level_ = DEBUG_VIEW::LOG_LEVEL::LEVEL_ERROR;
	}
	else
	{
		this->log_level_ = log_level;
	}

	size_t bufSize = strlen(delimiter) + 2;

	if (bufSize <= 3)	// 빈 문자열을 넘겨주며 객체를 생성한 경우.
	{
		this->delimiter_ = new char[kMaxBufSize];
		StringCchPrintfA(this->delimiter_, kMaxBufSize, "[%s]", "반드시 구분 문자를 지정해야 합니다");
	}
	else
	{
		this->delimiter_ = new char[bufSize];
		StringCchPrintfA(this->delimiter_, bufSize, "%s", delimiter);
	}
}



DEBUG_VIEW::DebugView::DebugView(const wchar_t * const delimiter, const unsigned int log_level) :
	start_(0),
	end_(0),
	log_level_(DEBUG_VIEW::LOG_LEVEL::LEVEL_ERROR)
{
	int bufSize = (int)(wcslen(delimiter) + 1);

	char * delimiter_multiByte = new char[bufSize];

	WideCharToMultiByte(CP_ACP, 0, delimiter, -1, delimiter_multiByte, bufSize, NULL, NULL);

	this->DebugView::DebugView(delimiter_multiByte, log_level);

	if (delimiter_multiByte != NULL)
	{
		delete[] delimiter_multiByte;
	}
}



DEBUG_VIEW::DebugView::~DebugView()
{
	if (this->delimiter_ != NULL)
	{
		delete[] this->delimiter_;
	}
}



void DEBUG_VIEW::DebugView::Trace(const char * const format, ...)
{
	if(this->log_level_ <= DEBUG_VIEW::LOG_LEVEL::LEVEL_TRACE)
	{
		va_list ap;
		char buf[kMaxBufSize] = { 0 };
		char debugString[kMaxBufSize] = { 0 };
		
		va_start(ap, format);
		StringCchVPrintfA(buf, kMaxBufSize, format, ap);
		va_end(ap);
		
		StringCchPrintfA(debugString, kMaxBufSize, "%s [TRACE] %s", this->delimiter_, buf);

		this->Print(debugString);
	}
}

void DEBUG_VIEW::DebugView::Trace(const wchar_t * const format, ...)
{
	if(this->log_level_ <= DEBUG_VIEW::LOG_LEVEL::LEVEL_TRACE)
	{
		va_list ap;
		wchar_t buf[kMaxBufSize] = { 0 };
		char debugString[kMaxBufSize] = { 0 };
		
		va_start(ap, format);
		StringCchVPrintfW(buf, kMaxBufSize, format, ap);
		va_end(ap);
		
		WideCharToMultiByte(CP_ACP, 0, buf, -1, debugString, kMaxBufSize, NULL, NULL);
		
		this->Trace(debugString);
	}
}



void DEBUG_VIEW::DebugView::Debug(const char * const format, ...)
{
	if(this->log_level_ <= DEBUG_VIEW::LOG_LEVEL::LEVEL_DEBUG)
	{
		va_list ap;
		char buf[kMaxBufSize] = { 0 };
		char debugString[kMaxBufSize] = { 0 };
		
		va_start(ap, format);
		StringCchVPrintfA(buf, kMaxBufSize, format, ap);
		va_end(ap);
		
		StringCchPrintfA(debugString, kMaxBufSize, "%s [DEBUG] %s", this->delimiter_, buf);
		
		this->Print(debugString);
	}
}

void DEBUG_VIEW::DebugView::Debug(const wchar_t * const format, ...)
{
	if(this->log_level_ <= DEBUG_VIEW::LOG_LEVEL::LEVEL_DEBUG)
	{
		va_list ap;
		wchar_t buf[kMaxBufSize] = { 0 };
		char debugString[kMaxBufSize] = { 0 };
		
		va_start(ap, format);
		StringCchVPrintfW(buf, kMaxBufSize, format, ap);
		va_end(ap);
		
		WideCharToMultiByte(CP_ACP, 0, buf, -1, debugString, kMaxBufSize, NULL, NULL);
		
		this->Debug(debugString);
	}
}



void DEBUG_VIEW::DebugView::Info(const char * const format, ...)
{
	if(this->log_level_ <= DEBUG_VIEW::LOG_LEVEL::LEVEL_INFO)
	{
		va_list ap;
		char buf[kMaxBufSize] = { 0 };
		char debugString[kMaxBufSize] = { 0 };
		
		va_start(ap, format);
		StringCchVPrintfA(buf, kMaxBufSize, format, ap);
		va_end(ap);
		
		StringCchPrintfA(debugString, kMaxBufSize, "%s [INFO] %s", this->delimiter_, buf);
		
		this->Print(debugString);
	}
}

void DEBUG_VIEW::DebugView::Info(const wchar_t * const format, ...)
{
	if(this->log_level_ <= DEBUG_VIEW::LOG_LEVEL::LEVEL_INFO)
	{
		va_list ap;
		wchar_t buf[kMaxBufSize] = { 0 };
		char debugString[kMaxBufSize] = { 0 };
		
		va_start(ap, format);
		StringCchVPrintfW(buf, kMaxBufSize, format, ap);
		va_end(ap);
		
		WideCharToMultiByte(CP_ACP, 0, buf, -1, debugString, kMaxBufSize, NULL, NULL);
		
		this->Info(debugString);
	}
}



void DEBUG_VIEW::DebugView::Warn(const char * const format, ...)
{
	if(this->log_level_ <= DEBUG_VIEW::LOG_LEVEL::LEVEL_WARN)
	{
		va_list ap;
		char buf[kMaxBufSize] = { 0 };
		char debugString[kMaxBufSize] = { 0 };
		
		va_start(ap, format);
		StringCchVPrintfA(buf, kMaxBufSize, format, ap);
		va_end(ap);
		
		StringCchPrintfA(debugString, kMaxBufSize, "%s [WARN] %s", this->delimiter_, buf);
		
		this->Print(debugString);
	}
}

void DEBUG_VIEW::DebugView::Warn(const wchar_t * const format, ...)
{
	if(this->log_level_ <= DEBUG_VIEW::LOG_LEVEL::LEVEL_WARN)
	{
		va_list ap;
		wchar_t buf[kMaxBufSize] = { 0 };
		char debugString[kMaxBufSize] = { 0 };
		
		va_start(ap, format);
		StringCchVPrintfW(buf, kMaxBufSize, format, ap);
		va_end(ap);
		
		WideCharToMultiByte(CP_ACP, 0, buf, -1, debugString, kMaxBufSize, NULL, NULL);
		
		this->Warn(debugString);
	}
}



void DEBUG_VIEW::DebugView::Error(const char * const format, ...)
{
	if(this->log_level_ <= DEBUG_VIEW::LOG_LEVEL::LEVEL_ERROR)
	{
		va_list ap;
		char buf[kMaxBufSize] = { 0 };
		char debugString[kMaxBufSize] = { 0 };
		
		va_start(ap, format);
		StringCchVPrintfA(buf, kMaxBufSize, format, ap);
		va_end(ap);
		
		StringCchPrintfA(debugString, kMaxBufSize, "%s [ERROR] %s", this->delimiter_, buf);
		
		this->Print(debugString);
	}
}

void DEBUG_VIEW::DebugView::Error(const wchar_t * const format, ...)
{
	if(this->log_level_ <= DEBUG_VIEW::LOG_LEVEL::LEVEL_ERROR)
	{
		va_list ap;
		wchar_t buf[kMaxBufSize] = { 0 };
		char debugString[kMaxBufSize] = { 0 };
		
		va_start(ap, format);
		StringCchVPrintfW(buf, kMaxBufSize, format, ap);
		va_end(ap);
		
		WideCharToMultiByte(CP_ACP, 0, buf, -1, debugString, kMaxBufSize, NULL, NULL);
		
		this->Error(debugString);
	}
}



void DEBUG_VIEW::DebugView::Fatal(const char * const format, ...)
{
	if(this->log_level_ <= DEBUG_VIEW::LOG_LEVEL::LEVEL_FATAL)
	{
		va_list ap;
		char buf[kMaxBufSize] = { 0 };
		char debugString[kMaxBufSize] = { 0 };
		
		va_start(ap, format);
		StringCchVPrintfA(buf, kMaxBufSize, format, ap);
		va_end(ap);
		
		StringCchPrintfA(debugString, kMaxBufSize, "%s [FATAL] %s", this->delimiter_, buf);
		
		this->Print(debugString);
	}
}

void DEBUG_VIEW::DebugView::Fatal(const wchar_t * const format, ...)
{
	if(this->log_level_ <= DEBUG_VIEW::LOG_LEVEL::LEVEL_FATAL)
	{
		va_list ap;
		wchar_t buf[kMaxBufSize] = { 0 };
		char debugString[kMaxBufSize] = { 0 };
		
		va_start(ap, format);
		StringCchVPrintfW(buf, kMaxBufSize, format, ap);
		va_end(ap);
		
		WideCharToMultiByte(CP_ACP, 0, buf, -1, debugString, kMaxBufSize, NULL, NULL);
		
		this->Fatal(debugString);
	}
}

void DEBUG_VIEW::DebugView::Print(const char* const format, ...)
{
	va_list ap;
	char buf[kMaxBufSize] = { 0 };
	char debugString[kMaxBufSize] = { 0 };

	va_start(ap, format);
	StringCchVPrintfA(buf, kMaxBufSize, format, ap);
	va_end(ap);

	StringCchPrintfA(debugString, kMaxBufSize, "%s %s\n", this->delimiter_, buf);

	OutputDebugStringA(debugString);
}