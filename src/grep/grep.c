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
  // флаг для 2 файлов
  int moreFile = 0;
  // флаг для ошибок
  int fileYes = 0;

  if (ARGV[optind]) {
    // сохраняет регулярное выражение
    char search_string[1024];

    // копирует значение в массив
    strcpy(search_string, ARGV[optind]);

    while (ARGV[optind]) {
      if (ARGV[optind + 2]) {
        moreFile = 1;
      }
      // структура regex
      regex_t regex;
      // для флагов
      int regflag = 0;
      // для getline
      int red = 0;
      // временная линия указатель на строку
      char *tmp_line = NULL;
      // длина строки
      size_t len = 0;
      int compare = 0;
      int success = 0;
      int str_count = 0;
      int over = 0;
      // поиск совпадений кол-во
      int find_success = 0;

      FILE *f = fopen(ARGV[optind + 1], "r");

      if (f) {
        // игнорирование регистра
        if (options->i == 1) {
          regflag = REG_ICASE;
        }

        // инверсия поиска
        if (options->v == 1) {
          compare = REG_NOMATCH;
        }

        if (options->l == 1) {
          over = 1;
        }

        // превращение в регулярное выражение
        regcomp(&regex, search_string, regflag);

        while (red != EOF) {
          // получаем строку из файла
          red = getline(&tmp_line, &len, f);

          // если не конец и помять выделилась
          if (tmp_line && red != EOF) {
            str_count++;
            // поиск строки из регулярного выражения
            success = regexec(&regex, tmp_line, 0, NULL, 0);

            if (success == compare) {
              find_success++;
            }

            // если удачно находит
            if (success == compare && over != 1 && options->c != 1) {
              if (options->h != 1 && moreFile == 1) {
                printf("%s:", ARGV[optind + 1]);
              }

              if (options->n == 1) {
                printf("%d:", str_count);
              }

              printf("%s", tmp_line);
            }

            if (success == compare && over == 1 && options->l == 1) {
              printf("%s\n", ARGV[optind + 1]);
              break;
            }
          }
        }

        if (options->c == 1) {
          printf("%s:", ARGV[optind + 1]);
          printf("%d", find_success);
          printf("\n");
        }

        free(tmp_line);
        regfree(&regex);
        fileYes = 1;

      } else if (fileYes == 0) {
        fprintf(stderr, "grep: %s: No such file or directory\n", ARGV[optind]);
      }

      fclose(f);
      optind++;
    }
  }
}
