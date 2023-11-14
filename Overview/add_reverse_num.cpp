#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int reversed(string &a)
{
    std::reverse(a.begin(), a.end());
    return std::stoi(a);
}

int reversed(const int &a)
{
    string r = std::to_string(a);
    return reversed(r);
}

int add_reverse(string &a, string &b)
{
    int res = reversed(a) + reversed(b);
    return reversed(res);
}

int main()
{
    int T;
    cin >> T;
    string a, b;
    while (T--)
    {
        cin >> a >> b;
        std::cout << add_reverse(a, b) << endl;
    }
    return 0;
}