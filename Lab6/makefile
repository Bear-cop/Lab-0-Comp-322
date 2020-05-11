#Ricardo Carrillo - Wack A Mole
#05/09/2020

EXECUTABLES = spiritd moles

FILE_1 = spiritd
SRC_1 = spiritd.c
OBJ_1 = spiritd.o

FILE_2 = moles
SRC_2 = moles.c
OBJ_2 = moles.o

CC = gcc
CFLAGS = -g

all: $(EXECUTABLES)
$(EXECUTABLES):
spiritd:
	$(CC) $(CFLAGS) -c $(SRC_1) -Wall -Wextra
	$(CC) $(CFLAGS) -o $(FILE_1) $(OBJ_1)
moles:
	$(CC) $(CFLAGS) -c $(SRC_2) -Wall -Wextra
	$(CC) $(CFLAGS) -o $(FILE_2) $(OBJ_2)

clean:
	rm -f $(EXECUTABLES) $(OBJ_1) $(OBJ_2) *~
