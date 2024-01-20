#include "NewProject.h"

#include "Engine/Simulation.h"

#include "Platform/Win32/WinEntry.h"

class NewProject : public CreateInspiration::Simulation
{
public:
	//���캯��
	NewProject() {}

	//��������
	~NewProject() {}

public:

	VOID SetupPerGameSettings();

	//��ʼ������
	VOID Initialize() {}

	//ѭ������Ӧ������ʱ����ѭ��
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
