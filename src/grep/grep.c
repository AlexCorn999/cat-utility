#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
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
  char search_string[1024];
  strcpy(search_string, ARGV[optind]);
  regex_t regex;
  int regflag = 0;
  int red = 0;
  char *tmp_line = NULL;
  size_t len = 0;
  int compare = 0;
  int success = 0;
  int str_count = 0;
  int over = 0;
  int find_success = 0;

  optind++;
  while (ARGV[optind]) {
    FILE *f = fopen(ARGV[optind], "r");

    if (f) {
      if (options->i == 1) {
        regflag = REG_ICASE;
      }

      if (options->v == 1) {
        compare = REG_NOMATCH;
      }

      if (options->l == 1) {
        over = 1;
      }

      regcomp(&regex, search_string, regflag);
      while (red != EOF) {
        red = getline(&tmp_line, &len, f);
        if (tmp_line && red != EOF) {
          str_count++;
          success = regexec(&regex, tmp_line, 0, NULL, 0);
          find_success++;
          if (success == compare && over != 1 && options->c != 1) {
            if (options->n == 1) {
              printf("%d:", str_count);
            }

            if (options->h != 1) {
              printf("%s", ARGV[optind + 1]);
            }

            printf("%s", tmp_line);
          }

          if (success == compare && over == 1) {
            printf("%s", ARGV[optind + 1]);
            break;
          }
        }
      }

      free(tmp_line);
      regfree(&regex);

      if (options->c == 1) {
        printf("%s:", ARGV[optind + 1]);
        printf("%d", find_success);
      }

    } else {
      fprintf(stderr, "grep: %s: No such file or directory\n",
              ARGV[optind + 2]);
      break;
    }
    fclose(f);
    optind++;
  }
}
