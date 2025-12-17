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

#define PARM0	(unsigned char)0x00
#define PARM1	(unsigned char)0x40
#define PARM2	(unsigned char)0x80
#define PARM4	(unsigned char)0xC0


// ('J'-0x20)  Jump Always to address specified in parameter
// ('?'-0x20)  Jump if stack pop is 0 to address specified in parameter
// ('N'-0x20)  Jump if stack pop is NOT 0 to address specified in parameter
// ('F'-0x20)  Call keyword specified in parameter ( keyword parameters are on call stack )
// ('O'-0x20)  Call operator specified in parameter ( basically same as keyword )
// ('D'-0x20)  Push VALUE of Constant on stack
// ('V'-0x20)  Push VALUE of variable on stack
// ('C'-0x20)  Copy top of stack, and push on stack
// ('S'-0x20)  Push VALUE on string stack
// ('T'-0x20)  Top of stack into variable referernced by parameter
// ('P'-0x20)  Pop stack into variable referernced by parameter
// ('U'-0x20)  Pop stack, dump data
// ('#'-0x20)  noop, used for Line Number when debugging 

//('F'-0x20)
#define FUNC1		(unsigned char)0x26+PARM1
#define FUNC2		(unsigned char)0x26+PARM2

// ('J'-0x20)
#define JUMP0		(unsigned char)0x2A+PARM0
#define JUMP1		(unsigned char)0x2A+PARM1
#define JUMP2		(unsigned char)0x2A+PARM2
#define JUMP4		(unsigned char)0x2A+PARM4

// ('U'-0x20)
#define DUMP		(unsigned char)0x35+PARM0

// ('D'-0x20)
#define PUSHC1		(unsigned char)0x24+PARM1
#define PUSHC2		(unsigned char)0x24+PARM2
#define PUSHC4		(unsigned char)0x24+PARM4

// ('S'-0x20)
#define STRING		(unsigned char)0x33+PARM1

// ('P'-0x20)
#define POPV1		(unsigned char)0x30+PARM1
#define POPV2		(unsigned char)0x30+PARM2
#define POPV4		(unsigned char)0x30+PARM4

// ('V'-0x20)
#define PUSHV1		(unsigned char)0x36+PARM1
#define PUSHV2		(unsigned char)0x36+PARM2
#define PUSHV4		(unsigned char)0x36+PARM4

// ('O'-0x20)
#define OPER1		(unsigned char)0x2F+PARM1
#define OPER2		(unsigned char)0x2F+PARM2
#define OPER4		(unsigned char)0x2F+PARM4

// ('?'-0x20)
#define JUMPZ1		(unsigned char)0x1F+PARM1		
#define JUMPZ2		(unsigned char)0x1F+PARM2		
#define JUMPZ4		(unsigned char)0x1F+PARM4	

// ('N'-0x20)
#define JUMPNZ1		(unsigned char)0x2E+PARM1
#define JUMPNZ2		(unsigned char)0x2E+PARM2
#define JUMPNZ4		(unsigned char)0x2E+PARM4

// ('C'-0x20)
// ('T'-0x20)



