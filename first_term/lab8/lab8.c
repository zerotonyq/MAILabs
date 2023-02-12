#include <stdio.h>
#include <stdlib.h>

int Calculate(char file_name[]){
  int sum = 0, nums_count = 0, total_sum = 0, total_length = 0, last_remain;
  FILE* file = fopen(file_name, "r");
  char* estr;
  char str[10];
  int sums_with_remains[44], remains_lengths[44];
  
  if(file == NULL) {
    printf("Error! File doesn't exists!.\n");
    return -1;
  }
  
  estr = fgets(str, sizeof(str), file);
  nums_count = atoi(str);
  
  for(int i = 1; i < nums_count + 1; ++i) {
    int current_num = atoi(fgets(str, sizeof(str), file));
    sum += current_num;
    int current_remain = sum % 43;
    
    if(current_remain == 0) {
      total_sum = sum;
      total_length = i;
    }
    else if(sum - sums_with_remains[current_remain] >= total_sum &&
	    (sum - sums_with_remains[current_remain]) % 43 == 0) {
      total_sum = sum - sums_with_remains[current_remain];
      total_length = i - remains_lengths[current_remain];
    }
    
    if(last_remain != current_remain && sums_with_remains[current_remain] == 0) {
      remains_lengths[current_remain] = i;
      sums_with_remains[current_remain] = sum;
    }
    last_remain = current_remain;
  }
  if(total_sum == 0) return -1;
    
  // Вывожу не только длину, но и саму 
  //сумму лишь в целях информативности
  printf("%d %d\n", total_sum, total_length);
  return total_sum;
}
int main() {

  char file_A[] = "a.txt", file_B[] = "b.txt";
  Calculate(file_A);
  Calculate(file_B);
}
