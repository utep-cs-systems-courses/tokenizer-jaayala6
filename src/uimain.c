#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 100


int strcmp(char *s, char *t) {
  for (; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t;
}

int main() {
  List *hist = init_history();
  int hist_num;
  char userIn[MAX];  
  while (1) {
    printf("type a string to tokenize, !<num> for old tokens, !h for full history, !q to quit:\n");
    putchar('$');
    fgets(userIn, MAX, stdin);
    char **tokens = tokenize(userIn);
    
    if (userIn[0] == '!') {
      if (userIn[1] == 'q')
	break;
      else if (userIn[1] == 'h')
	print_history(hist);
      else {
	hist_num = atoi(userIn+1);
	printf("%d: %s\n", hist_num, get_history(hist, hist_num));
      }
    }
    else {
      add_history(hist, userIn);
      print_tokens(tokens);
      free_tokens(tokens);
    }
  }
  free_history(hist);
  return 0;  
}
