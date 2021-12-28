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
			DebugView(const CStringA delimiter, const unsigned int logLevel = DEBUG_VIEW::LOG_LEVEL::LEVEL_WARN);

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
			void Print(const char* const token, const char* const format, va_list arg_ptr) const;
			void Print(const char* const token, const wchar_t* const format, va_list arg_ptr) const;

			const CStringA Get_delimiter() const;
			void Set_delimiter(const CStringA delimiter);

			unsigned int Get_log_level() const;
			void Set_log_level(unsigned int log_level);


		private:
			CStringA delimiter_;
			unsigned int log_level_;
		};
	}
}

#endif _DEBUG_VIEW_H_