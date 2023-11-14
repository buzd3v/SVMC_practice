#include <iostream>
#include <vcruntime_startup.h>
#include <vector>

using namespace std;

bool check(const vector<int> &a, const vector<int> &b)
{
    int size = a.size();
    for (int i = 0; i < size; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}
void reflect(vector<vector<int>> &mat)
{
    int size = mat.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (i != j)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }
    }
}

bool checkReflectX(const vector<vector<int>> &mat)
{
    int size = mat.size();
    for (int i = 0; i < size / 2; i++)
    {
        if (!check(mat[i], mat[size - 1 - i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        // declare and take input
        int n;
        cin >> n;
        vector<vector<int>> mat(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }
        bool checkX = checkReflectX(mat);
        reflect(mat);
        bool checkY = checkReflectX(mat);
        if (!(checkX && checkY))
        {
            cout << "#" << tc << " NO" << endl;
        }
        else
        {
            cout << "#" << tc << " YES" << endl;
        }
    }
    return 0;
}