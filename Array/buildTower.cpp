#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> void printVec(vector<T> &vec)
{
    for (auto e : vec)
    {
        cout << e << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        int n, t1, t2;
        cin >> n >> t1 >> t2;
        vector<int> weight(n, 0);

        for (int i = 0; i < n; i++)
        {
            cin >> weight[i];
        }

        std::sort(weight.begin(), weight.end());

        int iter = 1;
        int res = 0;
        while (iter <= t1 && iter <= t2)
        {
            res += weight.back() * iter;
            weight.pop_back();
            res += weight.back() * iter;
            weight.pop_back();
            iter++;
        }
        while (iter <= t1)
        {
            res += weight.back() * iter;
            weight.pop_back();
            iter++;
        }
        while (iter <= t2)
        {
            res += weight.back() * iter;
            weight.pop_back();
            iter++;
        }
        printf("#%d %d\n", tc, res);
    }
}