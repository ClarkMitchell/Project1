#include "prompt.h"
#include "read-files.h"
#include "hash.h"
#include "matrix-output.h"
#include <stdio.h>

int main( int argc, char **argv )
{
  int input;
  display_prompt();
  input = receive_input();
  printf("%d\n", input);

  make_input_file("./datafiles");
  //read_input_files("./inputfile.txt");
  //print_matrix("./inputfile.txt");

  //hashtable_s *hashtable = create_table(1);
  //insert(hashtable, "key1", "word");
  //insert(hashtable, "key2", "noideawhatimdoing");
  //insert(hashtable, "key3", "word");

  //printf("%s\n%s\n%s\n", get(hashtable, "key1"), get(hashtable, "key2"), get(hashtable, "key3"));

  return 0;
}
