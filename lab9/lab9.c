#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
  int is[100], js[100], ls[100];
  is[0] = 5;
  js[0] = 5;
  ls[0] = 4;

  for(int p = 1; p < 51; ++p) {
    int sign = (ls[p-1] - js[p-1]) > 0 ? 1 : -1;
    int max = is[p-1] > ls[p-1] ? is[p-1] : ls[p-1];
    is[p] = is[p-1] / 3 - abs(is[p-1] - p) * sign;
    js[p] = js[p-1] % 10 - max % p;
    ls[p] = is[p-1] + (js[p-1] * (p-1)) % 5 + ls[p-1] % 5 + 3;
    double a = sqrtf((double)((is[p]+10) * (is[p]+10) + (js[p]+10) * (js[p]+10)));
    double b = sqrtf((double)((is[p]+20) * (is[p]+20) + (js[p]+20) * (js[p]+20)));

    if((int)round(a) <= 10. && (int)round(b) <= 10) {
      printf("bam %d - %d %d %d\n", p, is[p], js[p], ls[p]);
      break;
    }
    if(p == 50) printf("noo %d - %d %d %d\n", p, is[p], js[p], ls[p]);
  }
}
