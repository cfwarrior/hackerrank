// tag : bfs
#include <bits/stdc++.h>

using namespace std;

int bfs(int n, int a, int b) {
    vector<pair<int, int>> moves = {{a, -b}, {a, b}, {-a, b}, {-a, -b}, {b, a}, {b, -a}, {-b, a}, {-b, -a}};
    int steps = 0;
    queue<pair<int,int>> q;
    int x = 0, y = 0;
    q.push({0, 0});
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[0][0] = 1;
    while(!q.empty()) {
        for(int k = q.size(); k > 0; --k) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            if(x == n-1 && y == n-1)
                return steps;
            for(auto& [dx, dy] : moves) {
                int xx = x + dx;
                int yy = y + dy;
                if(xx >= 0 && yy >= 0 && xx < n && yy < n && !visited[xx][yy]) {
                    visited[xx][yy] = 1;
                    q.push({xx, yy});
                }

            }
        }
        ++steps;
    }
    return -1;
}

// Complete the knightlOnAChessboard function below.
vector<vector<int>> knightlOnAChessboard(int n) {
    vector<vector<int>> res(n-1, vector<int>(n-1, 0));
    for(int a = 1; a < n; ++a) {
        for(int b = a; b < n; ++b) {
            int t = bfs(n, a, b);
            res[a-1][b-1] = res[b-1][a-1] = t;
        }
    }
    return res;
}