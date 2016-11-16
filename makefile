###############################################################################
#     File Name           :     makefile                                      #
#     Created By          :     Klas Segeljakt                                #
#     Creation Date       :     [2016-10-23 13:10]                            #
#     Last Modified       :     [2016-11-16 20:32]                     		  #
#     Description         :     Makefile of terminal-mario.                   #
###############################################################################
NAME = mario
PROJ_DIR = $(shell pwd)
BUILD = $(PROJ_DIR)/build
BIN = $(PROJ_DIR)/bin
CC = /usr/local/bin/gcc
#------------------------------------------------------------------------------
TARGET = $(BIN)/$(NAME)
#------------------------------------------------------------------------------
SRC = $(shell find $(PROJ_DIR)/src -name "*.c")
SRC += $(shell find $(PROJ_DIR)/debug -name "*.c")
SRC := $(filter-out $(PROJ_DIR)/src/state/online%, $(SRC))
SRC := $(filter-out $(PROJ_DIR)/src/state/input/readkey%, $(SRC))
#------------------------------------------------------------------------------
FLAGS = -Wall                           # Show all warnings
FLAGS += -lncurses                      # Link ncurses library
FLAGS += -framework AppKit
FLAGS += -fms-extensions                # Anonymous struct
#FLAGS += -Ofast                        # Full optimization
FLAGS += -I $(PROJ_DIR)                 # Set project directory
FLAGS += build/readkey.o
FLAGS += -o $(TARGET)
#FLAGS += --enable-checking -g -v -da -Q
#------------------------------------------------------------------------------
CALL = $(CC) $(SRC) $(FLAGS)
#------------------------------------------------------------------------------
all: $(SRC)
	$(CALL)
debug: $(SRC)
	$(CALL) -g -DDEBUG
	gdb $(TARGET)
run:
	./levels/font/font.applescript
	$(TARGET)
	./levels/font/font.applescript
#------------------------------------------------------------------------------
clean:
	rm $(TARGET)
