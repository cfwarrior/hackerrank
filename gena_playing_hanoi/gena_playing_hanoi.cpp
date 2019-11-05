#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

typedef long long ll;

ll hashh(vector<int> &a, int n)
{
    ll res = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        res |= (a[i] << n * i);
    }
    return res;
}
int moveHanoi(vector<int> &a)
{
    int n = a.size();
    // four int to represent four rod
    vector<int> target = {(1 << n) - 1, 0, 0, 0};
    vector<int> init = {0, 0, 0, 0};
    for (int i = 0; i < n; ++i)
    {
        init[a[i] - 1] |= (1 << i);
    }
    sort(init.begin() + 1, init.end());
    int steps = 0;
    queue<vector<int>> q;
    q.push(init);
    unordered_set<ll> visited;
    visited.insert(hashh(init, n));
    int di, dj;
    ll h;
    while (q.size())
    {
        for (int k = q.size(); k > 0; --k)
        {
            auto cur = q.front();
            q.pop();
            if (cur == target)
                return steps;
            // make all possible moves
            // try move disc on rod i to rod j
            for (int i = 0; i < 4; ++i)
            {
                // no disc at i
                if (cur[i] == 0)
                    continue;
                di = cur[i] & (~cur[i] + 1);
                for (int j = 0; j < 4; ++j)
                {
                    if (i == j)
                        continue;
                    dj = cur[j] & (~cur[j] + 1);
                    // valid move
                    if (dj == 0 || di < dj)
                    {
                        auto v = cur;
                        v[i] &= (~di);
                        v[j] |= (di);
                        sort(v.begin() + 1, v.end());
                        // hash 
                        h = 0;
                        for (int i = 0; i < v.size(); ++i)
                        {
                            h |= (v[i] << n * i);
                        }
                        if (visited.find(h) == visited.end())
                        {
                            q.push(v);
                            visited.insert(h);
                        }
                    }
                }
            }
        }
        ++steps;
    }
    return -1;
}