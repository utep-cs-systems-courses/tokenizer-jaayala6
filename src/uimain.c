#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.c"

int main()
{
  char userIn[100];

  while(1) {
    printf("Input a string to tokenize it or !<num> for a special number, !h for full history, !q to quit:\n");
    putchar('$');
    fgets(userIn, 100, stdin);
    char** tokenz = tokenize(userIn);
    print_all_tokens(tokenz);
    
    if (userIn == "!q") {
      return 0;
    }
    
    //printf("%s\n", userIn);
  }
  return 0;
}
