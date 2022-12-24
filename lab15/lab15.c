#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
int main() {
  int a;
  printf("Введите размерность квадратной матрицы:\n");
  scanf("%d",&a);
  int matrix[a][a];
  //заполняем матрицу
  for(int i = 0; i < a; ++i) {
    for(int j = 0; j < a; ++j) {
      printf("Ведите значение эл-та матрицы, стоящего на месте %d %d\n", i+1, j+1);
      scanf("%d", &matrix[i][j]);
    }
  }
  // выводим матрицу
  for(int i = 0; i < a; ++i) {
    for(int j = 0; j < a; ++j) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n")
  //находим минимальный эл-т матрицы
  int min_element = INT_MAX;
  for(int i = 0; i < a; ++i) {
    for(int j = 0; j < a; ++j) {
      if(matrix[i][j] < min_element) {
	min_element = matrix[i][j];
      }
    }
  }
  //строим маску столбцов, содержащих минимальный эл-т
  int columns_with_min_element[a];
  for(int i = 0; i < a; ++i)
    columns_with_min_element[i] = 0;
  for(int i = 0; i < a; ++i) {
    for(int j = 0; j < a; ++j) {
      if(matrix[i][j] == min_element) {
	columns_with_min_element[j] = 1;
      }
    }
  }
  //находим последний столбец, содержащий минимальный эл-т
  int last_column_with_min_element = 0;
  for(int i = 0; i < a; ++i) {
    if(columns_with_min_element[i] == 1)
      last_column_with_min_element = i;
  }
  // суммируем столбцы, содержащие минимальный эл-т и
  //записываем результат вместо последнего столбца, содержащего минимальный эл-т
  int result_column[a];
  for(int i = 0; i < a; ++i)
    result_column[i] = 0;
  for(int i = 0; i < a; ++i) {
    for(int j = 0; j < a; ++j) {
      if(columns_with_min_element[j] == 1) {
	result_column[i] += matrix[i][j];
      }
    }
    matrix[i][last_column_with_min_element] = result_column[i];
  }
  //выводим результат в виде матрицы
  for(int i = 0; i < a; ++i) {
    for(int j = 0; j < a; ++j) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  return 0;
}
