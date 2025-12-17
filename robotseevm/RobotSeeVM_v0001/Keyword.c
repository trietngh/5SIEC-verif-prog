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
#include "Keyword.h"

unsigned short Keyword( unsigned short Parameter )
{
	ERRORTYPE		ErrVal;
	DATATYPE		temp1;
	char			Output[32];

	ErrVal = 0;
	switch( Parameter )
	{
	case KEYWORD_VERSION:	// Display VM Version out Error stream
		CallBackErrorOut( VM_VERSION_STRING );
		ErrVal = Push( 0 );
		break;

	case KEYWORD_PRINTS:	// Print string FIFO to Console
		CallBackConsoleOut( GetString() );
		ErrVal = Push( 0 );
		break;

	case KEYWORD_PRINTVD:	// Print Value to Console in Decimal
		temp1 = Pop( &ErrVal );
		sprintf( Output, "%d", temp1 );
		CallBackConsoleOut( Output );
		ErrVal = Push( 0 );
		break;

	case KEYWORD_PRINTVH:	// Print Value to Console in Hex
		temp1 = Pop( &ErrVal );
		sprintf( Output, "%x", temp1 );
		CallBackConsoleOut( Output );
		ErrVal = Push( 0 );
		break;

	case KEYWORD_DELAY:		// Delay in ms
		EMGSLEEP( Top( &ErrVal ) );
		break;

	case KEYWORD_ABS:		// Absolute Value
		ErrVal = Push( abs(Pop( &ErrVal )) );
		break;

	case KEYWORD_TEST:		// ( reference, value1, value2 ) returns sum
		{
		DATATYPE ref = Pop( &ErrVal );			// variable reference
		DATATYPE temp2 = Pop( &ErrVal );        // value1
		DATATYPE temp3 = Pop( &ErrVal );        // value2
		sprintf( Output, "\ntest( %d, %d, %d )", ref, temp2, temp3 );
		CallBackConsoleOut( Output );
		temp1 = getVar( ref, &ErrVal );			// var[ref]
		sprintf( Output, "\nvar[%d] = %d", ref, temp1 );
		CallBackConsoleOut( Output );
		temp1 += (temp2+temp3); 
		ErrVal = setVar( ref, temp1 );
		sprintf( Output, "\nreturns: %d", temp1 );
		CallBackConsoleOut( Output );
		ErrVal = Push( temp1 );
		}
	}

	return ErrVal;
}
