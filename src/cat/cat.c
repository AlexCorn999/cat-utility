#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

typedef struct options {
    int b;
    int e;
    int n;
    int s;
    int t;
    int v;
}opt;

void parser(int ARGC, char * ARGV[], opt * options);
void reader(char *ARGV[], opt * options);



int main(int ARGC, char * ARGV[]) {
    opt options = {0};                                      // зануление каждого поля структуры
    parser(ARGC,ARGV, &options);
    if(options.b == 1) {
        options.n = 0;
        reader(ARGV, &options);
    } else {
    reader(ARGV, &options);
    }
}




void parser(int ARGC, char * ARGV[], opt * options) {
    int opt;
    int option_index;
    
    static struct option long_options[] = {
        { "number", 0, 0, 'n'},
        { "squeeze-blank", 0,  0, 's'},
        { "number-nonblank", 0, 0, 'b'},
        {0,0,0,0}};
    
    while ((opt=getopt_long(ARGC, ARGV, "+benstvTE",long_options, &option_index)) != -1) {
        switch(opt) {
            case 'b': options -> b = 1;
                break;
            case 'n': options -> n = 1;
                break;
            case 'e': options -> e = 1;
                options -> v = 1;
                break;
            case 's': options -> s = 1;
                break;
            case 't': options -> t = 1;
                options -> v = 1;
                break;
            case 'v': options -> v = 1;
                break;
            case 'T': options -> t = 1;
                break;
            case 'E': options -> e = 1;
                break;
            default : fprintf(stderr, "usage: cat [-benstuv] [file ...]");
                exit(1);
        }
    }
}




void reader(char *ARGV[], opt * options) {
    
    FILE *f;
    f = fopen(ARGV[optind], "r");
    
    if (f) {
        char prev = '\n';
        char flag;
        char future;
        int q;
        char current;                                   // текуший символ
        int str_count = 1;                              // номер строки
        int empty_count = 1;
        int counter = 0;                                // счетчик строк обнуляет строку
        
        
        while ((current = fgetc(f)) != EOF) {
            
            if (options -> b == 1) {
                if (current != '\n') {
                    if (counter == 0) {
                        printf("%6d\t", str_count++);
                        counter = 1;
                    }
                } else {
                    counter = 0;
                }
            }
            
            
            if (options -> n == 1) {
                if (prev == '\n') {
                        printf("%6d\t", str_count++);
                } else {
                    
                }
            }
            
            
            if (options -> s == 1) {
                if (prev == '\n') {
                    char next = fgetc(f);
                    ungetc(next, f);
                    if (next == '\n') {
                        continue;
                    }
                } else {
                    
                }
            }
            
            
            if (options -> v == 1) {
                if ((prev >= 0 && prev <= 31 && prev != '\n' && prev != '\t') || prev == 127) {
                    if (prev >= 0 && prev <= 31 && prev != '\n' && prev != '\t') {
                        prev = prev + 64;
                        q = 1;
                    }
                    if (prev == 127) {
                        prev = '?';
                        q = 1;
                    }
                } else {
                    q = 0;
                }
                
                
                
                
                
                
            }
            
            
            if (q == 1) {
                printf("^%c", prev);
                prev = current;
            } else {
                putchar(current);
                prev = current;
            }
    
            if (options -> v != 1) {
                putchar(current);
                prev = current;
            } else {

            }
            

            
            
            
            
            
        }
    } else {
        printf("No such file or directory");
    }
    
    
    fclose(f);
}
