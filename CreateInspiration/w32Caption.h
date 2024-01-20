#pragma once

namespace Win32
{
	class w32Caption
	{
	public:
		struct CaptionButton {
			WSTRING Text = L"";

			INT Command = -1;
			INT Width = 50;
			RECT Rect;

			CaptionButton(WSTRING text, INT command, INT width = 50) {
				Text = text;
				Command = command;
				Width = width;
			}
		};

	private:
		BOOL m_ShowTitle = TRUE;

	public:
		BOOL ShowTitle() { return m_ShowTitle; }

	public:
		VOID ShowTitle(BOOL show) { m_ShowTitle = show; }

	};
}
