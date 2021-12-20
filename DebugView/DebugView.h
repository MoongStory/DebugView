// https://github.com/MoongStory/DebugView

#if _MSC_VER > 1000
	#pragma once
#endif

#ifndef _DEBUG_VIEW_H_
#define _DEBUG_VIEW_H_

#include <atlstr.h>

namespace MOONG
{
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

		namespace TOKEN
		{
			const char* const TRACE_ = "[TRACE]";
			const char* const DEBUG_ = "[DEBUG]";
			const char* const INFO_ = "[INFO]";
			const char* const WARN_ = "[WARN]";
			const char* const ERROR_ = "[ERROR]";
			const char* const FATAL_ = "[FATAL]";
		}

		const unsigned int kMaxBufSize = 1024;

		class DebugView
		{
		public:	/* 생성자 & 소멸자 */
			DebugView(const CStringA delimiter, const unsigned int logLevel = DEBUG_VIEW::LOG_LEVEL::LEVEL_WARN);

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
			void Print(const char* const token, const char* const format, va_list arg_ptr);
			void Print(const char* const token, const wchar_t* const format, va_list arg_ptr);

			CStringA Get_delimiter();
			void Set_delimiter(CStringA delimiter);

			unsigned int Get_log_level();
			void Set_log_level(unsigned int log_level);


		private:
			CStringA delimiter_;
			unsigned int log_level_;
		};
	}
}

#endif _DEBUG_VIEW_H_