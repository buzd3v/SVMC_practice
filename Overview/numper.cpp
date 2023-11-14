#include <cmath>
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

bool isNumper(int n) {
  int temp = sqrt(n);
  if (temp * temp == n)
    return true;
  return false;
}

int main() {
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int a, b;
    cin >> a >> b;
    bool isHit = false;
    printf("#%d ", tc);
    for (auto i = a; i <= b; i++) {
      if (isNumper(i)) {
        cout << i << " ";
        isHit = true;
      }
    }
    if (!isHit) {
      cout << "NO NUMBER";
    }
    cout << endl;
  }
  return 0;
}