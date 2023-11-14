#include <iostream>
#include <string.h>

using namespace std;

int main() {

  int t;
  cin >> t;
  int m, n;
  while (t--) {
    cin >> m >> n;
    bool prime[n + 1];
    memset(prime, 1, sizeof(prime));
    prime[0] = false;
    prime[1] = false;

    for (int i = 0; i * i < n; i++) {
      if (prime[i] == true) {
        for (int j = i * i; j <= n; j += i) {
          prime[j] = false;
        }
      }
    }

    for (int i = m; i <= n; i++) {
      if (prime[i]) {
        cout << i << endl;
      }
    }
  }

  return 0;
  // set all number is false
}