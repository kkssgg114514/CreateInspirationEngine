#pragma once
#include <string>

namespace Time
{
	//��ȡ��ǰʱ�䣬�����ַ���
	WSTRING CREATEINSPIRATION_API GetTime(BOOL stripped = FALSE);

	//��ȡ��ǰ���ڣ������ַ���
	WSTRING CREATEINSPIRATION_API GetDate(BOOL stripped = FALSE);

	//��õ�ǰ�����ں�ʱ�䣬�����ַ���
	WSTRING CREATEINSPIRATION_API GetDateTimeString(BOOL stripped = FALSE);
}