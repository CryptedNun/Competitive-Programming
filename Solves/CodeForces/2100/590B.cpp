//! O(logC/epsilon), but O(1) is possible.

#include <bits/stdc++.h>
using namespace std;

bool satisfy(double t, double v_max, double T,
             double v_x, double v_y, double w_x, double w_y,
             double x, double y) {
    
    double wind_x, wind_y;

    if (t <= T) {
        wind_x = v_x * t;
        wind_y = v_y * t;
    } else {
        wind_x = v_x * T + w_x * (t - T);
        wind_y = v_y * T + w_y * (t - T);
    }

    double ship_x = x - wind_x;
    double ship_y = y - wind_y;

    double ship_vx = ship_x / t;
    double ship_vy = ship_y / t;

    double ship_v2 = ship_vx * ship_vx + ship_vy * ship_vy;

    return ship_v2 <= v_max * v_max; // Add epsilon to prevent rounding errors
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double epsilon = 1e-7;

    double x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    x2 -= x1, y2 -= y1;
    double v, t; cin>>v>>t;
    double vx, vy, wx, wy; cin>>vx>>vy>>wx>>wy;

    double left = 0, right = 1e9, answer;
    while(right - left >= epsilon) {
        double mid = left + (right - left)/2;
        bool isPossible = satisfy(mid, v, t, vx, vy, wx, wy, x2, y2);
        if(isPossible) {
            answer = mid;
            right = mid;
        } else {
            left = mid;
        }
    }

    cout<<fixed<<setprecision(6)<<answer<<endl;
}