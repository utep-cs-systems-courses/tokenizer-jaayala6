#include <stdlib.h>
#include <stdio.h>
#define true 1
#define false 0

int space_char(char c) {
  if (c == '\t' || c == ' ')
    return true;
  return false;
}

int non_space_char(char c) {
  if (c != '\t' && c != ' ' && c != '\0')
    return true;
  return false;
}

char *word_start(char *str) {
  while (non_space_char(*str++)) {
    if (*str == '\0') {
      return str;
    }
  }
  return str;
}

char *word_terminator(char *word) {
  while (non_space_char(*word++))
    ;
  return word;
}

int count_words(char *str) {
  if ((str != NULL) && (str[0] == '\0'))
    return 0;
  int words = 1;
  while (*str++)
    if (*str == ' ')
      words++;
  return words;
}

char *copy_str(char *inStr, short len) {
  char *copyStr = malloc((len + 1) *  sizeof(char *));
  for (int i = 0; i < len; i++) {
    copyStr[i] = inStr[i];
  }
  copyStr[len] = '\0';
  return copyStr;
}

char **tokenize(char *str) {
  int size = count_words(str);
  char **tokenP = malloc((size + 1) * sizeof(char *));
  char *tmp;
  for (int i = 0; i < size; i++) {
    tmp = word_terminator(str);
    tokenP[i] = copy_str(str, tmp - str);
    str = word_start(str);
  }
  return tokenP;
}

void print_tokens(char **tokens) {
  int n = 0;
  for (char **tmp = tokens; tmp[0] != NULL; *tmp++, n++) {
    printf("[%d]: %s\n", n, tmp[0]);
  }
}

void free_tokens(char **tokens) {
  for (char **tmp = tokens; tmp[0] != NULL; *tmp++) {
    free(tmp[0]);
  }
  free(tokens);
}

int main() {
  char userIn[1000];
  while (1) {
    putchar('$');
    fgets(userIn, 1000, stdin);
    char **tokens = tokenize(userIn);
    print_tokens(tokens);
    free_tokens(tokens);
  }

  return 0;  
}
