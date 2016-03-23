# ------------------------------------------------
# Generic Generate Makefile to compiler CGI
#
# Author: yangsheng1107@gmail.com
# Date  : 2016-02-23
#
# Changelog :
#   0.01 - first version
# ------------------------------------------------

# project name (generate executable with this name)
TARGET=demo.cgi
CFLAGS  = -c -O2 -Wall
LDFLAGS =
CC = gcc 

#source
C_FILES := $(wildcard *.c)
OBJ_FILES := $(addprefix , $(C_FILES:.c=.o))

.PHONY : clean all

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(LDFLAGS) $(OBJ_FILES) -o $@

.c.o:
	$(CC) $(DEBUG) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_FILES)
	rm -rf $(TARGET)

