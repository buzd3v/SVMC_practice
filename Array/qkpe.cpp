#include <iostream>
#include <vector>

using namespace std;

void checkQueen(vector<vector<int>> &mat, int x, int y)
{
    int row = mat.size();
    int col = mat[0].size();
    // check straight;
    int stepX = 1;
    int stepY = 1;

    bool checktop = true;
    bool checkbot = true;
    bool checkleft = true;
    bool checkright = true;
    bool checkupleft = true;
    bool checkupright = true;
    bool checkdownleft = true;
    bool checkdownright = true;

    bool check = true;
    while (check)
    {
        // check down
        if (x + stepX < row && checkbot)
        {
            if (mat[x + stepX][y] == 0 || mat[x + stepX][y] == -1)
            {
                mat[x + stepX][y] = -1;
            }
            else
            {
                checkbot = false;
            }
        }
        else
        {
            checkbot = false;
        }
        // check up
        if (x - stepX >= 0 && checktop)
        {
            if (mat[x - stepX][y] == 0 || mat[x - stepX][y] == -1)
            {
                mat[x - stepX][y] = -1;
            }
            else
            {
                checktop = false;
            }
        }
        else
        {
            checktop = false;
        }
        // check left
        if (y - stepY >= 0 && checkleft)
        {
            if (mat[x][y - stepY] == 0 || mat[x][y - stepY] == -1)
            {
                mat[x][y - stepY] = -1;
            }
            else
            {
                checkleft = false;
            }
        }
        else
        {
            checkleft = false;
        }
        // check right
        if (y + stepY < col && checkright)
        {
            if (mat[x][y + stepY] == 0 || mat[x][y + stepY] == -1)
            {
                mat[x][y + stepY] = -1;
            }
            else
            {
                checkright = false;
            }
        }
        else
        {
            checkright = false;
        }
        // check top left
        if (y - stepY >= 0 && x - stepX >= 0 && checkupleft)
        {
            if (mat[x - stepX][y - stepY] == 0 || mat[x - stepX][y - stepY] == -1)
            {
                mat[x - stepX][y - stepY] = -1;
            }
            else
            {
                checkupleft = false;
            }
        }
        else
        {
            checkupleft = false;
        }
        // check top right
        if (y + stepY < col && x - stepX >= 0 && checkupright)
        {
            if (mat[x - stepX][y + stepY] == 0 || mat[x - stepX][y + stepY] == -1)
            {
                mat[x - stepX][y + stepY] = -1;
            }
            else
            {
                checkupright = false;
            }
        }
        else
        {
            checkupright = false;
        }
        // check bottom right
        if (y + stepY < col && x + stepX < row && checkdownright)
        {
            if (mat[x + stepX][y + stepY] == 0 || mat[x + stepX][y + stepY] == -1)
            {
                mat[x + stepX][y + stepY] = -1;
            }
            else
            {
                checkdownright = false;
            }
        }
        else
        {
            checkdownright = false;
        }
        // check bottomleft
        if (y - stepY >= 0 && x + stepX < row && checkdownleft)
        {
            if (mat[x + stepX][y - stepY] == 0 || mat[x + stepX][y - stepY] == -1)
            {
                mat[x + stepX][y - stepY] = -1;
            }
            else
            {
                checkdownleft = false;
            }
        }
        else
        {
            checkdownleft = false;
        }
        if (!(checkbot || checktop || checkdownleft || checkdownright || checkupleft || checkupright || checkleft ||
              checkright))
        {
            check = false;
        }
        ++stepX;
        ++stepY;
    }
}

void checkKnight(vector<vector<int>> &mat, int x, int y)
{
    int row = mat.size();
    int col = mat[0].size();
    if (x + 1 < row && y + 2 < col)
        mat[x + 1][y + 2] = -1;
    if (x + 2 < row && y + 1 < col)
        mat[x + 2][y + 1] = -1;
    if (x - 2 >= 0 && y + 1 < col)
        mat[x - 2][y + 1] = -1;
    if (x - 1 >= 0 && y + 2 < col)
        mat[x - 1][y + 2] = -1;
    if (x - 2 >= 0 && y - 1 >= 0)
        mat[x - 2][y - 1] = -1;
    if (x - 1 >= 0 && y - 2 >= 0)
        mat[x - 1][y - 2] = -1;
    if (x + 2 < row && y - 1 >= 0)
        mat[x + 2][y - 1] = -1;
    if (x + 1 < row && y - 2 >= 0)
        mat[x + 1][y - 2] = -1;
}

int calSafesquare(const vector<vector<int>> &mat)
{
    int count = 0;
    for (auto r : mat)
    {
        for (auto e : r)
        {
            if (e == 0)
                count++;
        }
    }
    return count;
}
int main()
{
    int n, m; // n is num of row, m is num of col;
    int tc = 1;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
        {
            break;
        }
        // 0 = safe
        // -1 = danger
        // 1 - 2 - 3 = queens - knight - pawn
        vector<vector<int>> mat(n, vector<int>(m, 0));
        vector<pair<int, int>> queen, knight, pawn;
        for (int i = 0; i < 3; i++)
        {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++)
            {
                int x, y;
                cin >> x >> y;
                mat[x - 1][y - 1] = i + 1;
                if (i == 0)
                {
                    queen.push_back({x - 1, y - 1});
                }
                if (i == 1)
                {
                    knight.push_back({x - 1, y - 1});
                }
                if (i == 2)
                {
                    pawn.push_back({x - 1, y - 1});
                }
            }
        }
        for (auto q : queen)
        {
            checkQueen(mat, q.first, q.second);
        }
        for (auto k : knight)
        {
            checkKnight(mat, k.first, k.second);
        }
        int res = calSafesquare(mat);
        printf("Board %d has %d safe squares.\n", tc, res);
        tc++;
    }
}