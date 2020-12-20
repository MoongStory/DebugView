#include "TimeCheck.h"

#include <Windows.h>
#include <iostream>
#include <strsafe.h>

TIME_CHECK::TimeCheck::TimeCheck(const char* const delimiter, const char* const description) :
	delimiter_(NULL),
	description_(NULL),
	start_(0),
	end_(0)
{
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

	start_ = time(NULL);

	struct tm current_time;
	localtime_s(&current_time, &start_);

	if (strlen(description) != 0)
	{
		bufSize = strlen(description) + 3;

		this->description_ = new char[bufSize];
		StringCchPrintfA(this->description_, bufSize, "%s", description);

		this->Print("시작 시간[%02d시 %02d분 %02d초] %s", current_time.tm_hour, current_time.tm_min, current_time.tm_sec, this->description_);
	}
	else
	{
		this->Print("시작 시간[%02d시 %02d분 %02d초]", current_time.tm_hour, current_time.tm_min, current_time.tm_sec);
	}
}



TIME_CHECK::TimeCheck::TimeCheck(const wchar_t* const delimiter, const wchar_t* const description) :
	delimiter_(NULL),
	description_(NULL),
	start_(0),
	end_(0)
{
	int bufSize = (int)(wcslen(delimiter) + 1);
	char* delimiter_multiByte = new char[bufSize];
	WideCharToMultiByte(CP_ACP, 0, delimiter, -1, delimiter_multiByte, bufSize, NULL, NULL);

	if (wcslen(description) != 0)
	{
		bufSize = (int)(wcslen(description) + 1);
		char* description_multiByte = new char[bufSize];
		WideCharToMultiByte(CP_ACP, 0, description, -1, description_multiByte, bufSize, NULL, NULL);

		this->TimeCheck::TimeCheck(delimiter_multiByte, description_multiByte);

		if (description_multiByte != NULL)
		{
			delete[] description_multiByte;
		}
	}
	else
	{
		this->TimeCheck::TimeCheck(delimiter_multiByte);
	}

	if (delimiter_multiByte != NULL)
	{
		delete[] delimiter_multiByte;
	}
}



TIME_CHECK::TimeCheck::~TimeCheck()
{
	end_ = time(NULL);

	struct tm current_time;
	localtime_s(&current_time, &end_);

	if (this->description_ == NULL)
	{
		this->Print("종료 시간[%02d시 %02d분 %02d초] (%.3lf (Sec) 소요)", current_time.tm_hour, current_time.tm_min, current_time.tm_sec, (double)(this->end_ - this->start_));
	}
	else
	{
		this->Print("종료 시간[%02d시 %02d분 %02d초] %s (%.3lf (Sec) 소요)", current_time.tm_hour, current_time.tm_min, current_time.tm_sec, this->description_, (double)(this->end_ - this->start_));
	}

	if (this->delimiter_ != NULL)
	{
		delete[] this->delimiter_;
	}

	if (this->description_ != NULL)
	{
		delete[] this->description_;
	}
}



void TIME_CHECK::TimeCheck::Print(const char* const format, ...)
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