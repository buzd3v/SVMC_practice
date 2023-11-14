#include <iostream>
#include <string>

using namespace std;

pair<int, bool> isPanlindrome(string &a, int start, int end)
{
    bool isPanlindrome = true;
    string temp = string(a.begin() + start, a.begin() + end + 1);
    int size = temp.size();
    if (size == 1)
        isPanlindrome = true;
    else
    {
        for (int i = 0; i < size / 2; i++)
        {
            if (temp[i] != temp[size - i - 1])
            {
                isPanlindrome = false;
                break;
            }
        };
    }
    return {size, isPanlindrome};
}
int main()
{
    int t;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        string a;
        cin >> a;
        int size = a.size();
        int maxLength = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = i; j < size; j++)
            {
                auto res = isPanlindrome(a, i, j);
                if (res.second)
                {
                    if (res.first > maxLength)
                    {
                        maxLength = res.first;
                    }
                }
            }
        }
        cout << "#" << tc << " " << maxLength << endl;
    }
    return 0;
}