#include <cmath>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int a;
    cin >> a;
    a = sqrt(a);
    printf("#%d %d\n", tc, a);
  }
  return 0;
}