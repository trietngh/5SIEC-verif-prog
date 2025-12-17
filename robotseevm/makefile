#
# This file is part of the RobotVisionToolkit/RobotSee/RobotSeeVM project.
#
# Copyright (C) 2004-2010 Eric Gregori <eric.gregori@emgrobotics.com>   www.EMGRobotics.com
#
# 	RobotVisionToolkit/RobotSee by Eric Gregori - www.EMGRobotics.com
#	This program is free software: you can redistribute it and/or modify
#	it under the terms of the GNU General Public License as published by
#	the Free Software Foundation, either version 3 of the License, or
#	(at your option) any later version.
#
#	This program is distributed in the hope that it will be useful,
#	but WITHOUT ANY WARRANTY; without even the implied warranty of
#	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#	GNU General Public License for more details.
#
#	You should have received a copy of the GNU General Public License
#	along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
#	RobotSee by Eric Gregori - www.EMGRobotics.com
#	RobotSee is a basic/C-like interpreter for Robotics and Home Automation
#	The language looks like C, but is as simple as basic.
#	For more information goto - www.RobotSee.com

PROJECT=RobotSeeVM_v0001
CC=gcc
GUI=frama-c-gui
FRAMA=frama-c
CFLAGS=-c -Wall -DLINUX -L$(PROJECT) 
LDFLAGS= 
SOURCES= \
	$(PROJECT)/CallStack.c\
	$(PROJECT)/ExecutionEngine.c\
	$(PROJECT)/InitHardware.c\
	$(PROJECT)/Keyword.c\
	$(PROJECT)/Operator.c\
	$(PROJECT)/ports.c\
	$(PROJECT)/RamVar.c\
	$(PROJECT)/RobotSeeVM_Debugger.c\
	$(PROJECT)/StringFifo.c

OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=RobotSeeVM

all:	$(SOURCES)	$(EXECUTABLE)
clean:
	rm -rf *.o RobotSeeVM

$(EXECUTABLE):	$(OBJECTS)
	$(CC)	$(LDFLAGS)	$(OBJECTS) -o $@

.c.o:
	$(CC)	$(CFLAGS)	$< -o $@

val	: $(SOURCES) frama-c/malloc.c
	$(GUI) -val -pp-annot -cpp-command "gcc -C -E -DLINUX -LRobotSeeVM_v0001 -DFRAMA_C_MALLOC_HEAP"  $+
	
valb	: $(SOURCES) frama-c/malloc.c
	$(FRAMA) -val -pp-annot -cpp-command "gcc -C -E -DLINUX -LRobotSeeVM_v0001 -DFRAMA_C_MALLOC_HEAP"  $+
	