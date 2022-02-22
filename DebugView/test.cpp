#include <iostream>
#include <atlstr.h>	// TEXT, CString 사용을 위해

#include "DebugView.h"

const char* const delimiter = "[MOONG_DEBUG]";
const wchar_t* const wDelimiter = L"[MOONG_DEBUG_W]";

int main()
{
	//MOONG::DEBUG_VIEW::DebugView debug(delimiter, MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_TRACE);
	MOONG::DEBUG_VIEW::DebugView debug(wDelimiter, MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_TRACE);
	//MOONG::DEBUG_VIEW::DebugView debug("", MOONG::DEBUG_VIEW::LOG_LEVEL::LEVEL_TRACE);
	//MOONG::DEBUG_VIEW::DebugView debug(delimiter);
	//MOONG::DEBUG_VIEW::DebugView debug(wDelimiter);

	debug.Trace("Trace");
	debug.Debug(L"Debug");
	debug.Info("Info");
	debug.Warn(L"Warn");
	debug.Error("Error");
	debug.Fatal(L"Fatal");
	
	debug.Debug("test00[%c][%d][%s][%.2lf]", 'a', 3, "테스트 000", 2.3456);
	debug.Debug(L"test01[%c][%d][%s][%.2lf]", 'a', 3, L"테스트 001", 2.3456);
	debug.Trace(TEXT("test02[%c][%d][%s][%.2lf]"), 'a', 3, TEXT("테스트 002"), 2.3456);
	debug.Trace(L"test03[%c][%d][%s][%.2lf]", 'a', 3, L"테스트 003", 2.3456);

	CString strTest;
	strTest.Format(TEXT("test[%c][%d][%s][%.2lf]"), 'a', 3, TEXT("테스트 003"), 2.3456);
	debug.Debug(strTest);

	CString strTest000;
	strTest000 = "aaa";
	debug.Debug(strTest000);

	CString strTest001;
	strTest001 = L"bbb";
	debug.Debug(strTest001);

	return EXIT_SUCCESS;
}