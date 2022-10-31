#include <stdio.h>
#include <string.h>

struct options {
    int OPT_B;
    int OPT_E;
    int OPT_N;
    int OPT_S;
    int OPT_T;
} opt;

void init(struct options opt);
void parser(int ARGC, char ** ARGV, int error);
void reader(int ARGC, char ** ARGV, int error);






int main(int ARGC, char ** ARGV) {
    int error = 0;
     if (ARGC > 1) {
        init(opt);
        parser(int ARGC, char ** ARGV, error);
        reader(int ARGC, char ** ARGV, error);

        
        
    } else {
        printf("ERROR");
    }
    
    return 0;
}



void init(struct options opt) {
    opt.OPT_B = 0;
    opt.OPT_E = 0;
    opt.OPT_N = 0;
    opt.OPT_S = 0;
    opt.OPT_T = 0;
}

void parser(int ARGC, char ** ARGV, int error) {
    int count = 1;
    while (ARGV) {
        if (ARGV[count][0] == '-') {
                for(int i = 1; i < strlen(ARGV[count]); i++) {
                    if (ARGV[count][i] == 'b') {
                        opt.OPT_B = 1;
                    } if (ARGV[count][i] == 'e') {
                        opt.OPT_E = 1;
                    } if (ARGV[count][i] == 'n') {
                        opt.OPT_N = 1;
                    } if (ARGV[count][i] == 's') {
                        opt.OPT_S = 1;
                    } if (ARGV[count][i] == 't') {
                        opt.OPT_T = 1;
                    } if ((ARGV[count][1] = '-') && (strcmp(ARGV[count], "--number-nonblank") == 0)) {
                        opt.OPT_B = 1;
                    } if ((ARGV[count][1] = '-') && (strcmp(ARGV[count], "--number") == 0)) {
                        opt.OPT_N = 1;
                    } if ((ARGV[count][1] = '-') && (strcmp(ARGV[count], "--squeeze-blank") == 0)) {
                        opt.OPT_S = 1;
                    } else {
                        error = 1;
                        break;
                    }
                }
            }
        }
    memset(ARGV[count], '\0', strlen(ARGV[count]);
    }
           
           
           
    void reader(int ARGC, char ** ARGV, int error) {
        if (error == 0) {
            while (ARGV[count] != '\0') {
                FILE *f;
                f = fopen(ARGV[count]);
            }
            
        }
        
        
        
        
    }
           
           
    void print() {
        char print_char = f_
        
    }
