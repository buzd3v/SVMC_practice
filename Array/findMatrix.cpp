#include <iostream>
#include <vector>

using namespace std;
int differ(int a, int b)
{
    return (a > b) ? a - b : b - a;
}

int main()
{
    int t;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        // declare and take input
        int n, m, k;
        cin >> n >> m >> k;

        int maxDiff = 99999999;
        int diff = 0;
        int bestX = 0;
        int bestY = 0;
        int bestSum = 0;
        vector<vector<int>> mat(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }

        for (int i = 0; i <= n - m; i++)
        {
            int sum = 0;
            for (int j = 0; j <= n - m; j++)
            {
                // create sliding window
                if (j == 0)
                {
                    // first sum at pos [i,0]
                    for (int h = i; h < i + m; h++)
                    {
                        for (int p = j; p < j + m; p++)
                        {
                            sum += mat[h][p];
                        }
                    }
                }
                else
                {
                    // next sum at pos [i,1] and so on
                    for (int o = i; o < i + m; o++)
                    {
                        sum -= mat[o][j - 1];
                        sum += mat[o][j + m - 1];
                    }
                }
                diff = differ(k, sum);
                if (diff < maxDiff)
                {
                    maxDiff = diff;
                    bestX = i;
                    bestY = j;
                    bestSum = sum;
                }
                else if (diff == maxDiff)
                {
                    if (bestSum > sum)
                    {
                        bestSum = sum;
                        bestX = i;
                        bestY = j;
                    }
                    else if (bestSum == sum)
                    {
                        if (i <= bestX && j <= bestY)
                        {
                            bestX = i;
                            bestY = j;
                        }
                    }
                }
            }
        }
        cout << "#" << tc << " " << bestX << " " << bestY << endl;
    }
    return 0;
}