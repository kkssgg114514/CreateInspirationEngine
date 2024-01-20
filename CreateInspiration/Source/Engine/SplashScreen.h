#pragma once

#include "Platform/Win32/Window.h"

namespace SplashScreen
{
	VOID CREATEINSPIRATION_API Open();
	VOID CREATEINSPIRATION_API Close();
	VOID CREATEINSPIRATION_API AddMessage(CONST WCHAR* message);
	
}

class CREATEINSPIRATION_API SplashWindow : public Win32::Window
{
public:
	SplashWindow();
	~SplashWindow();

	virtual			LRESULT					MessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) override;

private:
	WCHAR m_outputMessage[MAX_NAME_STRING];
};