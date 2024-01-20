#pragma once

#ifdef BUILD_DLL
	#define CREATEINSPIRATION_API __declspec(dllexport)
#else
	#define CREATEINSPIRATION_API __declspec(dllimport)
#endif // BUILD_DLL

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL)

typedef std::wstring WSTRING;
typedef std::string  STRING;