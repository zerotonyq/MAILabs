#include <stdio.h>

int main() {
  int a[10];
  for(int i = 0; i <= sizeof(a) / sizeof(a[0]); ++i) {
    a[i] = 10;
  }
}
