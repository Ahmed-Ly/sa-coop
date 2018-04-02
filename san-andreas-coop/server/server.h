#pragma once

#if defined( _MSC_VER )
#pragma warning (disable : 4244)
#pragma warning (disable : 4348)
#pragma warning (disable : 4060)
#pragma warning (disable : 4018)

// librg
#include "vendor\librg\librg.h"

// inih
#include "vendor\inih\INIReader.h"

// Lua
extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

#include <Windows.h>
#include <experimental/filesystem>
#include <filesystem>

// Plugin-SDK
#include "game_vc/CPad.h"
#include "game_vc/CVector.h"
#include "game_vc/CVector2D.h"
#include "game_vc/CPathNode.h"
#include "game_vc/CColPoint.h"

#else
#define HAS_SOCKLEN_T 1

#include <pthread.h>
#include <experimental/filesystem>
	
// librg
#include "./vendor/librg/librg.h"

// inih
#include "./vendor/inih/INIReader.h"

// Lua
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}


#endif


// Standard includes
#include <iostream>
#include <ostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>

// SACOOP
#include "../sacoop_main/config.h"

#if !defined(SACOOP_VERBOSE_LOG) && defined(SACOOP_DEBUG)
	#define SACOOP_VERBOSE_LOG
#else
	#undef SACOOP_VERBOSE_LOG
#endif

#ifndef _DEBUG
	#undef SACOOP_DEBUG_ENGINE
	#undef SACOOP_VERBOSE_LOG
#endif 


#include "CModelIDs.h"
#include "CConfiguration.h"

#include "CLogger.h"
#include "CServerNetwork.h"

#include "CCustomData.h"
#include "CCustomDataManager.h"

#include "CLuaScript.h"
#include "CLuaDumper.h"

//------------------------------------------------------------------------------------------------

extern CConfiguration		*gConfig;
extern CLogger				*gLog;
extern CServerNetwork		*gServerNetwork;

extern CCustomDataManager	*gDataMgr;

extern std::string			ServerGamemodePath;
extern CLuaScript			*gGamemodeScript;

using namespace std;