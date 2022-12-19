#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
  //setlocale(LC_CTYPE, "");
  FILE* file = fopen("lab13.txt", "r");
  unsigned int alphabet = 0;
  alphabet = (1u << ('b' - 'a') | 1u << ('c' - 'a') | 1u << ('d' - 'a') | 1u << ('f' - 'a') |
	      1u << ('g' - 'a') | 1u << ('h' - 'a') | 1u << ('j' - 'a') | 1u << ('k' - 'a') |
	      1u << ('l' - 'a') | 1u << ('m' - 'a') | 1u << ('n' - 'a') | 1u << ('p' - 'a') |
	      1u << ('q' - 'a') | 1u << ('r' - 'a') | 1u << ('s' - 'a') | 1u << ('t' - 'a') |
	      1u << ('v' - 'a') | 1u << ('w' - 'a') | 1u << ('x' - 'a') | 1u << ('z' - 'a'));
  char current_char;
  unsigned int current_char_set = 0, current_consonant_word_set = 0;
  int has_two_same = 0;
  while(1){
    current_char = fgetc(file);
    current_char = tolower(current_char); 
    current_char_set = 1u << (current_char - 'a');
    if(current_char == EOF) {
      break;
    }
    else if(current_char == 32 || current_char == 10 || current_char == 9 || current_char == 44) {
      current_consonant_word_set = 0;
    }
    else if(current_char_set & alphabet) {
      if(current_char_set & current_consonant_word_set) {
	has_two_same = 1;
	break;
      }
      current_consonant_word_set |= current_char_set;
    }
  }
  if(has_two_same)
    printf("Есть повторяющаяся согласная, это %c\n", current_char);
  else
    printf("Нет повторяющихся согласных");
}
