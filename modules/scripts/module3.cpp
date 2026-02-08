#include <iostream>

#include "../../format.h"
#include "../Modules.h"




static void module_init()
{
	setupEnv();
}

static Module module(
	module_init,
	"Инициация" );

//