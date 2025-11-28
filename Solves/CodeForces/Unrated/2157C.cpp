#include <bits/stdc++.h>
using namespace std;

struct Answer {
    int val;
    bool minflag = false;
    bool mexflag = false;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n, k, q; cin >> n >> k >> q;
        vector<tuple<int, int, int>> queries(q);
        for(int i = 0; i < q; i++) {
            int c, l, r;
            cin >> c >> l >> r;
            queries[i] = make_tuple(c, l, r);
        }

        vector<Answer> answer(n);
        for(int i = 0; i < q; i++) {
            int c = get<0>(queries[i]);
            int l = get<1>(queries[i]);
            int r = get<2>(queries[i]);

            for(int j = l - 1; j < r; j++) {
                if(c == 1) answer[j].minflag = true;
                else answer[j].mexflag = true;
            }
        }

        for(int i = 0; i < n; i++) {
            if(answer[i].minflag && answer[i].mexflag) answer[i].val = k + 1;
            else if(answer[i].minflag) answer[i].val = k;
            else if(answer[i].mexflag) answer[i].val = i % k;
            else answer[i].val = 0;
        }

        for(auto& element : answer) {
            cout << element.val  << " ";
        }
        cout << endl;
    }
}

// You can also use a difference array to reduce the worst case time complexity from O(nq) to O(n + q)
// But here it is unnecessary