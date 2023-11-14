#include <iostream>
#include <limits>
#include <vector>

using namespace std;
void printMat(const vector<vector<int>> &mat)
{

    for (auto r : mat)
    {
        for (auto e : r)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}

int calSum(const vector<vector<int>> &mat, int h, int w, int x, int y)
{
    int sum = 0;
    for (int i = x; i < h + x; i++)
    {
        for (int j = y; j < w + y; j++)
        {
            if (i == x || i == h + x - 1)
            {
                if (mat[i][j] % 2 == 0)
                    sum += mat[i][j];
            }
            else
            {
                if (j == y || j == w + y - 1)
                {
                    if (mat[i][j] % 2 == 0)
                        sum += mat[i][j];
                }
            }
        }
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        int h, w, m, n;
        cin >> h >> w >> m >> n;
        int max = 0;
        vector<vector<int>> mat(m, vector<int>(n, 0));
        for (auto i = 0; i < m; i++)
        {
            for (auto j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }

        for (int i = 0; i <= m - h; i++)
        {
            for (int j = 0; j <= n - w; j++)
            {
                int res = calSum(mat, h, w, i, j);
                max = (max >= res) ? max : res;
            }
        }
        printf("#%d %d\n", tc, max);
    }
}