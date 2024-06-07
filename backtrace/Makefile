# Description: Hide a program stacktrace.
# Author: Nnamdi Michael Okpala
# Project Name: Backtrace

CC = gcc
CFLAGS := -fPIC -Wall -Werror -Wpedantic -std=c99 -g -I$(HEADERS) -MMD -lm
TFLAGS := -fPIC -Wall -Werror -Wpedantic -std=c99 -g -I$(HEADERS) -MMD -lm
# Directories
SRC_DIR := .
OBJ_DIR := ./obj
LIB := ./lib
BIN := ./bin
TEST_DIR := ./tests
CORE_DIR := ./core/wrangler

SOURCES := $(wildcard $(SRC_DIR)/**/*.c)
TEST_SOURCES := $(wildcard $(TEST_DIR)/**/*.test.c)
HEADERS := $(wildcard $(SRC_DIR)/**/*.h)
OBJECTS := $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TEST_OBJECTS := $(TEST_SOURCES:$(TEST_DIR)/%.test.c=$(OBJ_DIR)/%.test.o)

# Executables
EXEC = $(BIN)/bt
TEST_EXEC = $(BIN)/bt.test

# Commands
MKDIR = mkdir -p
RM = rm -rf

ifeq ($(OS),Windows_NT)
	EXEC := $(EXEC).exe
	RM = @del
else
	RM = rm -rf
endif

all: $(EXEC) $(TEST_EXEC)

$(EXEC): $(OBJECTS) | $(HEADERS)
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -o $@ main.c $(OBJECTS)

$(TEST_EXEC): $(TEST_OBJECTS) $(OBJECTS) | $(HEADERS)
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -o $@ $(TEST_DIR)/wrangler.test.c $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(MKDIR) $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/%.test.o: $(TEST_DIR)/%.test.c | $(OBJ_DIR)
	$(MKDIR) $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@
 
$(OBJ_DIR): 
	$(MKDIR) $(OBJ_DIR)

clean:
	$(RM) $(OBJECTS) $(TEST_OBJECTS) $(EXEC) $(TEST_EXEC) $(SOURCES:.c=.d) $(OBJECTS:.o=.d)

.PHONY: all clean

-include $(OBJECTS:.o=.d)
-include $(SOURCES:.c=.d)
