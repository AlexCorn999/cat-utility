#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

typedef struct options {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
} opt;

void parser(int ARGC, char *ARGV[], opt *options);
void reader(char *ARGV[], opt *options);



int main(int ARGC, char *ARGV[]) {
    opt options = {0};
    parser(ARGC, ARGV, &options);
    reader(ARGV, &options);
}

void parser(int ARGC, char *ARGV[], opt *options) {
  int opt;
  while ((opt = getopt(ARGC, ARGV, "eivclnhsfo")) != -1) {
    switch (opt) {
        case 'e':
          options->e = 1;
          break;
        case 'i':
          options->i = 1;
          break;
        case 'v':
          options->v = 1;
          break;
        case 'c':
          options->c = 1;
          break;
        case 'l':
          options->l = 1;
          break;
        case 'n':
          options->n = 1;
          break;
        case 'h':
          options->h = 1;
          break;
        case 's':
          options->s = 1;
          break;
        case 'f':
          options->f = 1;
          break;
        case 'o':
          options->o = 1;
          break;
        default:
          fprintf(stderr, "usage: grep [-eivclnhsfo] [file ...]");
          exit(1);
    }
  }
}




void reader(char *ARGV[], opt *options) {
    FILE *f;
    f = fopen(ARGV[optind + 1], "r");
    int compare = 0;
    char search_string [1024];      // массив для поиска похожих значений
    strcpy(search_string, ARGV[optind]);
    char * tmp_line = NULL;
    int red;                        // кол-во символов
    int success = 0;                // для удачного сравнения
    size_t len = 0;                 // длинна строки
    int regflag = 0;
    regex_t regex;
    
    
    
    
    if (f) {
    
        printf("%s\n", search_string);
    if (options->e != 1 && options->f != 1) {
//        char search_string = ARGV[1];
    }
    
    
    if (options->i == 1) {
        regflag = REG_ICASE;                //  улавливает различия регистра
    }
    
        
        
    if (options->v == 1) {
        compare = REG_NOMATCH;                //  улавливает различия регистра
    }
    
        search_string [0] = 'w';
        search_string [1] = 'a';
        search_string [2] = 's';
    
    regcomp(&regex, search_string, regflag);
    
        
        
    while (red != EOF) {
        red = getline(&tmp_line, &len, f);
        if (tmp_line && red != EOF) {
            success = regexec(&regex, tmp_line, 0, NULL, 0);
            
            
            if (success == compare) {
                printf("%s", tmp_line);
            }
            
            
            
            
        }
        
        
        
    }
    
    
    } else {
              printf("No such file or directory");
    }
    }
