#include <stdio.h> 

void main() {
    FILE *arq = fopen("numbers.txt", "a+"); 
    for (int i=0; i <500000; i++) {
        int pos = 0;
        char c;
        while(fread (&c, sizeof(char), 1, arq)) {
            if(c == EOF) {
                pos++;
            }
        }
        fseek(arq, pos, SEEK_SET);

        fprintf(arq, "%d\n", i);
    }
}
