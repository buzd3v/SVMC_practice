#include <iostream>
#include <vector>
using namespace std;

void printMat(const vector<vector<char>> &mat)
{

    for (auto r : mat)
    {
        for (auto e : r)
        {
            cout << e;
        }
        cout << endl;
    }
}

vector<vector<char>> extractWindow(const vector<vector<char>> &mat, int x, int y)
{
    int posX = x * 5;
    int posY = y * 5;

    vector<vector<char>> res(6);

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            res[i].push_back(mat[posX + i][posY + j]);
        }
    }

    return res;
}

// return curtain type
int checkWindow(const vector<vector<char>> &window)
{
    string s;
    for (int i = 1; i <= 4; i++)
    {
        s += window[i][1];
    }
    if (s == "....")
        return 0;
    if (s == "*...")
        return 1;
    if (s == "**..")
        return 2;
    if (s == "***.")
        return 3;
    if (s == "****")
        return 4;

    return -1;
}

int main()
{
    int t;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        vector<int> res(5, 0);
        int m, n;
        cin >> m >> n;
        int row = 5 * m + 1;
        int col = 5 * n + 1;
        vector<vector<char>> mat(row, vector<char>(col, 'z'));

        // init
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> mat[i][j];
            }
        }

        // printMat(mat);

        // count
        for (auto i = 0; i < m; i++)
        {
            for (auto j = 0; j < n; j++)
            {
                auto window = extractWindow(mat, i, j);
                int kind = checkWindow(window);
                res[kind]++;
            }
        }

        // print result
        std::cout << "#" << tc << " ";
        for (auto i : res)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
