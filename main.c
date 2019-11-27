#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args(char * line);

int main(){
  printf("\nWelcome to Alma's Parser! Please input your program and args:\n");
  char input[100] = "\0";
  char *error_catch = fgets(input, 100, stdin);
  if (error_catch == '\0'){
    printf("issue with fgets, aborting...\n");
    exit(1);
  }
  //now should have one long string
  //printf("here is input: %s\n", input);
  char ** args = parse_args(input);
  printf("here are the args: args[0]: %s\t args[1]: %s\n", args[0], args[1]);
  execvp(args[0], args);
  printf("done!\n");
  free(args);
  return 0;
}

char ** parse_args(char * line){
  char **to_return = malloc(5 * sizeof(char *)); //check
  int i = 0;
  //printf("in parse_args, here is line: %s\n", line);
  char * null_loop = "a"; //will set strsep to this and check if it's every null
  while(line != '\0'){
    null_loop = strsep(&line, " \n");
    to_return[i] = null_loop;
    i++;
  }
  if (i<5){ //means you didn't have 5 args, so make this null
    to_return[i] = NULL;
  }
  return to_return;
}
