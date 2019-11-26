#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args(char * line);

int main(){
  printf("\nWelcome to Alma's Parser! Please input your program and args:\n");
  char *input = NULL;
  char *error_catch = fgets(input, 100, stdin);
  if (error_catch == '\0'){
    printf("issue with fgets, aborting...\n");
    exit(1);
  }
  //now should have one long string
  char ** args = parse_args(input);
  execvp(args[0], args);
  return 0;
}

char ** parse_args(char * line){
  //delimit based on " " and "\n", since there is a newline at end before the null
  char *to_return[5] = malloc(5 * sizeof(*char)); //check
  int i = 0;
  while(0){
    //strsep, and if return is NULL, break 
  }
  if (i<5){ //means you didn't have 5 args, so make this null
    to_return[i] = '\0';
  }
}
