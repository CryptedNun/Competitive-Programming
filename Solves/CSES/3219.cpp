// ! https://www.youtube.com/watch?v=JDuVLyKn7Yw

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(auto& elem : arr) cin >> elem;

    map<int, int> freq; // window's elements' freqs
    set<int> missing; // Set of elems missing in the window
    for(int i = 0; i <= k; i++) missing.insert(i);

    int l = 0, r = l + k - 1;
    for(int i = l; i <= r; i++) if(arr[i] <= k) freq[arr[i]]++, missing.erase(arr[i]);
    cout << *missing.begin() << ' ';
    l++, r++;

    while(r < n) {
        if(arr[l - 1] <= k && --freq[arr[l - 1]] == 0) missing.insert(arr[l - 1]);
        if(arr[r] <= k && ++freq[arr[r]] == 1) missing.erase(arr[r]);

        cout << *missing.begin() << ' ';
        l++, r++;
    }
}

// #include <bits/stdc++.h>
// using namespace std;

// void solve() {
//     int n, k; cin >> n >> k;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++) cin >> a[i];

//     vector<int> freq(k + 1, 0);
//     for (int i = 0; i < k; i++) if (a[i] <= k) freq[a[i]]++;
//     int current_mex = 0;
//     while (freq[current_mex] > 0) current_mex++;
//     cout << current_mex;

//     for (int i = k; i < n; i++) {
//         int element_to_add = a[i];
//         int element_to_remove = a[i - k];

//         if (element_to_add <= k) freq[element_to_add]++;

//         if (element_to_remove <= k) {
//             freq[element_to_remove]--;
            
//             if (freq[element_to_remove] == 0 && element_to_remove < current_mex) current_mex = element_to_remove;
//         }

//         while (freq[current_mex] > 0) current_mex++;
//         cout << " " << current_mex;
//     }
//     cout << endl;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     solve();
// }