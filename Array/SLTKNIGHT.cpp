#include <iostream>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> knight_moves = {{1, 2}, {-1, 2}, {-1, -2}, {1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

bool isValidMove(int x, int y, int size)
{
    if (x >= 0 && x < size && y >= 0 && y < size)
        return true;
    return false;
}

int cal(const vector<vector<int>> &mat, const pair<int, int> &pos)
{
    int size = mat.size();
    int count = 0;
    for (auto move : knight_moves)
    {
        pair<int, int> new_pos = {pos.first + move.first, pos.second + move.second};
        if (isValidMove(new_pos.first, new_pos.second, size))
        {
            if (mat[new_pos.first][new_pos.second] == 2 || mat[new_pos.first][new_pos.second] == 1)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        int n, k, m, d;
        cin >> n >> k >> m >> d;
        int max = -1;
        int bestX, bestY;
        vector<pair<int, int>> knight_pos(k, pair<int, int>({0, 0}));
        vector<vector<int>> mat(n, vector<int>(n, -1));
        // knight = 1, other = 2 abandon = -1
        for (int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;
            knight_pos[i] = {a, b};
            mat[a][b] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            mat[a][b] = 2;
        }
        for (int i = 0; i < d; i++)
        {
            int a, b;
            cin >> a >> b;
            mat[a][b] = -1;
        }

        for (auto pos : knight_pos)
        {
            if (cal(mat, pos) > max)
            {
                max = cal(mat, pos);
                bestX = pos.first;
                bestY = pos.second;
            }
        }

        cout << "#" << tc << " " << bestX << " " << bestY << " " << max << endl;
    }
}
