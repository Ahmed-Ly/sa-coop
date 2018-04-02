#include "main.h"
#include <d3d9.h>

CCore *core = nullptr;

class SACOOP 
{
public:
	SACOOP() 
	{
		core = new CCore();
	}
	~SACOOP() 
	{	
		delete core;
	}
} SACOOP;