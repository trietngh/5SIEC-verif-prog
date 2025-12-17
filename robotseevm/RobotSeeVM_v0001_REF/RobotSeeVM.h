#ifndef ROBOTSEEVMH
#define ROBOTSEEVMH
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
#include "ports.h"

#define ERRORTYPE	unsigned short

typedef long DATATYPE;

// StringFifo
void initStringFIFO( unsigned char* pStringFifo, unsigned short CallStringFIFODepth );
unsigned char* GetString( void );
unsigned short StringPush( unsigned long LongParam );

// CallStack 
void initCallStack( unsigned long* pCallStack, unsigned short CallStackDepth );
ERRORTYPE Push( DATATYPE data );
DATATYPE Pop( ERRORTYPE* error );
DATATYPE Top( ERRORTYPE* error );
void ResetCallStack( void );

// RamVar
void initRAMArray( unsigned long* pRamVar, unsigned short MaxVars );
ERRORTYPE setVar( unsigned short Reference, DATATYPE Data );
DATATYPE getVar( unsigned short Reference, ERRORTYPE *error );

// Operator
ERRORTYPE Operator( unsigned short parameter );

// Keyword
ERRORTYPE Keyword( unsigned short Parameter );

#ifdef DEBUGGER
unsigned char DebugEnable( void );
void DebuggerEOhook( unsigned long, PROGRAMCOUNTER*, unsigned char*, unsigned long* );
#endif


// State Machine
ERRORTYPE CallBackGetProgramByte( unsigned long Address, unsigned char *PipeLine );
void CallBackConsoleOut( char* data );
void CallBackErrorOut( char* data );
void CallBackDebugOut( char* data );
void CallBackReset( void );
void initHardware( void );
void initFileSystem( void );
void StartVM( unsigned long*,  unsigned short, unsigned char*, unsigned short, unsigned long*, unsigned short );


typedef enum        { 
						RESET,
						DECODEOPERAND,
						GETBYTEPARAM,
						GETSHORTPARAM1,
						GETSHORTPARAM2,
						GETLONGPARAM1,
						GETLONGPARAM2,
						GETLONGPARAM3,
						GETLONGPARAM4,
						EXECUTEOPERAND
					} VMSTATES;


#define ERROR_STRINGFIFO_OVERRUN		0x0001
#define ERROR_CALLSTACK_OVERRUN			0x0002
#define ERROR_CALLSTACK_UNDERRUN		0x0004
#define ERROR_ILLEGAL_OPERATOR			0x0008
#define ERROR_REFERENCE_OUTOFRANGE		0x0010
#define ERROR_PROGRAM_FETCH				0x0020
#define ERROR_ILLEGAL_INSTRUCTION		0x0040


#endif

