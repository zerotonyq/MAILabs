#include <stdio.h>
#include <math.h>
#include <wchar.h>
#include <locale.h>

enum Condition {
  Q0,
  Q1,
  Q2,
  Q3
};
int main() {
  
  setlocale(LC_CTYPE, "");
  FILE* file = fopen("b.txt", "r");
  int char_num, stil_word = 0, all_words_length = 0, all_words_count = 0;
  enum Condition condition = Q0;
  int is_ended = 0, stil_switching = 0;
  while(!is_ended){
    
    if(!stil_switching)
      char_num = fgetwc(file);
    
    switch(condition) {
    case Q0:
      if(char_num == 32 || char_num == 10) {
	condition = Q1;
	stil_switching = 1;
      }
      else if(char_num == EOF) {
	condition = Q3;
	stil_switching = 1;
      }
      else {
	condition = Q2;
	stil_switching = 1;
      }
    case Q1:
      if(char_num == EOF) {
	condition = Q3;
	stil_switching = 1;
      }
      else if(char_num == 32 || char_num == 10) {
	if(stil_word == 1) {
	  all_words_count += 1;
	  stil_word = 0;
	}
	stil_switching = 0;
      }
      else {
	condition = Q2;
	stil_switching = 1;
      }
      break;
    case Q2:
      if(char_num == EOF) {
	condition = Q3;
	stil_switching = 1;
      }
      else if(char_num == 32 || char_num == 10) {
	condition = Q1;
	stil_switching = 1;
      }
      else {
	stil_word = 1;
	all_words_length += 1;
	stil_switching = 0;
      }
      break;
    case Q3:
      is_ended = 1;
      break;
      
    }
  }
  if(all_words_count == 0) {
    printf("%d\n", 0);
    return 1;
  }
  double a =(double)all_words_length/(double)all_words_count;
  printf("%d\n", (int)round(a));
}
