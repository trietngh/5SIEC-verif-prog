#include "assembler.h"

const unsigned char program[] = {			//	cmd,						parm
											//-----------------------------------------------------------------
											PUSHC1,	(unsigned char)100,
											POPV1,	(unsigned char)0,					// var[0] = 100
											//-----------------------------------------------------------------
											PUSHC1,	(unsigned char)7,
											POPV1,	(unsigned char)1,					// var[1] = 7
											//-----------------------------------------------------------------
											FUNC1,	(unsigned char)KEYWORD_VERSION,		// version()
											DUMP,						
											//-----------------------------------------------------------------
											PUSHC2,	(unsigned char)0x01,(unsigned char)0xFF,// loop:
											FUNC1,	(unsigned char)KEYWORD_DELAY,		// Delay( 0x04FF )
											DUMP,
											//-----------------------------------------------------------------
											STRING, (unsigned char)'H',					
											STRING, (unsigned char)'E',
											STRING, (unsigned char)'L',
											STRING, (unsigned char)'L',
											STRING, (unsigned char)'O',
											STRING, (unsigned char)0x0D, 
											STRING,	(unsigned char)0x0A, 
											STRING,	(unsigned char)0x00, 
											FUNC1,	(unsigned char)KEYWORD_PRINTS,		// print( "HELLO\n" )
											DUMP,
											//-----------------------------------------------------------------
											PUSHV1, (unsigned char)0,
											FUNC1,	(unsigned char)KEYWORD_PRINTVD,		// print( var[0] )
											DUMP,
											//-----------------------------------------------------------------
											PUSHC1,	(unsigned char)10,				    // value2 = 10
											PUSHV1, (unsigned char)0,					// value1 = var[0]
											PUSHC1, (unsigned char)1,					// reference to var[1]
											FUNC1,	(unsigned char)KEYWORD_TEST,		// KEYWORD_TEST:		// ( reference, value1, value2 ) returns sum
											POPV1,	(unsigned char)1,					// var[1] =
											//-----------------------------------------------------------------
											PUSHC1,	(unsigned char)1,
											PUSHV1, (unsigned char)0,
											OPER1,  (unsigned char)'-',					// var[0]-1
											POPV1,	(unsigned char)0,					// var[0] =
											//-----------------------------------------------------------------											
											PUSHC1,	(unsigned char)50,
											PUSHV1, (unsigned char)0,
											OPER2,  (unsigned char)'=', (unsigned char)'=', // if( var[0] == 50 ) push (1)
											JUMPZ1, (unsigned char)11,						
											JUMP1,  (unsigned char)0,						// if( var[0] == 50 ) jump(0)
											//-----------------------------------------------------------------
										//	PUSHV1, (unsigned char)0,
										//	JUMPNZ1,(unsigned char)11,					// if( var[0] == 0 ) jump loop
										//	PUSHC1,	(unsigned char)100,
										//	POPV1,	(unsigned char)0,					// var[0] = 100
											//-----------------------------------------------------------------
											JUMP1,	(unsigned char)11					// goto( loop )								
									};