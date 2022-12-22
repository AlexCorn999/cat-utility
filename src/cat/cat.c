#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct options {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} opt;

void parser(int ARGC, char *ARGV[], opt *options);
void reader(char *ARGV[], opt *options);

int main(int ARGC, char *ARGV[]) {
  opt options = {0};
  parser(ARGC, ARGV, &options);

  if (options.b == 1) {
    options.n = 0;
    reader(ARGV, &options);
  } else {
    reader(ARGV, &options);
  }
}

void parser(int ARGC, char *ARGV[], opt *options) {
  int opt;
  int option_index;

  static struct option long_options[] = {{"number", 0, 0, 'n'},
                                         {"squeeze-blank", 0, 0, 's'},
                                         {"number-nonblank", 0, 0, 'b'},
                                         {0, 0, 0, 0}};

  while ((opt = getopt_long(ARGC, ARGV, "+benstvTE", long_options,
                            &option_index)) != -1) {
    switch (opt) {
      case 'b':
        options->b = 1;
        break;
      case 'n':
        options->n = 1;
        break;
      case 'e':
        options->e = 1;
        options->v = 1;
        break;
      case 's':
        options->s = 1;
        break;
      case 't':
        options->t = 1;
        options->v = 1;
        break;
      case 'v':
        options->v = 1;
        break;
      case 'T':
        options->t = 1;
        break;
      case 'E':
        options->e = 1;
        break;
      default:
        fprintf(stderr, "usage: cat [-benstuv] [file ...]");
        exit(1);
    }
  }
}

void reader(char *ARGV[], opt *options) {
  while (ARGV[optind]) {
    FILE *f = fopen(ARGV[optind], "r");

    if (f) {
      int prev = '\n';
      int current;
      int flag_127 = 0;
      int q = 0;
      int p = 0;
      int str_count = 1;

      while ((current = fgetc(f)) != EOF) {
        if (options->s == 1) {
          if (prev == '\n') {
            char next = fgetc(f);
            ungetc(next, f);
            if (next == '\n') {
              continue;
            }
          } else {
          }
        }

        if (options->b == 1) {
          if (current != '\n' && prev == '\n') {
            printf("%6d\t", str_count++);
          }
        }

        if (options->t == 1) {
          if (current == '\t') {
            current = 'I';
            p = 1;
          }
        }

        if (options->v == 1) {
          if ((current >= 0 && current <= 31 && current != '\n' &&
               current != '\t') ||
              current == 127 || current > 127) {
            if (current >= 0 && current <= 31 && current != '\n' &&
                current != '\t') {
              current = current + 64;
              q = 1;
            }
            if (current > 127 && current <= 160) {
              current = (current & 31) + 64;
              flag_127 = 1;
            }
            if (current == 127) {
              current = '?';
              q = 1;
            }

          } else {
            q = 0;
            flag_127 = 0;
          }
        }

        if (options->n == 1) {
          if (prev == '\n') {
            printf("%6d\t", str_count++);
          } else {
          }
        }

        if (options->e == 1) {
          if (current == '\n') {
            fprintf(stdout, "$");
          }
        }

        if (p == 1) {
          printf("^%c", current);
          prev = current;
          p = 0;
        } else if (q == 1) {
          printf("^%c", current);
          prev = current;
        } else if (flag_127 == 1) {
          printf("M-^%c", current);
          prev = current;
        } else {
          prev = current;
          putchar(current);
        }
      }
      fclose(f);
    } else {
      fprintf(stderr, "cat: %s: No such file or directory\n", ARGV[optind]);
    }
    optind++;
  }
}
