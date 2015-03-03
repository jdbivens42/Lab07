AutomatedMakefile = am
CC = g++

FILES = Problem22_1.o RecursiveIntegration.o RombergIntegration.o
EXECUTABLE = Lab07.exe

PROJECT_PATH = $(PROJECT_DIR)

INC_DIRS = -I$(PROJECT_PATH)/CSC2110/
LIB_DIRS = -L$(PROJECT_PATH)/CSC2110/
LIBS = -lCSC2110

COMPILE = $(CC) $(INC_DIRS) -c
LINK = $(CC) $(LIB_DIRS) -o

all: Project

Project: 		$(FILES)
				$(LINK) $(EXECUTABLE) $(FILES) $(LIBS)

Problem22_1.o:		 Problem22_1.h Problem22_1.cpp
					 $(COMPILE) -D DEBUG=0 Problem22_1.cpp
				
RecursiveIntegration.o: RecursiveIntegration.cpp RecursiveIntegration.h
						$(COMPILE) -D DEBUG=0 RecursiveIntegration.cpp
						
RombergIntegration.o:	RecursiveIntegration.o RombergIntegration.cpp QueueLinked.h 
						$(COMPILE) -D DEBUG=1 RombergIntegration.cpp
