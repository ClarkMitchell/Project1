#include <stdio.h>
#include <string.h>

int print_matrix(char* file_names){
  FILE *fp = fopen(file_names, "r");
  char files[20][20] = {""};
  int i = 0;
  int j = 0;
  while(fscanf(fp, "%s", files[i]) == 1){
    i++;
  }
  
  while(strcmp(files[i], "") != 0){
    while(strcmp(files[j], "") != 0){
      printf("%s ", files[j]);
    }
    }
  return 0;
}
