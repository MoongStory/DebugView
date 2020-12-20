#pragma once

#ifndef TIME_CHECK_H_
#define TIME_CHECK_H_

#include <ctime>

namespace TIME_CHECK
{
	const unsigned int kMaxBufSize = 1024;

	class TimeCheck
	{
	public:	/* 持失切 & 社瑚切 */
		TimeCheck(const char* const delimiter, const char* const description = "");
		TimeCheck(const wchar_t* const delimiter, const wchar_t* const description = L"");
		~TimeCheck();

	private:
		void Print(const char* const format, ...);

	private:
		char* delimiter_;
		char* description_;
		time_t start_, end_;
	};
}

#endif TIME_CHECK_H_