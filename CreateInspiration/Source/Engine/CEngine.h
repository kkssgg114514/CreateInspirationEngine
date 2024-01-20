#pragma once

class CREATEINSPIRATION_API CEngine;
namespace Engine
{
	enum EngineMode : INT
	{
		NONE,
		DEBUG,
		RELEASE,
		EDITOR,
		SERVER
	};

	extern CEngine g_CreateInspirationEngine;

	VOID CREATEINSPIRATION_API SetMode(EngineMode mode);
	EngineMode CREATEINSPIRATION_API GetMode();

	WSTRING CREATEINSPIRATION_API EngineModeToString();
}

using namespace Engine;
class CREATEINSPIRATION_API CEngine
{
public:
	CEngine();
	~CEngine();

private:
	EngineMode m_EngineMode;

public:
	EngineMode GetEngineMode();
	VOID SetEngineMode(EngineMode mode);
};