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
  printf("here is input: %s\n", input);
  char ** args = parse_args(input);
  execvp(args[0], args);
  printf("done!\n");
  return 0;
}

char ** parse_args(char * line){
  //delimit based on " " and "\n", since there is a newline at end before the null
  char **to_return = malloc(5 * sizeof(char *)); //check
  int i = 0;
  char *s = line;
  char * null_loop = "a"; //will set strsep to this and check if it's every null
  while(null_loop != NULL && i<=5){
    null_loop = strsep(&s, " \n");
    to_return[i] = null_loop;
    i++;
  }
  if (i<5){ //means you didn't have 5 args, so make this null
    to_return[i] = NULL;
  }
  return to_return;
}
