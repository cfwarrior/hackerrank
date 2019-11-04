// tag : dfs
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool dfs(vector<string> &matrix, int x, int y, vector<int> &destination, vector<pair<int, int>> &path, vector<vector<bool>> &visited)
{
    int m = matrix.size(), n = matrix[0].size();
    if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] == 'X' || visited[x][y])
    {
        return false;
    }
    visited[x][y] = 1;
    if (x == destination[0] && y == destination[1])
        return true;
    path.push_back({x, y});
    for (auto &[dx, dy] : moves)
    {
        if (dfs(matrix, x + dx, y + dy, destination, path, visited))
            return true;
    }
    path.pop_back();
    return false;
}

// Complete the countLuck function below.
string countLuck(vector<string> matrix, int k)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, 0));
    // find starting point
    vector<int> start;
    vector<int> destination;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == '*')
            {
                destination = {i, j};
            }
            if (matrix[i][j] == 'M')
            {
                start = {i, j};
            }
        }
    }
    vector<pair<int, int>> path;
    bool found = dfs(matrix, start[0], start[1], destination, path, visited);
    int count = 0;
    // count how many branch
    int last_x = -1, last_y = -1;
    for (auto &[x, y] : path)
    {
        int c = 0;
        for (auto &[dx, dy] : moves)
        {
            if (x + dx >= 0 && y + dy >= 0 && x + dx < m && y + dy < n && matrix[x + dx][y + dy] != 'X' && !(last_x == x + dx && last_y == y + dy))
                ++c;
        }
        last_x = x;
        last_y = y;
        if (c > 1)
        {
            count++;
        }
    }
    return count == k ? "Impressed" : "Oops!";
}