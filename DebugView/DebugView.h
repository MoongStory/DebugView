#pragma once

#ifndef DEBUG_VIEW_H_
#define DEBUG_VIEW_H_

#include <time.h>

namespace DEBUG_VIEW
{
	namespace LOG_LEVEL
	{
		enum LOG_LEVEL
		{
			LEVEL_TRACE = 0,	// 경로 추적을 위해 사용한다.
			LEVEL_DEBUG,		// 일반 정보를 상세히 나타낼 때 사용한다.
			LEVEL_INFO,			// 일반 정보를 나타낼 때 사용한다.
			LEVEL_WARN,			// 에러는 아니지만 주의할 필요가 있을 때 사용한다.
			LEVEL_ERROR,		// 일반 에러가 일어났을 때 사용한다.
			LEVEL_FATAL			// 가장 크리티컬한 에러가 일어났을 때 사용한다.
		};
	}

	const unsigned int kMaxBufSize = 1024;

	class DebugView
	{
	public:	/* 생성자 & 소멸자 */
		DebugView(const char* const delimiter, const unsigned int logLevel = DEBUG_VIEW::LOG_LEVEL::LEVEL_WARN);
		DebugView(const wchar_t* const delimiter, const unsigned int logLevel = DEBUG_VIEW::LOG_LEVEL::LEVEL_WARN);
		~DebugView();

	public:
		void Trace(const char* const format, ...);
		void Trace(const wchar_t* const format, ...);

		void Debug(const char* const format, ...);
		void Debug(const wchar_t* const format, ...);

		void Info(const char* const format, ...);
		void Info(const wchar_t* const format, ...);

		void Warn(const char* const format, ...);
		void Warn(const wchar_t* const format, ...);

		void Error(const char* const format, ...);
		void Error(const wchar_t* const format, ...);

		void Fatal(const char* const format, ...);
		void Fatal(const wchar_t* const format, ...);

	private:
		void Print(const char* const format, ...);


	private:
		char* delimiter_;
		time_t start_, end_;
		unsigned int log_level_;
	};
}

#endif DEBUG_VIEW_H_