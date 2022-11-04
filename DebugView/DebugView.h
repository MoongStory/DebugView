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
		namespace LOG_LEVEL
		{
			static const int LEVEL_TRACE = 0;	// 경로 추적을 위해 사용한다.
			static const int LEVEL_DEBUG = 1;	// 일반 정보를 상세히 나타낼 때 사용한다.
			static const int LEVEL_INFO = 2;	// 일반 정보를 나타낼 때 사용한다.
			static const int LEVEL_WARN = 3;	// 에러는 아니지만 주의할 필요가 있을 때 사용한다.
			static const int LEVEL_ERROR = 4;	// 일반 에러가 일어났을 때 사용한다.
			static const int LEVEL_FATAL = 5;	// 가장 크리티컬한 에러가 일어났을 때 사용한다.
		}
	}
	
	class DebugView
	{
	public:
	protected:
	private:
		static const std::string TRACE_;
		static const std::string DEBUG_;
		static const std::string INFO_;
		static const std::string WARN_;
		static const std::string ERROR_;
		static const std::string FATAL_;
		
		static const unsigned int max_buf_size_;
		static std::string delimiter_;
		static unsigned int log_level_;
		
		
		
	public:
		static void Trace(const std::string format, ...);
		static void Trace(const std::wstring format, ...);
		
		static void Debug(const std::string format, ...);
		static void Debug(const std::wstring format, ...);
		
		static void Info(const std::string format, ...);
		static void Info(const std::wstring format, ...);
		
		static void Warn(const std::string format, ...);
		static void Warn(const std::wstring format, ...);
		
		static void Error(const std::string format, ...);
		static void Error(const std::wstring format, ...);
		
		static void Fatal(const std::string format, ...);
		static void Fatal(const std::wstring format, ...);
		
		
		
		static const std::string Get_delimiter();
		static void setDelimiter(const std::string delimiter);
		static void setDelimiter(const std::wstring wDelimiter);
		
		static unsigned int getLogLevel();
		static void setLogLevel(unsigned int log_level);

		static const unsigned int getMaxBufSize();
	private:
		static void Print(const std::string token, const std::string format, va_list arg_ptr) noexcept(false);
		static void Print(const std::string token, const std::wstring format, va_list arg_ptr) noexcept(false);
	};
}

#endif _DEBUG_VIEW_H_