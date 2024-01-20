#include "CreateInspiration.h"
#include <fstream>
#include <Shlobj.h>
#include <cstdio>
#include <tlhelp32.h>

Logger* Logger::inst;

Logger::~Logger()
{
}

Logger::Logger()
{
	//单例模式构造方法
	inst = this;
}

VOID Logger::PrintLog(const WCHAR* fmt, ...)
{
	WCHAR buf[4096];
	va_list args;

	va_start(args, fmt);
	vswprintf_s(buf, fmt, args);
	va_end(args);

	//输出首先发送到控制台（或消息框，这取决于修改）
	//MessageBox(0, buf, 0, 0);
	OutputDebugString(buf);

	//日志数据保存位置，用微软提供的AppData文件夹保存法，区别不同的用户保存的文件，同时不会被系统锁死
	//示例位置 %AppData%/NewProject/Log/NewProject20231126151737.jour

	std::wfstream outfile;

	outfile.open(WSTRING(LogDirectory() + L"/" + LogFile()), std::ios_base::app);

	//MessageBox(0, LogDirectory().c_str(), 0, 0);

	if (outfile.is_open())
	{
		WSTRING s = buf;
		outfile << L"[" << Time::GetDateTimeString() << L"] " << s;
		outfile.close();
		OutputDebugString(s.c_str());
	}
	else
	{
		MessageBox(NULL, L"无法打开日志文件...", L"Log Error", MB_OK);
	}

}

WSTRING Logger::LogDirectory()
{
	WCHAR Path[1024];
	WCHAR* AppDataLocal;
	SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &AppDataLocal);
	wcscpy_s(Path, AppDataLocal);
	wcscat_s(Path, L"\\");
	wcscat_s(Path, PerGameSettings::GameName());
	CreateDirectory(Path, NULL);
	wcscat_s(Path, L"\\Log");
	CreateDirectory(Path, NULL);
	return Path;
}

WSTRING Logger::LogFile()
{
	WCHAR File[1024];
	wcscpy_s(File, PerGameSettings::GameName());
	wcscat_s(File, PerGameSettings::BootTime());
	wcscat_s(File, L".jour");
	return File;
}

VOID Logger::PrintDebugSeperator()
{
	WSTRING s = L"\n-------------------------------------------------------------------------------------------------------------\n\n";

#ifdef _DEBUG
	std::wfstream outfile;
	outfile.open(WSTRING(LogDirectory() + L"/" + LogFile()), std::ios_base::app);

	if (outfile.is_open())
	{
		outfile << s;
		outfile.close();
	}
	else
	{
		MessageBox(NULL, L"无法打开日志文件...", L"Log Error", MB_OK);
	}
#endif // _DEBUG
}

BOOL Logger::IsMTailRunning()
{
	bool exists = false;
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry))
	{
		while (Process32Next(snapshot, &entry))
		{
			if (!_wcsicmp(entry.szExeFile, L"mTAIL.exe"))
			{
				exists = true;
			}
		}
	}

	CloseHandle(snapshot);
	return exists;
}

VOID Logger::StartMTail()
{
	if (IsMTailRunning())
	{
		Logger::PrintLog(L"--MTail Startup failed - already running\n");
		return;
	}

	Logger::PrintLog(L"--Starting MTail\n");
	WCHAR path[MAX_PATH] = { 0 };
	GetCurrentDirectoryW(MAX_PATH, path);
	WSTRING url = path + WSTRING(L"/mTAIL.exe");
	WSTRING params = L" \"" + LogDirectory() + L"/" + LogFile() + L"\" /start";
	ShellExecute(0, NULL, url.c_str(), params.c_str(), NULL, SW_SHOWDEFAULT);
}

