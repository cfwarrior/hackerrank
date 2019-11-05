#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

struct node
{
    int x = 0;
    int y = 0;
    string path = "";
};

int dx[] = {-2, -2, 0, 2, 2, 0};
int dy[] = {-1, 1, 2, 1, -1, -2};
vector<string> moves = {"UL", "UR", "R", "LR", "LL", "L"};
bool visited[201][201] = {};

void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end)
{
    // Print the distance along with the sequence of moves.
    queue<node> q;
    node no;
    no.x = i_start;
    no.y = j_start;
    q.push(no);
    visited[i_start][j_start] = 1;
    int steps = 0;
    string p;
    int xx, yy, x, y;
    while (q.size())
    {
        for (int k = q.size(); k > 0; --k)
        {
            x = q.front().x;
            y = q.front().y;
            p = q.front().path;
            q.pop();
            if (x == i_end && y == j_end)
            {
                cout << steps << endl;
                cout << p << endl;
                return;
            }
            for (int i = 0; i < 6; ++i)
            {
                xx = x + dx[i];
                yy = y + dy[i];
                if (xx >= 0 && xx < n && yy >= 0 && yy < n && !visited[xx][yy])
                {
                    visited[xx][yy] = 1;
                    node nn;
                    nn.x = xx;
                    nn.y = yy;
                    nn.path = p.empty() ? moves[i] : p + " " + moves[i];
                    q.push(nn);
                }
            }
        }
        ++steps;
    }
    cout << "Impossible" << endl;
}