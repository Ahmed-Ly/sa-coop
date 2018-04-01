#include "main.h"

bool debugEnabled = true;
char   SACOOP_string[600];

#ifdef SACOOP_DEBUG
DeveloperConsole* CDebugScreen::gDevConsole;

CDebugScreen::CDebugScreen() 
{
	debugEnabled = true;
}
CDebugScreen::~CDebugScreen() 
{

}
void CDebugScreen::Draw()
{
	if (!gNetwork->connected)
	{
		sprintf(SACOOP_string, "%s %s", SACOOP_NAME, SACOOP_VER);
	}
	else
	{
		sprintf(SACOOP_string, "%s %s     Server: %s:%d   Press F7 to disconnect", SACOOP_NAME, SACOOP_VER, gNetwork->addr.host, gNetwork->addr.port);
	}

	SIZE textSize = gRender->MeasureText(SACOOP_string);

	gRender->RenderText(SACOOP_string, { 10, (LONG)screen::GetScreenHeight() - textSize.cy - 5 }, (gNetwork->connected ? 0xFF00FF00 : 0xFFFFFFFF));

	sprintf(SACOOP_string, "Ped pool: %d/%d\nVehicle pool: %d/%d\nmsTime: %d\n", CPools::ms_pPedPool->GetNoOfFreeSpaces(), CPools::ms_pPedPool->m_nSize, CPools::ms_pVehiclePool->GetNoOfFreeSpaces(), CPools::ms_pVehiclePool->m_nSize, CTimer::m_snTimeInMilliseconds);
	textSize = gRender->MeasureText(SACOOP_string);
	gRender->RenderText(SACOOP_string, { (LONG)screen::GetScreenWidth() - textSize.cx - 5, (LONG)screen::GetScreenHeight() -textSize.cy - 5 }, 0xFFFFFFFF);
}
#endif
