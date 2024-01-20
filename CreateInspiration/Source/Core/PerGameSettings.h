#pragma once

class CREATEINSPIRATION_API PerGameSettings
{
	//静态类，单例模式，因为一个项目只能有一组设置
private:
	static PerGameSettings* inst;

	static PerGameSettings* Instance() { return inst; }

public:
	PerGameSettings();
	~PerGameSettings();

private:
	//每个项目都应该有的属性
	WCHAR m_GameName[MAX_NAME_STRING];
	WCHAR m_ShortName[MAX_NAME_STRING];
	HICON m_MainIcon;
	WCHAR m_BootTime[MAX_NAME_STRING];
	WCHAR m_SplashURL[MAX_NAME_STRING];

public:
	//用来访问和设置项目属性
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