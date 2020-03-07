#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

int main(int argc, char *argv[]) {
	    
	int fd;
	int decequiv;
	size_t c;
	int counter;
	char *filename;
	char *str1;
	str1 = (char*)malloc(1500);
	memset(str1, '\0', sizeof(char)*1500);	
	char *str;
	str = (char*)malloc(9);
	char *token;
	char asciibuffer[2] = "0";
	char ascii[6] = "0";
	char parity[5];
	char *unprintables[] = {
		"NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
		" BS", " HT", " LF", " VT", " FF", " CR", " SO", " SI",
		"DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
		"CAN", " EM", "SUB", "ESC", " FS", " GS", " RS", " US",
		"space", "DEL"};
	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if(argc < 2) {
		printf("Error: No filename or binary value inputted.");
		return 0;
	}
	if(fd == -1) {
		if(strcmp(argv[1], "-") == 0){
			if (argc == 2){
				printf("Error: No filename or binary value inputted.");
				return 0;
			}
			strcat(str1, argv[2]);
			for(int i = 3; i < argc; i++){
				strcat(str1, " ");
				strcat(str1, argv[i]);
			}
		}
		else{
			strcat(str1, argv[1]);
			for(int i = 2; i < argc; i++){
				strcat(str1, " ");
				strcat(str1, argv[i]);
			}
		}
		printf("Original\tASCII\t\tDecimal\t\tParity\n");
		printf("--------\t--------\t--------\t--------\n");
		token = strtok(str1, " ");
		while(token != NULL) {
			while(strlen(token) > 0) {
				if (strlen(token) > 8){
					strncpy(str, token, 8);
					else{
						strncpy(str, token, strlen(token));
					}
					if(strlen(str) < 8) {
						for(size_t i = 0; i < (8 - strlen(token)); i++){
							strcat(str, "0");
						}
					}
					*(str + 8) = 0;
					for(c = 0, decequiv = 0, counter = 0; c < strlen(str); c++) {	
						if(str[strlen(str) - (c + 1)] == 49) {
							decequiv += 1*(pow(2,c));
							counter++;
						}
						if(decequiv >= 128) {
							decequiv -= 128;
							if(isascii(decequiv)){
								if(decequiv == 127){
									strncpy(ascii, unprintables[33], 4);
								}
								else if(decequiv == 32) {
									strncpy(ascii, unprintables[decequiv], 6);
								}
								else if(decequiv < 32){
									strncpy(ascii, unprintables[decequiv], 4);
								}
								else{
									asciibuffer[0] = decequiv;
									strncpy(ascii, &asciibuffer[0], 2);
								}
							}
							if(counter % 2 == 0){
								strncpy(parity, "EVEN", 5);
							}
							else{
								strncpy(parity, "ODD", 4);
							}
							printf("%s\t%s\t\t%d\t\t%s\n", str, ascii, decequiv, parity);
							memset(ascii, '\0', sizeof(char)*6);
							if(strlen(token) > 8){
								token = token + 8;
							}
							else{
								token = token + strlen(token);
							}
							memset(str,0,8*sizeof(str[0]));
						}
						token = strtok(NULL, " ");
					}
				}
				else{
					read(fd, str1, 1500);
					token = strtok(str1, " ");
					printf("Original\tASCII\t\tDecimal\t\tParity\n");
					printf("--------\t--------\t--------\t--------\n");
					while(token != NULL) {
						while(strlen(token) > 0) {
							if (strlen(token) > 8){
								strncpy(str, token, 8);
							}
							else{
								strncpy(str, token, strlen(token));
							}
							if(strlen(str) < 8) {
								for(size_t i = 0; i < (8 - strlen(token)); i++){
									strcat(str, "0");
								}
								*(str + 8) = 0;
								for(c = 0, decequiv = 0, counter = 0; c < strlen(str); c++) {	
									if(str[strlen(str) - (c + 1)] == 49) {
										decequiv += 1*(pow(2,c));
										counter++;
									}
								}
								if(decequiv >= 128) {
									decequiv -= 128;
								}
								if(isascii(decequiv)){
									if(decequiv == 127){
										strncpy(ascii, unprintables[33], 4);
									}
									else if(decequiv == 32) {
										strncpy(ascii, unprintables[decequiv], 6);
									}
									else if(decequiv < 32){
										strncpy(ascii, unprintables[decequiv], 4);
									}
									else{
										asciibuffer[0] = decequiv;
										strncpy(ascii, &asciibuffer[0], 2);
									}
								}
								if(counter % 2 == 0) {
									strncpy(parity, "EVEN", 5);
								}
								else{
									strncpy(parity, "ODD", 4);
								}
								printf("%s\t%s\t\t%d\t\t%s\n", str, ascii, decequiv, parity);
								if(strlen(token) > 8){
									token = token + 8;
								}
								else{
									token = token + strlen(token);
								}
								memset(str,0,8*sizeof(str[0]));
							}
							token = strtok(NULL, " ");
						}
					}
					free(str1);
					free(str);
					return 0;
				}
