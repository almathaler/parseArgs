#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args(char * line);

int main(){
  printf("\nWelcome to Alma's Parser! Please input your program and args:\n");
  char input[100];
  char *error_catch = fgets(input, 100, stdin);
  if (error_catch == '\0'){
    printf("issue with fgets, aborting...\n");
    exit(0);
  }
  //now should have one long string
  //printf("here is input: %s\n", input);
  char **args = parse_args(input);
  printf("here are the args: args[0]: %s\t args[1]: %s\t args[2]: %s\t args[3]: %s\n", args[0], args[1], args[2], args[3]);
  execvp(args[0], args);
  printf("done!\n");
  free(args);
  return 0;
}

char ** parse_args(char * line){
  char **to_return = malloc(5 * sizeof(char *)); //check
  int i = 0;
  //printf("in parse_args, here is line: %s\n", line);
  while(line != '\0'){
    to_return[i] = strsep(&line, " \n");
    i++;
  }
  to_return[i] = NULL;
  printf("in parse_args, size of i: %d\n", i);
  return to_return;
}
