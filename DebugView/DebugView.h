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
			LEVEL_TRACE = 0,	// ��� ������ ���� ����Ѵ�.
			LEVEL_DEBUG,		// �Ϲ� ������ ���� ��Ÿ�� �� ����Ѵ�.
			LEVEL_INFO,			// �Ϲ� ������ ��Ÿ�� �� ����Ѵ�.
			LEVEL_WARN,			// ������ �ƴ����� ������ �ʿ䰡 ���� �� ����Ѵ�.
			LEVEL_ERROR,		// �Ϲ� ������ �Ͼ�� �� ����Ѵ�.
			LEVEL_FATAL			// ���� ũ��Ƽ���� ������ �Ͼ�� �� ����Ѵ�.
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
		public:	/* ������ & �Ҹ��� */
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