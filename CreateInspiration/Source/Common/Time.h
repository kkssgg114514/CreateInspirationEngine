#pragma once
#include <string>

namespace Time
{
	//获取当前时间，返回字符串
	WSTRING CREATEINSPIRATION_API GetTime(BOOL stripped = FALSE);

	//获取当前日期，返回字符串
	WSTRING CREATEINSPIRATION_API GetDate(BOOL stripped = FALSE);

	//获得当前的日期和时间，返回字符串
	WSTRING CREATEINSPIRATION_API GetDateTimeString(BOOL stripped = FALSE);
}