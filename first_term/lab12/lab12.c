#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
int main() {

  int a;
  scanf("%d", &a);
  int forward_zeroes = 0;
  for(int i = 0; i < 32; ++i) {
    if((int)pow(2, i) > abs(a)) {
      forward_zeroes = 31 - i;
      printf("%d\n", forward_zeroes);
      break;
    }
  }
  int num_size = 31 - forward_zeroes;
  int half_num_size = 0;
  if(num_size%2 == 0)
    half_num_size = num_size/2;
  else
    half_num_size = num_size/2 + 1;
  int part_before_zeroes = a % ((int)pow(2, half_num_size));
  printf("%d\n", half_num_size);
  printf("%d\n", part_before_zeroes);
  int part_after_zeroes = 0;
  part_after_zeroes = a / ((int)pow(2, half_num_size));
  printf("%d\n", part_after_zeroes);
  int res = part_before_zeroes + (part_after_zeroes*(int)pow(2, forward_zeroes)*(int)pow(2, half_num_size));
  if(a == 1)
    res = INT_MAX;
  printf("%d\n", res);
  return 0;
}
