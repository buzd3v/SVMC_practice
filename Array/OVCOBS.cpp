#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

vector<int> stepX{-1, 0, 1};
vector<int> stepY{-1, 0, 1};

std::tuple<int, int, bool> findNext(const vector<vector<int>> &mat, int x, int y)
{
    int resx, resy;
    bool isFound = false;

    int besDiff = 999999999;
    int size = mat.size();

    for (int i = 0; i < stepX.size(); i++)
    {
        for (int j = 0; j < stepY.size(); j++)
        {
            if (x + stepX[i] >= 0 && x + stepX[i] < size && y + stepY[j] < size && y + stepY[j] >= 0)
            {
                int dif = mat[x + stepX[i]][y + stepY[j]] - mat[x][y];
                if (dif > 0)
                {
                    if (dif < besDiff)
                    {
                        resx = x + stepX[i];
                        resy = y + stepY[j];
                        besDiff = dif;
                        isFound = true;
                    }
                }
            }
        }
    }

    return {resx, resy, isFound};
}

int main()
{
    int t;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        // declare and take input
        int n, x, y;
        cin >> n >> x >> y;
        vector<vector<int>> mat(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }
        tuple<int, int, bool> result;
        int count = 0;
        result = findNext(mat, x, y);
        while (get<2>(result))
        {
            result = findNext(mat, get<0>(result), get<1>(result));
            count++;
        }
        cout << "#" << tc << " " << count << endl;
    }
    return 0;
}