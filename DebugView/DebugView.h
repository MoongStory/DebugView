/*******************************************************************************
MIT License

Copyright (c) 2023 Moong

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*******************************************************************************/

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
		namespace LEVEL
		{
			static const int TRACE_ = 0;	// 경로 추적을 위해 사용한다.
			static const int DEBUG_ = 1;	// 일반 정보를 상세히 나타낼 때 사용한다.
			static const int INFO_ = 2;	// 일반 정보를 나타낼 때 사용한다.
			static const int WARN_ = 3;	// 에러는 아니지만 주의할 필요가 있을 때 사용한다.
			static const int ERROR_ = 4;	// 일반 에러가 일어났을 때 사용한다.
			static const int FATAL_ = 5;	// 가장 크리티컬한 에러가 일어났을 때 사용한다.
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



		static void Print(const std::string format, ...);
		static void Print(const std::wstring format, ...);
		
		
		
		static const std::string Get_delimiter();
		static void setDelimiter(const std::string delimiter);
		static void setDelimiter(const std::wstring wDelimiter);
		
		static unsigned int getLogLevel();
		static void setLogLevel(unsigned int log_level);
	private:
		static void Print_(const std::string token, const std::string format, va_list arg_ptr);
	};
}

#endif _DEBUG_VIEW_H_