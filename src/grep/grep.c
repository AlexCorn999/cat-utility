#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>

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
    int current;
    
    FILE *f;
    f = fopen(ARGV[optind], "r");

      if (f) {
          int current;
          
          
          
          
          
              while ((current = fgetc(f)) != EOF) {
                  
                  
                  if (options->e == 1) {
                    
                      
                      
                      
                  }
            
            
                  
                  
                  if (options->i == 1) {
                    
                      
                      
                      
                  }
                  
                  
                  
                  
                  if (options->v == 1) {
                    
                      
                      
                      
                  }
                  
                  
                  
                  
                  if (options->c == 1) {
                    
                      
                      
                      
                  }
                  
                  
                  
                  
                  if (options->l == 1) {
                    
                      
                      
                      
                  }
                  
                  
                  
                  
                  if (options->n == 1) {
                    
                      
                      
                      
                  }
            
            
                  
                  
                  if (options->h == 1) {
                    
                      
                      
                      
                  }
                  
                  
                  
                  if (options->s == 1) {
                    
                      
                      
                      
                  }
                  
                  
                  
                  
                  if (options->f == 1) {
                    
                      
                      
                      
                  }
                  
                  
                  
                  
                  if (options->o == 1) {
                    
                      
                      
                      
                  }
            
                  putchar(current);
                  
                  
          } else {
              printf("No such file or directory");
            }
      }
