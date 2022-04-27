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
		private:
			static void Print(const std::string token, const std::string format, va_list arg_ptr);
			static void Print(const std::string token, const std::wstring format, va_list arg_ptr);
		};
	}
}

#endif _DEBUG_VIEW_H_