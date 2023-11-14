#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;

bool isDigit(char c)
{
    if (c > '9' || c < '0')
        return false;
    return true;
}
void swapChar(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

void reflect(vector<vector<char>> &mat)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (i != j)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }
    }
}

bool checkInRowOrder(const vector<vector<char>> &mat)
{

    int i = 0;
    for (auto r : mat)
    {
        for (auto e : r)
        {
            if (isDigit(e))
            {
                int cnt = std::count(r.begin(), r.end(), e);
                if (cnt > 1)
                {
                    return false;
                }
            }
        }
        i++;
    }
    return true;
}

bool checkEachSquare(const vector<vector<char>> &mat)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            set<char> s;
            int x = i * 3;
            int y = j * 3;
            for (int k = x; k < x + 3; k++)
            {
                for (int t = y; t < y + 3; t++)
                {
                    if (isDigit(mat[k][t]))
                    {
                        if (s.find(mat[k][t]) == s.end())
                        {
                            s.insert(mat[k][t]);
                        }
                        else
                        {
                            // cout << "Wrong in square " << i << j << endl;
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    for (auto tc = 0; tc < t; tc++)
    {

        // declare and take input
        vector<vector<char>> mat(9, vector<char>(9, '.'));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> mat[i][j];
            }
        }
        // solve
        bool checkSquare = checkEachSquare(mat);
        bool checkR = checkInRowOrder(mat);
        reflect(mat);
        bool checkC = checkInRowOrder(mat);
        if (checkC && checkR && checkSquare)
        {
            std::cout << "#" << tc + 1 << " 1" << endl;
        }
        else
        {
            std::cout << "#" << tc + 1 << " 0" << endl;
        }
    }
}