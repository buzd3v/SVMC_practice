#include <iostream>

using namespace std;

template <size_t ROW, size_t COL> void changeValue(char (&mat)[ROW][COL], int row, int col, int x, int y, int rad)
{
    for (int i = 1; i <= rad; i++)
    {
        if (x - i >= 0)
            mat[x - i][y] = (mat[x - i][y] == 'H') ? 'X' : mat[x - i][y];
        if (x + i < row)
            mat[x + i][y] = (mat[x + i][y] == 'H') ? 'X' : mat[x + i][y];
        if (y - i >= 0)
            mat[x][y - i] = (mat[x][y - i] == 'H') ? 'X' : mat[x][y - i];
        if (y + i < col)
            mat[x][y + i] = (mat[x][y + i] == 'H') ? 'X' : mat[x][y + i];
    }
}
template <size_t ROW, size_t COL> int countH(char (&mat)[ROW][COL], int row, int col)
{
    int res = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == 'H')
                res++;
        }
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    for (auto tc = 1; tc <= t; tc++)
    {
        int row, col;
        cin >> row >> col;
        char mat[1001][1001];
        for (auto r = 0; r < row; r++)
        {
            for (auto c = 0; c < col; c++)
            {
                cin >> mat[r][c];
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int rad = 0;
                if (mat[i][j] == 'A')
                {
                    rad = 1;
                }
                if (mat[i][j] == 'B')
                {
                    rad = 2;
                }
                if (mat[i][j] == 'C')
                {
                    rad = 3;
                }
                if (rad)
                {
                    changeValue(mat, row, col, i, j, rad);
                }
            }
        }
        int res = countH(mat, row, col);
        cout << "#" << tc << " " << countH(mat, row, col) << endl;
    }
    return 0;
}
