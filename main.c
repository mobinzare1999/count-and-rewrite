#include <stdio.h>
#include <ctype.h>
#define input "input.txt"
#define output "output.txt"
int main() {
    FILE *fin,*fout;
    fin = fopen(input,"r");
    fout = fopen(output,"w");
    if(fin == NULL){
        return 0;
    }
    char ch,ch2;
    int i ,b,T = 1;
    ch = fgetc(fin);
    while(ch != EOF) {
        i = 0;
        while (i < 25 && ch != '\n'){
            i++;
            if (isdigit(ch)) {
                fputc('*', fout);
                ch = fgetc(fin);
            } else if (ispunct(ch)) {
                fputc(ch, fout);
                ch2 = fgetc(fin);
                if (ch2 == EOF){
                    break;
                }
                i++;
                if (ch == '!' || ch == '?' || ch == '.') {
                    while(ch2 == ' '){
                        fputc(ch2,fout);
                        ch2 = fgetc(fin);
                        i++;
                    }
                    if(ch2 == '\n'){
                        T = 0;
                        i--;
                        break;
                    }
                    if (isalpha(ch2)) {
                        if(islower(ch2)) {
                            fputc(' ', fout);
                            ch2 = ch2 - 32;
                            fputc(ch2, fout);
                            ch2 = fgetc(fin);
                            i++;
                        }
                    }
                }
                if(ch2 != '.' && ch2 != ',' && ch2 != ';' && ch2 != ':' && ch2 != '!' && ch2 != '?' && ch2 != 39 && ch2 != '\n' && ch2 != ' ' && ch2 != '(' && ch2 != ')'){
                    fputc(' ', fout);
                    i++;
                }
                while (ispunct(ch2)) {
                    fputc(ch2, fout);
                    ch2 = fgetc(fin);
                    i++;
                }
                ch = ch2;
                i--;
            }else{
                fputc(ch,fout);
                ch = fgetc(fin);
            }
        }
        b = i;
        while(i < 25){
            fputc(' ',fout);
            i++;
        }if(ch == '\n'){
            fprintf(fout,"| c:%d \n",b);
            ch = fgetc(fin);
        }else{
            fprintf(fout,"| c:%d \n",b);
        }
        if(ch2 == EOF){
            ch = ch2;
        }
        if (T == 0) {
            ch2 = fgetc(fin);
            if (ch2 >= 97 && ch2 <= 122) {
                ch2 = ch2 - 32;
                ch = ch2;
                T = 1;
            } else {
                ch = ch2;
            }
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
