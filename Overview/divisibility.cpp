#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  int n, x, y;
  while (t--) {
    cin >> n >> x >> y;
    int temp = x;
    int i = 1;
    while (temp < n && temp > 1) {
      //   cout << temp << " ";
      if (temp % y != 0) {
        cout << temp << " ";
      }
      i++;
      temp = x * i;
    }
    cout << endl;
  }
  return 0;
}