#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define bool int

void DecodeText(char *num) {
	    printf("% 8s",num);
	        printf("% 8c",ConvertD(num));
		    printf("% 8d",ConvertD(num));
		        printf("% 8s", getParity(ConvertD(num)) ? "odd" : "even");
			    printf("\n");
}
int ConvertD(char *n) {
	    int convertD = 0, i = 0, remainder;
	        int count = atoi(n);
		    while (count != 0) {
			            remainder = count % 10;
				            count /= 10;
					            convertD += remainder * pow(2, i);
						            ++i;
							        }
		        return convertD;

}

bool getParity(unsigned int n) {
	    bool parity = 0;
	        while (n) {
			        parity = !parity;
				        n = n & (n - 1);
					    }
		    return parity;
}
int main(int argc, char** argv) {
	    char num[100];
	        char temp[10000];
		    
		    printf("Enter file name \n");
		        gets(temp);
			        printf("BINARY    ASCII   DECIMAL  PARITY\n");
				    FILE *fileL = fopen(temp, "r"); \

						      if (fileL == NULL) {\
							              printf("Could not find file\n");
								              exit(-1);
									          }
				        while (fscanf(fileL, "%s", & num) == 1) {
						        char buffer[9];
							        int length;
								        snprintf(buffer, 9, "%s", num);
									        length = strlen(buffer);

										        for (int i = length; i < 8; i++) {
												            buffer[i] = '0';
													            }
											      DecodeText(buffer);
											          }
}					   return (EXIT_SUCCESS);
