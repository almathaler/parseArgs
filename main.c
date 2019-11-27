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
  execvp(args[0], args);
  printf("done!\n");
  free(args);
  return 0;
}

char ** parse_args(char * line){
  char **to_return = malloc(5 * sizeof(char *)); //check
  int i = 0;
  while(*line != '\0'){ //this will make the last arg null by default bc strsep returns null when it's done
    to_return[i] = strsep(&line, " \t\n");
    i++;
  }
  to_return[i] = NULL;
  return to_return;
}
