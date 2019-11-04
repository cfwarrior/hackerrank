#include <bits/stdc++.h>

using namespace std;

void flood(vector<vector<int>>& matrix, int i, int j, int color) {
    int m = matrix.size(), n = matrix[0].size();
    if( i < 0 || j < 0 || i >= m || j >= n || matrix[i][j] != 1) {
        return;
    }
    matrix[i][j] = color;
    for(int dx = -1; dx <= 1; ++dx) {
        for(int dy = -1; dy <= 1; ++dy) {
            if(dx == 0 && dy == 0)
                continue;
            flood(matrix, i+dx, j+dy, color);
        }
    }
}

// Complete the connectedCell function below.
int connectedCell(vector<vector<int>> matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int color = 1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; ++j) {
            if(matrix[i][j] == 1) {
                flood(matrix, i, j, ++color);
            }
        }
    }
    unordered_map<int, int> mp;
    int res = 0;
    for(auto& row : matrix) {
        for(auto& c : row) {
            if(c) {
                mp[c]++;
                res = max(res, mp[c]);
            }
        }
    }
    return res;
}
