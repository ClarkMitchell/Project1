#include "main.h"
#include "prompt.h"
#include "read-files.h"
#include "matrix-output.h"
#include <stdio.h>

int main( int argc, char **argv )
{
  int input;
  display_prompt();
  input = receive_input();
  printf("%d\n", input);

  make_input_file("./datafiles");
  read_input_files("./inputfile.txt");
  print_matrix("./inputfile.txt");
  return 0;
}
