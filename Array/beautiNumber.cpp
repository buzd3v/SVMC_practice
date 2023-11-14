#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isBeauty(const vector<int> &v, int n, int num)
{
    bool isbeauty = true;

    string strN = std::to_string(n);
    if (strN.size() < num)
    {
        isbeauty = false;
    }
    else
    {
        int count = 0;
        for (auto c : strN)
        {
            for (auto e : v)
            {
                if (e == c - '0')
                    count++;
            }
        }
        if (count < num)
        {
            isbeauty = false;
        }
        else
        {
            isbeauty = true;
        }
    }

    return isbeauty;
}

int main()
{
    int t;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        int n, m;
        cin >> n >> m;
        int count = 0;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int start, end;
        cin >> start >> end;
        for (auto i = start; i <= end; i++)
        {
            if (isBeauty(v, i, m))
            {
                count++;
            }
        }
        cout << "#" << tc << " " << count << endl;
    }
}