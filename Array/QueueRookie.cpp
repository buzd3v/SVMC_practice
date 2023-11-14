#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void printPair(const vector<pair<int, int>> &mat)
{
    for (auto e : mat)
    {
        cout << e.first << " " << e.second << endl;
    }
}
void printVec(const vector<int> &v)
{
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}

int findPos(const vector<int> &res, int num, int numBefore)
{
    int cnt = 0;
    int pos = 0;
    int i = 0;
    for (auto e : res)
    {
        if (e > num || e == -1)
        {
            cnt++;
        }
        if (cnt == numBefore)
        {
            pos = i + 1;
            break;
        }
        i++;
    }
    return pos;
}

vector<int> solve(const vector<pair<int, int>> &combine)
{
    vector<int> res(combine.size(), -1);

    for (auto e : combine)
    {
        int pos = findPos(res, e.first, e.second);
        if (res[pos] == -1)
        {
            res[pos] = e.first;
        }
        else
        {
            while (res[pos] != -1)
            {
                pos++;
            }
            res[pos] = e.first;
        }
    }

    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> height(n, 0);
        vector<int> numBefore(n, 0);
        vector<pair<int, int>> combine;
        for (auto i = 0; i < n; i++)
        {
            cin >> height[i];
        }
        for (auto i = 0; i < n; i++)
        {
            cin >> numBefore[i];
            combine.push_back({height[i], numBefore[i]});
        }

        // sorting
        std::sort(combine.begin(), combine.end(), [](const auto &a, const auto &b) {
            return a.first < b.first || (a.first == b.first) && (a.second < b.second);
        });

        auto res = solve(combine);
        for (auto e : res)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}