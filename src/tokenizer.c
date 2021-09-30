#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

int space_char(char c){
  if (c == '\t' || c == ' ') {
      return 1;
  }
  else {
    if (c == '\0') {
      return 0;
    }
  }  
}

/* return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  if (c != '\t' || c != ' ' || c != '\0') {
    return 1;
  }
  return 0;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str) {
  int i = 0;
  char c = str[i];
  while (non_space_char(c)) {
    if (str[i] == '\0') return str;
  }
    while (i > -1) str++;
    return str;
} 

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){
  char c = word[0];
  while (non_space_char(c)) {
    word++;
    c = word[0];
  }
  return word;
}

/* Counts the number of words in the string argument. */
int count_words(char *str) {
  char c;
  int count = 1;
  while (*str) {
    c = str[0];
    str++;
    if (space_char(c)) {
      count++;
    }
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *oStr = malloc((len +1) * sizeof(char *));
  for (int i = 0; i < len; i++) {
    oStr[i] = inStr[i];
  }
  oStr[len] = '\0';
  return oStr;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str) {
  int size = count_words(str);
  char **t = malloc((size + 1) * sizeof(char *));
  char *temp;

  for (int i = 0; i < size; i++) {
    temp = word_terminator(str);
    t[i] = copy_str(str, temp-str);
    str = word_start(str);
  }
  return t;
}

/* Prints all tokens. */
void print_tokens(char **tokens) {
  printf("All tokens:\n");
  int i = 0;
  for (char **temp = tokens; temp[0] != NULL; *temp++, i++) {
    printf("%d: %s\n", i, temp[0]);
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens) {

  for (char **temp = tokens; temp[0] != NULL; *temp++) {
    free(temp[0]);
  }
  free(tokens);
}
