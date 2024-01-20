#include "CreateInspiration.h"

namespace Engine
{
	CEngine g_CreateInspirationEngine;

	VOID SetMode(EngineMode mode)
	{
		g_CreateInspirationEngine.SetEngineMode(mode);
	}

	EngineMode GetMode()
	{
		return g_CreateInspirationEngine.GetEngineMode();
	}

	WSTRING CREATEINSPIRATION_API EngineModeToString()
	{
		switch (Engine::GetMode())
		{
		case EngineMode::DEBUG:
			return L"Debug";
		case EngineMode::RELEASE:
			return L"Release";
		case EngineMode::EDITOR:
			return L"Editor";
		case EngineMode::SERVER:
			return L"Server";
		default:
			return L"None";
		}
	}

}

CEngine::CEngine()
{
#ifdef _DEBUG
	m_EngineMode = EngineMode::DEBUG;
#else
	m_EngineMode = EngineMode::RELEASE;
#endif // _DEBUG
}

CEngine::~CEngine()
{
}

EngineMode CEngine::GetEngineMode()
{
	return m_EngineMode;
}

VOID CEngine::SetEngineMode(EngineMode mode)
{
	m_EngineMode = mode;
}
