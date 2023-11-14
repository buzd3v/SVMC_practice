#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  int a;
  int mod = 1000007;
  while (t--) {
    cin >> a;
    int res = 0;
    int i = 0;
    for (i = 1; i <= a / 2; i++) {
      int j = a / i;
      int product = i * j;
      res = (res % mod + product) % mod;
    }
    res = (res % mod + (a + i) * (a - i + 1) / 2) % mod;
    cout << res << endl;
  }
  return 0;
}