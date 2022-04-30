#include <iostream>
#include <atlstr.h>	// TEXT, CString 사용을 위해

#include "DebugView.h"

const char* const delimiter = "[MOONG_DEBUG]";
const wchar_t* const wDelimiter = L"[MOONG_DEBUG_W]";

int main()
{
	MOONG::DebugView::Trace("트레이스");
	MOONG::DebugView::Debug(L"디버그");
	MOONG::DebugView::Info("Info");
	MOONG::DebugView::Warn(L"Warn");
	MOONG::DebugView::Error("Error");
	MOONG::DebugView::Fatal(L"Fatal");
	
	MOONG::DebugView::Debug("test00[%c][%d][%s][%.2lf]", 'a', 3, "한글 출력 000", 2.3456);
	MOONG::DebugView::Debug(L"test01[%c][%d][%s][%.2lf]", 'a', 3, L"드디어 한글 되네 001", 2.3456);

	MOONG::DebugView::setDelimiter(L"[MOONG_TEST]");

	MOONG::DebugView::Trace(TEXT("test02[%c][%d][%s][%.2lf]"), 'a', 3, TEXT("test 002"), 2.3456);
	MOONG::DebugView::Trace(L"test03[%c][%d][%s][%.2lf]", 'a', 3, L"test 003", 2.3456);

	CString strTest;
	strTest.Format(TEXT("test[%c][%d][%s][%.2lf]"), 'a', 3, TEXT("test 003"), 2.3456);
	MOONG::DebugView::Debug(strTest.GetString());

	CString strTest000;
	strTest000 = "aaa";
	MOONG::DebugView::Debug(strTest000.GetString());

	MOONG::DebugView::setLogLevel(MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_FATAL);

	CString strTest001;
	strTest001 = L"bbb";
	MOONG::DebugView::Debug(strTest001.GetString());
	MOONG::DebugView::Fatal(strTest001.GetString());

	MOONG::DebugView::setLogLevel(MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_TRACE);

	CString strTest002;
	strTest002 = L"ccc";
	MOONG::DebugView::Debug(strTest002.GetString());
	MOONG::DebugView::Fatal(strTest002.GetString());

	return EXIT_SUCCESS;
}