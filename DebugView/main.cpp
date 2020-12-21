// 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>

#include "DebugView.h"
#include "TimeCheck.h"
#include <atlstr.h>

const char* const delimiter = "[4444 TEST]";
const char* const wDelimiter = "[4444 TEST]";
const char* const timeDelimiter = "[4444 TIME_CHECK]";
const char* const wTimeDelimiter = "[4444 TIME_CHECK]";

int IntervalCheckTest();

int main()
{
	DEBUG_VIEW::DebugView debug(wDelimiter, DEBUG_VIEW::LOG_LEVEL::LEVEL_TRACE);
	//DEBUG_VIEW::DebugView debug(delimiter);
	//DEBUG_VIEW::DebugView debug(wDelimiter);

	debug.Trace("Trace");
	debug.Debug(L"Debug");
	debug.Info("Info");
	debug.Warn(L"Warn");
	debug.Error("Error");
	debug.Fatal(L"Fatal");

	IntervalCheckTest();
	
	debug.Debug("test[%c][%d][%s][%.2lf]", 'a', 3, "테스트 000", 2.3456);
	debug.Debug(L"test[%c][%d][%s][%.2lf]", 'a', 3, L"테스트 001", 2.3456);
	debug.Trace(_T("test[%c][%d][%s][%.2lf]"), 'a', 3, _T("테스트 002"), 2.3456);

	CString strTest;
	strTest.Format(_T("test[%c][%d][%s][%.2lf]"), 'a', 3, _T("테스트 003"), 2.3456);
	debug.Debug(strTest);

	CString strTest000;
	strTest000 = "aaa";
	debug.Debug(strTest000);

	CString strTest001;
	strTest001 = L"bbb";
	debug.Debug(strTest001);

	return EXIT_SUCCESS;
}

int IntervalCheckTest()
{
	//TIME_CHECK::TimeCheck intervalTestWithDesc(timeDelimiter, "IntervalCheckTest 함수 시간 체크");
	//TIME_CHECK::TimeCheck intervalTestWithDesc(timeDelimiter, __func__);
	TIME_CHECK::TimeCheck intervalTestWithDesc(timeDelimiter, __FUNCTION__);
	//TIME_CHECK::TimeCheck intervalTestWithDesc(wTimeDelimiter, __func__);

	//TIME_CHECK::TimeCheck intervalTest(timeDelimiter);
	TIME_CHECK::TimeCheck intervalTest(wTimeDelimiter);

	Sleep(3000);

	return 0;
}