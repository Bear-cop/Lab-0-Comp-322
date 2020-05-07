#Ricardo Carrillo 
#Makefile for Lab 5 -  page calculation
#05/06/2020

CC=gcc
CFLAGS=-g -Wall -Wextra

all: offsetCalc

catcher: offsetCalc.c
        $(CC) $(CFLAGS) -c offsetCalc.c
	      $(CC) $(CFLAGS) -o catcher offsetCalc.o -lm
	
clean:
	rm -f offsetCalc offsetCalc.o *~
