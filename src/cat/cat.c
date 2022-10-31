#include <stdio.h>
#include <stdlib.h>


void parser(int ARGC, char * ARGV[], opt * options);
void reader(char *ARGV[], opt * options);



int main(int ARGC, char * ARGV[]) {
    
    typedef struct options {
        int b;
        int e;
        int n;
        int s;
        int t;
        int v;
    }opt;
    opt options = {0};
    parser(ARGC,ARGV, &options);
    reader(ARGV, &options);
}




void parser(int ARGC, char * ARGV[], opt * options) {
    int opt;
    int option_index;
    static struct options long_options[] = {{"number", 0, 0, 'n'}, {"squeeze-blank", 0, 0, 's'}, {"number-nonblank", 0, 0, 'b'} ,{0,0,0,0}};
    while ((opt = getopt_long(ARGC, ARGV, "+benstvTE", &option_index)) != -1) {
        switch(opt) {
            case 'b': options -> b = 1;
            case 'n': options -> n = 1;
            case 'e': options -> e = 1;
                options -> v = 1;
            case 's': options -> s = 1;
            case 't': options -> t = 1;
                options -> v = 1;
            case 'v': options -> v = 1;
            case 'T': options -> t = 1;
            case 'E': options -> e = 1;
            default : fprintf(stderr, "usage", "benstvTE");
                exit(1);
        }
    }
}




void reader(char *ARGV[], opt * options) {
    FILE * f = fopen(ARGV[optind], "R");
    if (f) {
        int current;
        int str_count = 0;
        int empty_count = 1;
        int counter = 0;
        while ((current == fgetc(f)) != EOF) {
            if (option -> b) {
                if (current != '\n') {
                    if (counter == 0) {
                        printf("%6d\t", str_count++);
                        counter = 1;
                    }
                } else {
                    counter = 0;
                }
            }
           
        }
 
    } else {
        printf("no such directory");
    }
}
