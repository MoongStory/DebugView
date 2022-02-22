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
			enum LOG_LEVEL
			{
				LEVEL_TRACE = 0,	// ��� ������ ���� ����Ѵ�.
				LEVEL_DEBUG,		// �Ϲ� ������ ���� ��Ÿ�� �� ����Ѵ�.
				LEVEL_INFO,			// �Ϲ� ������ ��Ÿ�� �� ����Ѵ�.
				LEVEL_WARN,			// ������ �ƴ����� ������ �ʿ䰡 ���� �� ����Ѵ�.
				LEVEL_ERROR,		// �Ϲ� ������ �Ͼ�� �� ����Ѵ�.
				LEVEL_FATAL			// ���� ũ��Ƽ���� ������ �Ͼ�� �� ����Ѵ�.
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
		public:	/* ������ & �Ҹ��� */
			DebugView(const std::string delimiter, const unsigned int log_level = DEBUG_VIEW::LOG_LEVEL::LEVEL_WARN);
			DebugView(const std::wstring wDelimiter, const unsigned int log_level = DEBUG_VIEW::LOG_LEVEL::LEVEL_WARN);

		public:
			void Trace(const char* const format, ...) const;
			void Trace(const wchar_t* const format, ...) const;

			void Debug(const char* const format, ...) const;
			void Debug(const wchar_t* const format, ...) const;

			void Info(const char* const format, ...) const;
			void Info(const wchar_t* const format, ...) const;

			void Warn(const char* const format, ...) const;
			void Warn(const wchar_t* const format, ...) const;

			void Error(const char* const format, ...) const;
			void Error(const wchar_t* const format, ...) const;

			void Fatal(const char* const format, ...) const;
			void Fatal(const wchar_t* const format, ...) const;

		private:
			void Init(const std::string delimiter, const unsigned int log_level);

			void Print(const char* const token, const char* const format, va_list arg_ptr) const;
			void Print(const char* const token, const wchar_t* const format, va_list arg_ptr) const;

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