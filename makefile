###############################################################################
#     File Name           :     makefile                                      #
#     Created By          :     Klas Segeljakt                                #
#     Creation Date       :     [2016-10-23 13:10]                            #
#     Last Modified       :     [2016-11-03 19:16]                     		  #
#     Description         :     Makefile of terminal-mario.                   #
###############################################################################
CC = /usr/bin/gcc
#------------------------------------------------------------------------------
BIN = jump-squad
#------------------------------------------------------------------------------
PROJ_DIR = $(shell pwd)
#------------------------------------------------------------------------------
TARGET = $(PROJ_DIR)/bin/$(BIN)
#------------------------------------------------------------------------------
SRC = $(shell find $(PROJ_DIR)/src -name "*.c")
#------------------------------------------------------------------------------
#FLAGS += -Wall                          # Show all warnings
FLAGS += -lncurses                      # Link ncurses library
FLAGS += -framework AppKit
FLAGS += -Ofast                         # Full optimization
FLAGS += -I $(PROJ_DIR)                 # Set project directory
FLAGS += -o $(TARGET)                   # Output file
#------------------------------------------------------------------------------
CALL = $(CC) $(SRC) $(FLAGS)
#------------------------------------------------------------------------------
all: $(SRC)
	$(CALL)
debug:
	$(CALL) -g
run:
	./levels/font/font.applescript
	./bin/$(BIN)
	./levels/font/font.applescript
#------------------------------------------------------------------------------
clean:
	rm $(TARGET)
