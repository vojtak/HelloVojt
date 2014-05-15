#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

double magicNumber() {

  /* this is placeholder, fill it with some fancy stuff! */
  return 42;
}

int main(int argc, char **argv) {
  if(argc != 2 || atoi(argv[1]) <= 0) {
    printf("program requies exactly one positive integer argument\n");
    return -1;
  }

  const int magicN = atoi(argv[1]);

  for(int i = 0; i < magicN/2+1; i++) {
    for(int k = 0; k < magicN; k++) {
      printf("%s", k - magicN/2 < i && -i <  k - magicN/2 ? "*" : " ");
    }
  printf("\n");
  }

  char *str = new char[magicN];
  sprintf(str, "%.4f", magicNumber());
  
  int len = strlen(str);
  
  for(int i = 0; i <= magicN; i++) {
    int dummy = i - magicN/2 + len/2;
    printf("%c", dummy < len && dummy >= 0 ? str[dummy] : '*');
  }
  printf("\n");

  delete [] str;

  return 0;
}
