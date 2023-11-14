#include <iostream>
#include <string>

using namespace std;

int calculate(const int &n) {
  string r = std::to_string(n);
  int res = 0;
  for (auto c : r) {
    res += (c - '0');
  }
  return res;
}

int comporess(const int &n) {
  int res = 11;
  int start = n;
  while (res > 10) {
    res = calculate(start);
    start = res;
  }
  return res;
}

int main() {
  int t, n;
  cin >> t;
  int i = 0;
  while (t--) {

    cin >> n;
    cout << "#" << ++i << " " << comporess(n) << endl;
  }
}