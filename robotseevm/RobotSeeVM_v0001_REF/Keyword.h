//---------------------------------------------------------------------------
//    RobotSee, RobotSeeVM - Written by Eric Gregori ( www.EMGRobotics.com )
//    Copyright (C) 2010  Eric Gregori
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//---------------------------------------------------------------------------
//
// This file must compile on everything from a small 8bit micro, 
// all the way up to a Linux/Windows system.
// It's written in C for max portability ( 8bit processors are extremely inneficient at c++ )
// I also try to use global variables as much as possible to minimize RAM requirements
// for small embedded systems.  I avoided structures do to packing inneficiencies.
//
//---------------------------------------------------------------------------
#include "RobotSeeVM.h"

#define VM_VERSION_STRING	__DATE__ __TIME__


// Core Keywords
#define KEYWORD_VERSION							0
#define KEYWORD_PRINTS							1
#define KEYWORD_PRINTVD							2
#define KEYWORD_PRINTVH							3
#define KEYWORD_DELAY							4
#define KEYWORD_ABS								5
#define KEYWORD_TEST							6


// Linux/Windows Keywords
#define KEYWORD_GETMS							100
#define KEYWORD_TIME							101
#define KEYWORD_SOUNDPLAY						102
#define KEYWORD_SOUNDLOOP						103
#define KEYWORD_SOUNDSTOP						104
#define KEYWORD_SRAND							105
#define KEYWORD_RAND							106
#define KEYWORD_ATANTO							107
#define KEYWORD_SQRT							108
#define KEYWORD_ASIN							109
#define KEYWORD_ACOS							110
#define KEYWORD_ATAN							111
#define KEYWORD_TAN								112
#define KEYWORD_SIN								113
#define KEYWORD_COS								114



