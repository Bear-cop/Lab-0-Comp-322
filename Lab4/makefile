#Ricardo Carrillo
#LAB4 - RICE RICE AND RICE
#05/07/2020

EXECUTABLES = dining-p
SRC = dining-p.c
OBJ = dining-p.o

# The CC and CFLAGS variables are defined to ensure I'm using the native compiler and
# that the correct command-line options are set
CC = gcc
CFLAGS = -g -Wall -Wextra

# Here is my default target for the Makefile.  When I type make, this first target will
# be created. I.e., all the executables
all: $(EXECUTABLES)

dining-p: $(EXECUTABLES)

# On the following lines (which _must_ start with a tab), are the commands I need to type -- 
# each time my source file is modified.
$(EXECUTABLES): $(SRC)
	$(CC) $(CFLAGS) -lpthread -c $(SRC)
	$(CC) $(CFLAGS) -lpthread -o $@ $(OBJ)

# By convention, I always have a target called
# "clean" that I used to define all temporary
# or intermediates.
clean:
	rm -f $(EXECUTABLES) $(OBJ) *~
