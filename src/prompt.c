#include <stdio.h>

void display_prompt(){
  printf("What is the number of words to analyze (2 - 10)?\n");
  printf("> ");
}

int check_input(int input){
  if(input < 11 && input > 1)
    return 1;
  else
    return 0;
}

int receive_input(){
  int i = 1;           // default is an invalid input
  scanf("%d", &i);     // scanf will only assign a valid integer
  if(check_input(i))
    return i;
  else{
    printf("Error: invalid input. ");
    return -1;
  }
}

