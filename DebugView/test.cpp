#include "DebugView.h"

#include <iostream>
#include <atlstr.h>	// TEXT, CString 사용을 위해

const char* const delimiter = "[MOONG_DEBUG]";
const wchar_t* const wDelimiter = L"[MOONG_DEBUG_W]";

int main()
{
	try
	{
		MOONG::DebugView::trace("트레이스");
		MOONG::DebugView::debug(L"디버그");
		MOONG::DebugView::info("Info");
		MOONG::DebugView::warn(L"Warn");
		MOONG::DebugView::error("Error");
		MOONG::DebugView::fatal(L"Fatal");

		MOONG::DebugView::debug("test00[%c][%d][%s][%.2lf]", 'a', 3, "한글 출력 000", 2.3456);
		MOONG::DebugView::debug(L"test01[%c][%d][%ws][%.2lf]", 'a', 3, L"드디어 한글 되네 001", 2.3456);

		MOONG::DebugView::set_delimiter(L"[MOONG_TEST]");

		MOONG::DebugView::trace(TEXT("test02[%c][%d][%s][%.2lf]"), 'a', 3, TEXT("test 002"), 2.3456);
		MOONG::DebugView::trace(L"test03[%c][%d][%s][%.2lf]", 'a', 3, L"test 003", 2.3456);

		CString strTest;
		strTest.Format(TEXT("test[%c][%d][%s][%.2lf]"), 'a', 3, TEXT("test 003"), 2.3456);
		MOONG::DebugView::debug(strTest.GetString());

		CString strTest000;
		strTest000 = "aaa";
		MOONG::DebugView::debug(strTest000.GetString());

		MOONG::DebugView::set_log_level(MOONG::DEBUG_VIEW::LEVEL::FATAL_);

		CString strTest001;
		strTest001 = L"bbb";
		MOONG::DebugView::debug(strTest001.GetString());
		MOONG::DebugView::fatal(strTest001.GetString());

		MOONG::DebugView::set_log_level(MOONG::DEBUG_VIEW::LEVEL::TRACE_);

		CString strTest002;
		strTest002 = L"ccc";
		MOONG::DebugView::debug(strTest002.GetString());
		MOONG::DebugView::fatal(strTest002.GetString());
	}
	catch (const std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
	}

	return EXIT_SUCCESS;
}