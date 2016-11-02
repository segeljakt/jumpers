###############################################################################
#     File Name           :     makefile                                      #
#     Created By          :     Klas Segeljakt                                #
#     Creation Date       :     [2016-10-23 13:10]                            #
#     Last Modified       :     [2016-10-31 20:52]                     		  #
#     Description         :     Makefile of terminal-mario.                   #
###############################################################################
CC = /usr/bin/gcc
#------------------------------------------------------------------------------
BIN = terminal-mario
#------------------------------------------------------------------------------
PROJ_DIR = $(shell pwd)
#------------------------------------------------------------------------------
TARGET = $(PROJ_DIR)/bin/$(BIN)
#------------------------------------------------------------------------------
SRC = $(shell find $(PROJ_DIR)/src -name "*.c")
#------------------------------------------------------------------------------
FLAGS += -Wall                          # Show all warnings
FLAGS += -lncurses                      # Link ncurses library
FLAGS += -framework Carbon 				# Carbon framework
FLAGS += -Ofast                         # Full optimization
FLAGS += -I $(PROJ_DIR)                 # Set project directory
FLAGS += -o $(TARGET)                   # Output file
#------------------------------------------------------------------------------
CALL = $(CC) $(SRC) $(FLAGS)
#------------------------------------------------------------------------------
all: $(SRC)
	$(CALL)
run:
	./levels/font/font.applescript
	./bin/terminal-mario
	./levels/font/font.applescript
#------------------------------------------------------------------------------
clean:
	rm $(TARGET)
