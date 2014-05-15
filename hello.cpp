#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define magicN 42

double magicNumber() {

  /* this is placeholder, fill it with some fancy stuff! */
  return 4242;
}


int main(void) {
  for(int i = 0; i < magicN/2+1; i++) {
    for(int k = 0; k < magicN; k++) {
      printf("%s", k - magicN/2 < i && -i <  k - magicN/2 ? "*" : " ");
    }
  printf("\n");
  }

  char str[magicN];
  sprintf(str, "%.3f", magicNumber());
  
  int len = strlen(str);
  
  //printf("%d (%s)\n", len, str);
  for(int i = 0; i <= magicN; i++) {
    int dummy = i - magicN/2 + len/2;
    printf("%c", dummy < len && dummy >= 0 ? str[dummy] : '*');
  }
  printf("\n");
}
