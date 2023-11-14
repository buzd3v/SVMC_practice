#include <cmath>
#include <iostream>
#include <math.h>

using namespace std;

int main() {

  // your code here
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc) {
    int a, b;
    cin >> a >> b;
    int res = pow(a, b);
    printf("#%d %d\n", tc, res);
  }

  return 0;
}