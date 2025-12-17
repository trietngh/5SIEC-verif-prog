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

ERRORTYPE Operator( unsigned short Parameter )
{
	DATATYPE temp1;
	ERRORTYPE ErrVal;

	ErrVal = 0;
	switch( Parameter )
	{
	case 0x0021: // '!' -> if( pop() == 0 ) push(0)
		if( Pop( &ErrVal ) == 0 ) 
			ErrVal |= Push( 1 );
		else
			ErrVal |= Push( 0 );
		break;

	case 0x0026: // '&' -> top = pop & pop
		temp1 = Pop( &ErrVal ) & Pop( &ErrVal );
		ErrVal |= Push( temp1 );
		break;

	case 0x002A: // '*' -> top = pop * pop
		temp1 = Pop( &ErrVal ) * Pop( &ErrVal );
		ErrVal |= Push( temp1 );
		break;

	case 0x002B: // '+' -> top = pop + pop
		temp1 = Pop( &ErrVal ) + Pop( &ErrVal );
		ErrVal |= Push( temp1 );
		break;
		
	case 0x002D: // '-' -> top = pop - pop
		temp1 = Pop( &ErrVal ) - Pop( &ErrVal );
		ErrVal |= Push( temp1 );
		break;

	case 0x002F: // '/' -> top = pop / pop
		temp1 = Pop( &ErrVal ) / Pop( &ErrVal );
		ErrVal |= Push( temp1 );
		break;

	case 0x003C: // '<' 
		if( Pop( &ErrVal ) < Pop( &ErrVal ) ) 
			ErrVal |= Push( 1 );
		else
			ErrVal |= Push( 0 );
		break;

	case 0x003D: // '=' -> varREF = Value -> varREF, Value
		ErrVal |= setVar( (unsigned short)Pop( &ErrVal ), Top( &ErrVal ) ); // Leave Value on stack
		break;

	case 0x003E: // '>' 
		if( Pop( &ErrVal ) > Pop( &ErrVal ) ) 
			ErrVal |= Push( 1 );
		else
			ErrVal |= Push( 0 );
		break;

	case 0x007C: // '|' -> top = pop | pop
		temp1 = Pop( &ErrVal ) | Pop( &ErrVal );
		ErrVal |= Push( temp1 );
		break;

	case 0x263D: // '&=' -> varREF = varREF & value
		temp1 = Pop( &ErrVal );
		ErrVal |= setVar( (unsigned short)temp1, getVar((unsigned short)temp1, &ErrVal) & Pop( &ErrVal ) );
		break;

	case 0x2A3D: // '*=' -> varREF = varREF * value
		temp1 = Pop( &ErrVal );
		ErrVal |= setVar( (unsigned short)temp1, getVar((unsigned short)temp1, &ErrVal) * Pop( &ErrVal ) );
		break;

	case 0x2B3D: // '+=' -> varREF = varREF + value
		temp1 = Pop( &ErrVal );
		ErrVal |= setVar( (unsigned short)temp1, getVar((unsigned short)temp1, &ErrVal) + Pop( &ErrVal ) );
		break;

	case 0x2D3D: // '-=' -> varREF = varREF - value
		temp1 = Pop( &ErrVal );
		ErrVal |= setVar( (unsigned short)temp1, getVar((unsigned short)temp1, &ErrVal) - Pop( &ErrVal ) );
		break;

	case 0x2F3D: // '/=' -> varREF = varREF / value
		temp1 = Pop( &ErrVal );
		ErrVal |= setVar( (unsigned short)temp1, getVar((unsigned short)temp1, &ErrVal) / Pop( &ErrVal ) );
		break;

	case 0x3D3D: // '==' 
		if( Pop( &ErrVal ) == Pop( &ErrVal ) ) 
			ErrVal |= Push( 1 );
		else
			ErrVal |= Push( 0 );
		break;

	case 0x7C3D: // '|=' -> varREF = varREF | value
		temp1 = Pop( &ErrVal );
		ErrVal |= setVar( (unsigned short)temp1, getVar((unsigned short)temp1, &ErrVal) | Pop( &ErrVal ) );
		break;

	default: return ERROR_ILLEGAL_OPERATOR; 
	}

	return ErrVal;
}
