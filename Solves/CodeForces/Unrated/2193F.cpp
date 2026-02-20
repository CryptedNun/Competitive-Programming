// Light work no reaction

#include <bits/stdc++.h>
using namespace std;

struct point { int x, y; };
struct col { int x, miny, maxy; };

void solve() {
    long long n, Ax, Ay, Bx, By; cin >> n >> Ax >> Ay >> Bx >> By;
    vector<point> points(n);
    for(auto& elem : points) cin >> elem.x;
    for(auto& elem : points) cin >> elem.y;

    sort(points.begin(), points.end(), [] (point a, point b) {
        if(a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    vector<col> cols;
    cols.push_back({points[0].x, points[0].y, points[0].y});
    for(int i = 1 ; i < n; i++) {
        if(points[i].x == points[i - 1].x) {
            if(points[i].y < cols.back().miny) cols.back().miny = points[i].y;
            if(points[i].y > cols.back().maxy) cols.back().maxy = points[i].y;
        } else cols.push_back({points[i].x, points[i].y, points[i].y});
    }

    // def dp[i][0/1] = minpath time to get to i-th col's top(if j = 0) or bottom (if j = 1) point
    // base cases:: dp[0][0] = abs(Ay - cols[0].miny) + cols[0].maxy - cols[0].miny
    // dp[0][1] = abs(Ay - cols[0].maxy) + cols[0].maxy - cols[0].miny
    // state transition is simple since it's geom. DP

    // ! The greedy motif is that we only enter cols via one of its extrema_y point (like min/max) once we enter a col, we exit via the other extrema_y point.

    long long dp[cols.size()][2];
    dp[0][0] = abs(Ay - cols[0].miny) + cols[0].maxy - cols[0].miny;
    dp[0][1] = abs(Ay - cols[0].maxy) + cols[0].maxy - cols[0].miny;

    for(int i = 1; i < cols.size(); i++) {
        dp[i][0] = min(dp[i - 1][0] + abs(cols[i - 1].maxy - cols[i].miny) , dp[i - 1][1] + abs(cols[i - 1].miny - cols[i].miny)) + cols[i].maxy - cols[i].miny;
        dp[i][1] = min(dp[i - 1][0] + abs(cols[i - 1].maxy - cols[i].maxy) , dp[i - 1][1] + abs(cols[i - 1].miny - cols[i].maxy)) + cols[i].maxy - cols[i].miny;
    }

    // ! X_DIFF from A to B is const since we can't go back
    long long x_time = Bx - Ax;
    long long y_time = min(dp[cols.size() - 1][0] + abs(cols.back().maxy - By), dp[cols.size() - 1][1] + abs(cols.back().miny - By));

    cout << x_time + y_time << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}