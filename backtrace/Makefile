# Description: Hide a program stacktrace.
# Author: Nnamdi Michael Okpala
# Project Name: Backtrace

CC=gcc
CFLAGS := -fPIC -Wall -Werror -Wpedantic -std=c2x -g -I$(LIB_DIR) -MMD 
LDFLAGS := -shared 

# Directories
SRC_DIR:=.
OBJ_DIR=obj
LIB=lib
BIN=bin

SOURCES:=$(wildcard $(SRC_DIR)/**/*.c)
OBJECTS:=$(SOURCES:%.h=$(OBJ_DIR)/%.o)
HEADERS:=$(SOURCES:%.h)

# Executable
EXEC=$(BIN)\backtrace

ifdef OS
MKDIR=@mkdir
RM = @del /Q
else
MKDIR=@mkdir -p
RM = @rm -f
endif


all: $(EXEC)	

$(EXEC): $(OBJECTS) | $(HEADERS)
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -o $@ main.c $(LDFLAGS)

$(OBJECTS): $(SOURCES) | $(HEADERS)
	$(MKDIR) $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@


clean:
	$(RM) $(OBJECTS) $(EXEC) $(SOURCES:.c=.d) $(OBJECTS:.o=.d)

.PHONY: all clean

-include $(OBJECTS:.o=.d)
-include $(SOURCES:.c=.d)
