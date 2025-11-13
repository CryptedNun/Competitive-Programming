// ! ami ekta kanadocha

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<int> fixeds;
    for(int i = 1; i <= n; i++) if(a[i] == i) fixeds.push_back(i);

    int numberOfSwaps = fixeds.size() / 2;
    if(fixeds.size() % 2 == 1) numberOfSwaps++;
    cout << numberOfSwaps << endl;

    auto it = fixeds.begin();
    while(it < fixeds.end() - 1 && !fixeds.empty()) {
        cout << *it << " " << *(it + 1) << endl;
        it += 2;
    }
    if(it < fixeds.end()) {
        if(*it != 1) cout << *it << " " << 1 << endl; 
        else cout << *it << " " << 2 << endl;
    }
}