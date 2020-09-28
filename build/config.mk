# Define root directory for the project
ROOT  := $(CURDIR)
SHELL := /bin/bash

# Define build system directory
BUILD_SYSTEM := build

# Define all main directories for the project
INCLUDE_DIR   := include
SOURCE_DIR    := src
OBJECT_DIR    := obj
TEST_DIR      := tests

# Set directory for all files which will be generated or builded
OUT_DIR          := $(ROOT)/out
TEST_OUT_DIR     := $(OUT_DIR)/$(TEST_DIR)
OBJECT_OUT_DIR   := $(OUT_DIR)/$(OBJECT_DIR)

ENGINE_LIB_NAME     := libglobalengine.a
ENGINE_LIB_LOCATION := $(OUT_DIR)

QUIET := @

CLEAR_VARS := $(BUILD_SYSTEM)/clear_variables.mk
BUILD_TEST := $(BUILD_SYSTEM)/test.mk
BUILD_STATIC_LIBRARY := $(BUILD_SYSTEM)/static_library.mk

# Define colors escape codes for pretty format output
ESC_BOLD     := \033[1m
ESC_TARGET   := \033[1;35m
ESC_OK       := \033[1;32m
ESC_ERROR    := \033[1;31m
ESC_WARNING  := \033[0;33m
ESC_RESET    := \033[0m

# Define string messages needed for pretty format output
SUCCESS_MESSAGE      := "[SUCCESS]"
ERROR_MESSAGE        := "[ERROR]"
WARNING_MESSAGE      := "[WARNING]"
COMPILATION_MESSAGE  := "Compiling"

# TODO: Not used yet
#ARCHIVATION_MESSAGE  := "Archiving"
