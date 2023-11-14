#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

template <size_t sizex, size_t sizey> string combined(char (&mat)[sizex][sizey], int row, int col)
{
    string res = "";
    for (int i = 0; i < col; i++)
    {
        int j = 0;
        while (j < row)
        {
            res += mat[j][i];
            j++;
        }
    }
    return res;
}
int main()
{
    int COL;
    while (cin >> COL)
    {
        if (COL == 0)
            break;
        string cryptCode;
        cin >> cryptCode;
        int size = cryptCode.length();

        int ROW = size / COL;

        char mat[21][21];
        int row = -1, col = 0;
        // sign = 1 mean left to right, -1 means right to left
        int sign = -1;

        string decrypt = "";

        for (int i = 0; i < size; i++)
        {
            if (i % COL == 0)
            {
                sign *= -1;
                row++;
                col = 0;
            }
            if (sign > 0)
            {
                mat[row][col] = cryptCode[i];
                col++;
            }
            else
            {
                mat[row][COL - col - 1] = cryptCode[i];
                col++;
            }
        }
        decrypt = combined(mat, ROW, COL);

        cout << decrypt << endl;
    }
}