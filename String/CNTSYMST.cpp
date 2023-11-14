#include <iostream>
#include <string>

using namespace std;

bool isPanlindrome(string &a, int start, int end)
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
    return isPanlindrome;
}
int main()
{
    int t;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        string a;
        cin >> a;
        int count = 0;
        int size = a.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = i; j < size; j++)
            {
                if (isPanlindrome(a, i, j))
                {
                    count++;
                }
            }
        }
        cout << "#" << tc << " " << count << endl;
    }
    return 0;
}