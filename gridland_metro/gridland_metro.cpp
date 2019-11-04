// tag : sort, greedy
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long long getCoverage(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    int start = intervals[0][0], end = intervals[0][1];
    long long total = 0;
    for (auto &v : intervals)
    {
        if (v[0] <= end)
        {
            end = max(end, v[1]);
        }
        else
        {
            total += end - start + 1;
            start = v[0];
            end = v[1];
        }
    }
    total += end - start + 1;
    return total;
};

// Complete the gridlandMetro function below.
long long gridlandMetro(int n, int m, int k, vector<vector<int>> track)
{
    if (k == 0)
        return n * m;
    sort(track.begin(), track.end());
    long long total = 0;
    unordered_map<int, vector<vector<int>>> mp;
    for (auto &v : track)
    {
        mp[v[0]].push_back({v[1], v[2]});
    }
    for (auto &row : mp)
    {
        auto v = row.second;
        total += getCoverage(v);
    }
    cout << (long long)m * n - total << endl;
    return (long long)m * n - total;
}
