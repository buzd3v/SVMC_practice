#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int order = 1;
    while (t--)
    {
        int n;
        cin >> n;
        set<int> s;
        int res = -1;
        bool isfind = false;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (!isfind)
            {
                if (s.find(a) == s.end())
                {
                    s.insert(a);
                }
                else
                {
                    res = a;
                    isfind = true;
                }
            }
        }

        printf("#%d %d\n", order, res);
        order++;
    }
}