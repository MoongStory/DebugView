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
			static const int LEVEL_TRACE = 0;	// ��� ������ ���� ����Ѵ�.
			static const int LEVEL_DEBUG = 1;	// �Ϲ� ������ ���� ��Ÿ�� �� ����Ѵ�.
			static const int LEVEL_INFO = 2;	// �Ϲ� ������ ��Ÿ�� �� ����Ѵ�.
			static const int LEVEL_WARN = 3;	// ������ �ƴ����� ������ �ʿ䰡 ���� �� ����Ѵ�.
			static const int LEVEL_ERROR = 4;	// �Ϲ� ������ �Ͼ�� �� ����Ѵ�.
			static const int LEVEL_FATAL = 5;	// ���� ũ��Ƽ���� ������ �Ͼ�� �� ����Ѵ�.
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
		static void Trace(const std::string format, ...) noexcept(false);
		static void Trace(const std::wstring format, ...) noexcept(false);
		
		static void Debug(const std::string format, ...) noexcept(false);
		static void Debug(const std::wstring format, ...) noexcept(false);
		
		static void Info(const std::string format, ...) noexcept(false);
		static void Info(const std::wstring format, ...) noexcept(false);
		
		static void Warn(const std::string format, ...) noexcept(false);
		static void Warn(const std::wstring format, ...) noexcept(false);
		
		static void Error(const std::string format, ...) noexcept(false);
		static void Error(const std::wstring format, ...) noexcept(false);
		
		static void Fatal(const std::string format, ...) noexcept(false);
		static void Fatal(const std::wstring format, ...) noexcept(false);
		
		
		
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