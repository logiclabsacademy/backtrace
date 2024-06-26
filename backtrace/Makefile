# Description: Hide a program stacktrace.
# Author: Nnamdi Michael Okpala
# Project Name: Backtrace

CC=gcc
CFLAGS := -fPIC -Wall -Werror -Wpedantic -std=c99  -I$(LIB_DIR) -MMD 

ifeq ($(DEBUG),1)
	CFLAGS += -g
else
	CFLAGS += -O2
	
# Directories
SRC_DIR:=.
OBJ_DIR=./obj
LIB=./lib
BIN=./bin

SOURCES:=$(wildcard $(SRC_DIR)/**/*.c)
OBJECTS:=$(SOURCES:%.h=$(OBJ_DIR)/%.o)
HEADERS:=$(wildcard $(SRC_DIR)/**/*.h)

# Executable
EXEC=$(BIN)/bt

# Commands
MKDIR=mkdir 
RM=rm -rf

ifeq ($(OS),Windows_NT)
	EXEC:=$(EXEC).exe
	RM= @del
	CFLAGS += -DWIN32
else 
	RM=rm -rf
	CFLAGS += -DUNIX
endif


all: $(EXEC)	

$(EXEC): $(OBJECTS)  | $(HEADERS)
# Create the directory if it does not exist
	$(CC) $(CFLAGS) -o $@ main.c $< 

$(OBJECTS):
# Create the directory if it does not exist
	$(MKDIR) $(dir $@)
	

$(OBJ_DIR)/%.o: %.c
	$(MKDIR) $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@


clean:
	$(RM) $(OBJECTS) $(EXEC) $(SOURCES:.c=.d) $(OBJECTS:.o=.d)

.PHONY: all clean

-include $(OBJECTS:.o=.d)
-include $(SOURCES:.c=.d)
