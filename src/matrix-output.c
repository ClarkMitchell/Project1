#include <stdio.h>

int print_matrix(char* file_names){
  FILE *fp = fopen(file_names, "r");
  const char *files[20] = {0};
  int i = 0;
  int j = 0;
  while(fscanf(fp, files[i]) == 1){
    i++;
  }

  while(files[i] != 0){
    while(files[j] != 0){
      printf("%s ", files[j]);
    }
  }
  return 0;
}
