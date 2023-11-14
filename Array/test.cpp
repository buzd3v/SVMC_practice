#include <iostream>
#include <set>

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
    set<int> s;
    s.insert(10);
    s.insert(5);

    for (auto num : s)
    {
        cout << num;
    }
    cout << "Kien";
}