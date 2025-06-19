#include <bits/stdc++.h>
using namespace std;

bool cow(vector<int>& x, int number, int distance) {
    auto currentPosition = x.begin();
    for(int i=1; i<number; i++) {
        currentPosition = lower_bound(x.begin(), x.end(), *currentPosition + distance);
        if(currentPosition == x.end()) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int n, c; cin>>n>>c;
        vector<int> x(n);
        for(int& point:x) cin>>point;
        sort(x.begin(), x.end());

        int left = 0, right = x.back() - x.front(), answer;
        while(left <= right) {
            int mid = left + (right-left)/2;
            bool condition = cow(x, c, mid);
            if(condition) {
                answer = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }

        cout<<answer<<endl;
    }
}