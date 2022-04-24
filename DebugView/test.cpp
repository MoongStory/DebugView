#include <iostream>
#include <atlstr.h>	// TEXT, CString 사용을 위해

#include "DebugView.h"

const char* const delimiter = "[MOONG_DEBUG]";
const wchar_t* const wDelimiter = L"[MOONG_DEBUG_W]";

int main()
{
	MOONG::DEBUG_VIEW::DebugView::Trace("트레이스");
	MOONG::DEBUG_VIEW::DebugView::Debug(L"디버그");
	MOONG::DEBUG_VIEW::DebugView::Info("Info");
	MOONG::DEBUG_VIEW::DebugView::Warn(L"Warn");
	MOONG::DEBUG_VIEW::DebugView::Error("Error");
	MOONG::DEBUG_VIEW::DebugView::Fatal(L"Fatal");
	
	MOONG::DEBUG_VIEW::DebugView::Debug("test00[%c][%d][%s][%.2lf]", 'a', 3, "한글 출력 000", 2.3456);
	MOONG::DEBUG_VIEW::DebugView::Debug(L"test01[%c][%d][%s][%.2lf]", 'a', 3, L"드디어 한글 되네 001", 2.3456);

	MOONG::DEBUG_VIEW::DebugView::setDelimiter(L"[MOONG_TEST]");

	MOONG::DEBUG_VIEW::DebugView::Trace(TEXT("test02[%c][%d][%s][%.2lf]"), 'a', 3, TEXT("test 002"), 2.3456);
	MOONG::DEBUG_VIEW::DebugView::Trace(L"test03[%c][%d][%s][%.2lf]", 'a', 3, L"test 003", 2.3456);

	CString strTest;
	strTest.Format(TEXT("test[%c][%d][%s][%.2lf]"), 'a', 3, TEXT("test 003"), 2.3456);
	MOONG::DEBUG_VIEW::DebugView::Debug(strTest.GetString());

	CString strTest000;
	strTest000 = "aaa";
	MOONG::DEBUG_VIEW::DebugView::Debug(strTest000.GetString());

	MOONG::DEBUG_VIEW::DebugView::setLogLevel(MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_FATAL);

	CString strTest001;
	strTest001 = L"bbb";
	MOONG::DEBUG_VIEW::DebugView::Debug(strTest001.GetString());
	MOONG::DEBUG_VIEW::DebugView::Fatal(strTest001.GetString());

	MOONG::DEBUG_VIEW::DebugView::setLogLevel(MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_TRACE);

	CString strTest002;
	strTest002 = L"ccc";
	MOONG::DEBUG_VIEW::DebugView::Debug(strTest002.GetString());
	MOONG::DEBUG_VIEW::DebugView::Fatal(strTest002.GetString());

	return EXIT_SUCCESS;
}