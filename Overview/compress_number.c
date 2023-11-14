#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculate(int n) {
  char r[100];
  sprintf(r, "%d", n);
  int res = 0;
  for (int i = 0; i < strlen(r); i++) {
    res += (r[i] - '0');
  }
  return res;
}

int comporess(int n) {
  int res = 11;
  int start = n;
  while (res >= 10) {
    res = calculate(start);
    start = res;
  }
  return res;
}

int main() {
  int t, n;
  scanf("%d", &t);
  int i = 0;
  while (t--) {

    scanf("%d", &n);
    printf("#%d %d\n", ++i, comporess(n));
  }
}