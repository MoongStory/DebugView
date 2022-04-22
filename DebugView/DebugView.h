// https://github.com/MoongStory/DebugView

#if _MSC_VER > 1000
	#pragma once
#endif

#ifndef _DEBUG_VIEW_H_
#define _DEBUG_VIEW_H_

#include <iostream>

namespace MOONG
{
	namespace DEBUG_VIEW
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

		namespace TOKEN
		{
			const std::string TRACE_ = "[TRACE]";
			const std::string DEBUG_ = "[DEBUG]";
			const std::string INFO_ = "[INFO]";
			const std::string WARN_ = "[WARN]";
			const std::string ERROR_ = "[ERROR]";
			const std::string FATAL_ = "[FATAL]";
		}

		const unsigned int kMaxBufSize = 1024;

		class DebugView
		{
		public:	/* 생성자 & 소멸자 */
			DebugView(const std::string delimiter, const unsigned int log_level = DEBUG_VIEW::LOG_LEVEL::LEVEL_WARN);
			DebugView(const std::wstring wDelimiter, const unsigned int log_level = DEBUG_VIEW::LOG_LEVEL::LEVEL_WARN);

		public:
			void Trace(const std::string format, ...) const;
			void Trace(const std::wstring format, ...) const;

			void Debug(const std::string format, ...) const;
			void Debug(const std::wstring format, ...) const;

			void Info(const std::string format, ...) const;
			void Info(const std::wstring format, ...) const;

			void Warn(const std::string format, ...) const;
			void Warn(const std::wstring format, ...) const;

			void Error(const std::string format, ...) const;
			void Error(const std::wstring format, ...) const;

			void Fatal(const std::string format, ...) const;
			void Fatal(const std::wstring format, ...) const;

		private:
			void Init(const std::string delimiter, const unsigned int log_level);

			void Print(const std::string token, const std::string format, va_list arg_ptr) const;
			void Print(const std::string token, const std::wstring format, va_list arg_ptr) const;

			const std::string Get_delimiter() const;
			void setDelimiter(const std::string delimiter);

			unsigned int getLogLevel() const;
			void setLogLevel(unsigned int log_level);


		private:
			std::string delimiter_;
			unsigned int log_level_;
		};
	}
}

#endif _DEBUG_VIEW_H_