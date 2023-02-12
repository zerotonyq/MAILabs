#include <stdio.h>
#include <math.h>

int main() {
  int a;
  printf("Введите размерность квадратной матрицы:\n");
  scanf("%d",&a);
  int matrix[a][a];
  for(int i = 0; i < a; ++i) {
    for(int j = 0; j < a; ++j) {
      printf("Ведите значение эл-та матрицы, стоящего на месте %d %d\n", i+1, j+1);
      scanf("%d", &matrix[i][j]);
    }
  }
  for(int i = 0; i < a; ++i) {
    for(int j = 0; j < a; ++j) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  int num_of_operations = 1, elements_remove = 0, current_column = 0, current_stroke = 0;
  for(int i = 1; i < a; ++i) {
    num_of_operations += 2;
  }
  for(int b = 0; b < num_of_operations; ++b) { 
    switch(b % 4) {
    case 0:
      for(int j = 0; j < a; ++j) {
	if(j < a - elements_remove && j > elements_remove - 1)
	  printf("%d ", matrix[current_stroke][j]);
      }
      current_stroke += 1;
      break;
    case 1:
      for(int i = 0; i < a; ++i) {
	if(i <= a - elements_remove && i > elements_remove - 1)
	  printf("%d ", matrix[i][a-1-current_column]);
      }
      
      break;
    case 2:
      for(int j = a-1; j > -1; --j) {
	if(j < a - elements_remove && j > elements_remove-2)
	  printf("%d ", matrix[a-current_stroke][j]);
      }
      break;
    case 3:
       for(int i = a-1; i > -1; --i) {
	if(i <= a - elements_remove && i > elements_remove - 1)
	  printf("%d ", matrix[i][current_column]);
      }
      current_column += 1;
      break;
    }
    if(b % 4 == 0)
      elements_remove += 1;   
  }
}
