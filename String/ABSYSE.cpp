#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

vector<string> parsingLine(string &line)
{
    stringstream ss(line);
    string a, b, c, temp;
    ss >> a >> temp >> b >> temp >> c;
    return {a, b, c};
}
bool isDigit(const char &c)
{
    if ('a' <= c && 'z' >= c)
    {
        return false;
    }
    return true;
}

bool isNumber(const string &num)
{
    for (auto c : num)
    {
        if (!isDigit(c))
        {
            return false;
        }
    }
    return true;
}

string add(const string &a, const string &b)
{
    auto res = stoi(a) + stoi(b);
    return to_string(res);
}
string sub(const string &a, const string &b)
{
    auto res = stoi(a) - stoi(b);
    return to_string(res);
}
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    for (auto tc = 0; tc < t; tc++)
    {
        string temp;
        getline(cin, temp, '\n');
        string expr;
        std::getline(cin, expr, '\n');
        // cout << expr;
        auto vec = parsingLine(expr);
        int i = 0;
        for (auto num : vec)
        {
            if (!isNumber(num))
            {
                break;
            }
            i++;
        }
        if (i == 2)
        {
            vec[i] = add(vec[0], vec[1]);
        }
        if (i == 1)
        {
            vec[i] = sub(vec[2], vec[0]);
        }
        if (i == 0)
        {
            vec[i] = sub(vec[2], vec[1]);
        }

        std::cout << vec[0] << " + " << vec[1] << " = " << vec[2] << endl;
    }
    return 0;
}