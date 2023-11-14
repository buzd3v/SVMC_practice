#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, count = 0;
        cin >> n >> k;
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            s.insert(a);
        }

        for (auto num : s)
        {
            if (s.find(k + num) != s.end())
            {
                count++;
            }
            if (s.find(num - k) != s.end())
            {
                count++;
            }
        }

        cout << count / 2 << endl;
    }
}