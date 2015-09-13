#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int make_input_file(char* path){
  char string[50];
  sprintf(string, "ls %s > inputfile.txt\n", path);
  system(string);
  return 0;
}

//int read_input_files(char *path){
//  int i = 0;
//  char line[15];
//  char *token;
//  char *tokens[10][10];
//  FILE *f1 = fopen(path, "r");
  
//  do{
//    fgets(line, sizeof(line), f1);
//    char token[] = strtok(line, " ");
//    char filename[] = strcat("/datafiles/", token); 
//    FILE f2* = fopen(filename, "r")
//    tokens[i][0] = malloc(strlen(token) + 1);
//    strcpy(tokens[i][0], token);
//    i++;
//    printf("%s\n", token);
//  }while(token != NULL );
//  return 0;
//}
