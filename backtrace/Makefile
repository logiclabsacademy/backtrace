# Description: Hide a program stacktrace.
# Author: Nnamdi Michael Okpala
# Project Name: Backtrace

CC = gcc
CFLAGS := -fPIC -Wall -Werror -Wpedantic -std=c99 -g -I$(HEADERS) -MMD -lm
TFLAGS := -fPIC -Wall -Werror -Wpedantic -std=c99 -g -I$(HEADERS,$()) -MMD -lm

# Directories
SRC_DIR := .
OBJ_DIR := ./obj
LIB := ./lib
BIN := ./bin
TEST_DIR := ./tests
UNIT_TEST_DIR := $(TEST_DIR)/unit
INTEGRATION_TEST_DIR := $(TEST_DIR)/integration
CORE_DIR := ./core

SOURCES := $(wildcard $(SRC_DIR)/**/*.c $(SRC_DIR)/*.c)
HEADERS := $(wildcard $(SRC_DIR)/**/*.h)
OBJECTS := $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

UNIT_TEST_SOURCES := $(wildcard $(UNIT_TEST_DIR)/**/*.c $(UNIT_TEST_DIR)/*.c)
INTEGRATION_TEST_SOURCES := $(wildcard $(INTEGRATION_TEST_DIR)/**/*.c $(INTEGRATION_TEST_DIR)/*.c)

UNIT_TEST_OBJECTS := $(UNIT_TEST_SOURCES:$(UNIT_TEST_DIR)/%.c=$(OBJ_DIR)/unit/%.o)
INTEGRATION_TEST_OBJECTS := $(INTEGRATION_TEST_SOURCES:$(INTEGRATION_TEST_DIR)/%.c=$(OBJ_DIR)/integration/%.o)

# Executables
EXEC = $(BIN)/bt
UNIT_TEST_EXEC = $(BIN)/unit_tests
INTEGRATION_TEST_EXEC = $(BIN)/integration_tests

# Commands
MKDIR = mkdir -p
RM = rm -rf

ifeq ($(OS),Windows_NT)
	EXEC := $(EXEC).exe
	RM = @del
else
	RM = rm -rf
endif

all: $(EXEC) $(UNIT_TEST_EXEC) $(INTEGRATION_TEST_EXEC)

$(EXEC): $(OBJECTS) | $(HEADERS)
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -o $@ main.c $(OBJECTS)

$(UNIT_TEST_EXEC): $(UNIT_TEST_OBJECTS) $(OBJECTS) | $(HEADERS)
	$(MKDIR) $(dir $@)
	$(CC) $(TFLAGS) -o $@ $(UNIT_TEST_OBJECTS) $(OBJECTS)

$(INTEGRATION_TEST_EXEC): $(INTEGRATION_TEST_OBJECTS) $(OBJECTS) | $(HEADERS)
	$(MKDIR) $(dir $@)
	$(CC) $(TFLAGS) -o $@ $(INTEGRATION_TEST_OBJECTS) $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(MKDIR) $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/unit/%.o: $(UNIT_TEST_DIR)/%.c | $(OBJ_DIR)/unit
	$(MKDIR) $(dir $@)
	$(CC) -c $(TFLAGS) $< -o $@

$(OBJ_DIR)/integration/%.o: $(INTEGRATION_TEST_DIR)/%.c | $(OBJ_DIR)/integration
	$(MKDIR) $(dir $@)
	$(CC) -c $(TFLAGS) $< -o $@

$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

$(OBJ_DIR)/unit:
	$(MKDIR) $(OBJ_DIR)/unit

$(OBJ_DIR)/integration:
	$(MKDIR) $(OBJ_DIR)/integration

clean:
	$(RM) $(OBJECTS) $(UNIT_TEST_OBJECTS) $(INTEGRATION_TEST_OBJECTS) $(EXEC) $(UNIT_TEST_EXEC) $(INTEGRATION_TEST_EXEC) $(SOURCES:.c=.d) $(OBJECTS:.o=.d)

.PHONY: all clean test

test: $(UNIT_TEST_EXEC) $(INTEGRATION_TEST_EXEC)
	$(UNIT_TEST_EXEC)
	$(INTEGRATION_TEST_EXEC)

-include $(OBJECTS:.o:.d)
-include $(SOURCES:.c:.d)
