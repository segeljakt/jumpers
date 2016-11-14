###############################################################################
#     File Name           :     makefile                                      #
#     Created By          :     Klas Segeljakt                                #
#     Creation Date       :     [2016-10-23 13:10]                            #
#     Last Modified       :     [2016-11-14 21:08]                     		  #
#     Description         :     Makefile of terminal-mario.                   #
###############################################################################
PROJ_DIR = $(shell pwd)
BUILD = $(PROJ_DIR)/build
BIN = $(PROJ_DIR)/bin
GCC = /usr/local/bin/gcc
#------------------------------------------------------------------------------
BIN = jump-squad
#------------------------------------------------------------------------------
TARGET = $(PROJ_DIR)/bin/$(BIN)
#------------------------------------------------------------------------------
SRC = $(shell find $(PROJ_DIR)/src -name "*.c")
SRC := $(filter-out $(PROJ_DIR)/src/state/online%, $(SRC))
SRC := $(filter-out $(PROJ_DIR)/src/state/input/readkey%, $(SRC))
#------------------------------------------------------------------------------
FLAGS = -Wall                           # Show all warnings
FLAGS += -lncurses                      # Link ncurses library
FLAGS += -framework AppKit
FLAGS += -fms-extensions                # Anonymous struct
#FLAGS += -Ofast                        # Full optimization
FLAGS += -I $(PROJ_DIR)                 # Set project directory
#------------------------------------------------------------------------------
CALL = gcc $(SRC) $(FLAGS)
#------------------------------------------------------------------------------
all: $(SRC)
	$(CALL)
debug: $(SRC)
	$(CALL) -g
	gdb bin/jump-squad
run:
	./levels/font/font.applescript
	./bin/$(BIN)
	./levels/font/font.applescript
#------------------------------------------------------------------------------
clean:
	rm $(TARGET)
