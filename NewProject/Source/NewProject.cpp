#include "NewProject.h"

#include "Engine/Simulation.h"

#include "Platform/Win32/WinEntry.h"

class NewProject : public CreateInspiration::Simulation
{
public:
	//构造函数
	NewProject() {}

	//析构函数
	~NewProject() {}

public:

	VOID SetupPerGameSettings();

	//初始化方法
	VOID Initialize() {}

	//循环，在应用运行时不断循环
	VOID Update() {}
};

ENTRYAPP(NewProject)

VOID NewProject::SetupPerGameSettings()
{
	PerGameSettings::SetGameName(IDS_PERGAMENAME);
	PerGameSettings::SetShortName(IDS_SHORTNAME);
	PerGameSettings::SetMainIcon(IDI_MAINICON);
	PerGameSettings::SetSplashURL(IDS_SPLASHURL);
}
