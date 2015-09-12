#include <stdio.h>
#include <stdlib.h>

int make_input_file(char* path){
  char string[50];
  sprintf(string, "ls %s > inputfile.txt\n", path);
  int i = system(string);
  return 0;
}

int read_input_files(char *path){
  char str[15];
  FILE *f1 = fopen(path, "r");
  while(fscanf(f1, "%s", str) == 1 ){
    printf("%s\n", str);
  }
  return 0;
}
