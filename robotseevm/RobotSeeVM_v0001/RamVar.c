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

static unsigned short MaxVarIndex;
static unsigned long  RamVar;

void initRAMArray( unsigned long* pRamVar, unsigned short MaxVars )
{
	MaxVarIndex = MaxVars;
	RamVar      = (unsigned long)pRamVar; 
}

ERRORTYPE setVar( unsigned short Reference, DATATYPE Data )
{
	if( Reference > MaxVarIndex ) return ERROR_REFERENCE_OUTOFRANGE;
	*((DATATYPE*)RamVar+Reference) = Data;
	return 0;
}

DATATYPE getVar( unsigned short Reference, ERRORTYPE *error )
{
	if( Reference > MaxVarIndex ) *error |= ERROR_REFERENCE_OUTOFRANGE;
	return( *((DATATYPE*)RamVar+Reference) );
}
