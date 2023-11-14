#include <iostream>
#include <string>

using namespace std;

int findStr(const string &a, const string &b)
{
    int sizeA = a.size();
    int sizeB = b.size();
    int count = 0;
    for (int i = 0; i <= sizeA - sizeB; i++)
    {
        bool isFind = true;
        for (int j = 0; j < sizeB; j++)
        {
            if (a[i + j] != b[j])
                isFind = false;
        }
        if (isFind)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int tc;
    while (cin >> tc)
    {

        string a, b;
        cin >> a;
        cin.ignore();
        getline(cin, b, '\n');
        std::cout << "#" << tc << " " << findStr(b, a) << "\n";
    }
}