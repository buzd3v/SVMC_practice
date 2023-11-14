#include <iostream>
#include <ostream>

using namespace std;

const int ROW = 5, COL = 5;
int mat[ROW][COL];

void rowTravel(int mat[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << mat[i][j] << " ";
        }
    }
    cout << endl;
}
void colTravel(int mat[ROW][COL])
{
    for (int i = 0; i < COL; i++)
    {
        for (int j = 0; j < ROW; j++)
        {
            cout << mat[j][i] << " ";
        }
    }
    cout << endl;
}

void lrTravel(int mat[ROW][COL])
{
    // 1 mean left to right, -1 mean right to left
    int sign = -1;
    int r = -1;
    int c = 0;
    while (r < ROW)
    {
        if (c % COL == 0)
        {
            sign *= -1;
            c = 0;
            r++;
            if (r == ROW)
            {
                break;
            }
        }
        // travel from left to right
        if (sign > 0)
        {
            std::cout << mat[r][c] << " ";
            // cout << " r, c =" << r << " " << c << endl;
            c++;
        }
        // travel from right to left
        if (sign < 0)
        {
            std::cout << mat[r][COL - c - 1] << " ";
            // cout << " r, c =" << r << " " << c << endl;
            c++;
        }
    }
    cout << endl;
}
void duTravel(int mat[ROW][COL])
{
    {
        // 1 mean down, -1 mean up
        int sign = -1;
        int c = -1;
        int r = 0;
        while (c < COL)
        {
            if (r % ROW == 0)
            {
                sign *= -1;
                c++;
                r = 0;
                if (c == COL)
                {
                    break;
                }
            }
            // travel from left to right
            if (sign > 0)
            {
                std::cout << mat[r][c] << " ";
                // cout << " r, c =" << r << " " << c << endl;
                r++;
            }
            // travel from right to left
            if (sign < 0)
            {
                std::cout << mat[ROW - r - 1][c] << " ";
                // cout << " r, c =" << r << " " << c << endl;
                r++;
            }
        }
        cout << endl;
    }
}
void spiralTravel(int mat[ROW][COL])
{
}

void diagonalTravel(int mat[ROW][COL])
{
    int maxDiagonalLength = ROW - 1;
    // half bottom travel
    for (int i = maxDiagonalLength; i >= 0; i--)
    {
        for (int c = 0; c < COL; c++)
        {
            int r = i + c;
            if (r >= ROW || r < 0)
            {
                break;
            }
            else
            {
                cout << mat[r][c] << " ";
            }
        }
    }
    cout << endl;

    // the remain
    for (int i = 1; i <= maxDiagonalLength; i++)
    {
        for (int c = 0; c < COL; c++)
        {
            int r = i + c;
            if (r >= ROW || r < 0)
            {
                break;
            }
            else
            {
                cout << mat[r][c] << " ";
            }
        }
    }
    cout << endl;
}

int main()
{
    int c = 1;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            mat[i][j] = c;
            c++;
        }
    }
    rowTravel(mat);
    lrTravel(mat);
    duTravel(mat);
    diagonalTravel(mat);
}