#pragma once

class CREATEINSPIRATION_API PerGameSettings
{
	//��̬�࣬����ģʽ����Ϊһ����Ŀֻ����һ������
private:
	static PerGameSettings* inst;

	static PerGameSettings* Instance() { return inst; }

public:
	PerGameSettings();
	~PerGameSettings();

private:
	//ÿ����Ŀ��Ӧ���е�����
	WCHAR m_GameName[MAX_NAME_STRING];
	WCHAR m_ShortName[MAX_NAME_STRING];
	HICON m_MainIcon;
	WCHAR m_BootTime[MAX_NAME_STRING];
	WCHAR m_SplashURL[MAX_NAME_STRING];

public:
	//�������ʺ�������Ŀ����
	static WCHAR* GameName() { return inst->m_GameName; }
	static VOID SetGameName(UINT id) { LoadString(HInstance(), id, inst->m_GameName, MAX_NAME_STRING); }

	static WCHAR* ShortName() { return inst->m_ShortName; }
	static VOID SetShortName(UINT id) { LoadString(HInstance(), id, inst->m_ShortName, MAX_NAME_STRING); }

	static HICON MainIcon() { return inst->m_MainIcon; }
	static VOID SetMainIcon(UINT id) { LoadIcon(HInstance(), MAKEINTRESOURCE(id)); }

	static WCHAR* BootTime() { return inst->m_BootTime; }

	static WCHAR* SplashURL() { return inst->m_SplashURL; }
	static VOID SetSplashURL(UINT id) { LoadString(HInstance(), id, inst->m_SplashURL, MAX_NAME_STRING); }

};