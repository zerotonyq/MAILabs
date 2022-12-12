#include <stdio.h>
#include <math.h>
#include <wchar.h>
#include <locale.h>
int main() {
  setlocale(LC_CTYPE, "");
  FILE* file = fopen("b.txt", "r");
  int charNum, stilWord = 0, allWordsLength = 0, allWordsCount = 0;

  while(1){
    charNum = fgetwc(file);
    if(charNum == EOF) {
      break;
    }
    else if(charNum == 32 || charNum == 10) {
      if(stilWord == 1) {
	allWordsCount += 1;
	stilWord = 0;
      }
    }
    else {
      stilWord = 1;
      allWordsLength += 1;
    }
  }
  if(allWordsCount == 0)
    return 1;
  double a =(double)allWordsLength/(double)allWordsCount;
  printf("%d\n", (int)round(a));
  printf("%d %d", allWordsLength, allWordsCount);
}
