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

// CallStack
static unsigned long CallStack;
static unsigned short CallStackSize;
static unsigned short CallStackIndex;


void initCallStack( unsigned long* pCallStack, unsigned short CallStackDepth )
{
	CallStackIndex = 0;
	CallStackSize  = CallStackDepth;
	CallStack      = (unsigned long)pCallStack;
}

ERRORTYPE Push( DATATYPE data )
{
	if( CallStackIndex == CallStackSize ) return ERROR_CALLSTACK_OVERRUN; 
	*((DATATYPE*)CallStack+CallStackIndex) = data;
	++CallStackIndex;
	return 0;
}

DATATYPE Pop( ERRORTYPE* error )
{
	if( CallStackIndex == 0 ) 
	{
		*error = *error | ERROR_CALLSTACK_UNDERRUN;
		return 0;
	}
	--CallStackIndex;
	return( *((DATATYPE*)CallStack+CallStackIndex));
}

DATATYPE Top( ERRORTYPE* error )
{
	if( CallStackIndex == 0 ) 
	{
		*error = *error | ERROR_CALLSTACK_UNDERRUN;
		return 0;
	}
	return( *((DATATYPE*)CallStack+CallStackIndex-1) );
}

void ResetCallStack( void )
{
	CallStackIndex = 0;
}
