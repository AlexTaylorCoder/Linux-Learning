#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#define ESCAPE_KEYS { \C-c,\C-v,\C-z } //dont need for now already works but will keep for real impl

int hash(char *val, int cap) {
  int hash = 0;
  int i = 0;
  while (input[i] != "\0") {
    hash += val[i] + ((i + 1 ) * 100);
  }
  return hash % cap;
}
void command_switch(char *input) {
  char vals[50][20] = {""};


  char cd[] = "cd";
  char ls[] = "ls";

  int ind_cd = hash(&cd, 50);
  int ind_ls = hash(&ls, 50);

  vals[ind_cd] = &cd[0];
  vals[ind_ls] = &ls[0];

  int i = 0
  while (input[i] != "\0") {

      if (hash(input[i] != "") {

          //call method match
          }
  }
    
}
int main(int argc, char *argv[]) {
  printf("Welcome to mini shell!");
  printf("ESCAPE KEYS TO EXIT");

  while (true) {
    
    char *line = readline(argv[1]);

  }
  return 1;
}

