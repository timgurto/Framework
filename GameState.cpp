// (C) 2010-2011 Tim Gurto

#include <fstream>
#include <iostream>
#include <list>
#include "globals.h"
#include "util.h"
#include "GameState.h"
#include "misc.h"

GameState::GameState():
loop(true),
outcome(IN_PROGRESS){}