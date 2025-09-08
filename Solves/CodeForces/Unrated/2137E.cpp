#include <bits/stdc++.h>
using namespace std;
int MEX(const vector<int>& input);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int n, k; cin>>n>>k;
        vector<int> a(n);
        unordered_map<int, int> freq;
        for(int i=0; i<n; i++) {
            cin>>a[i];
            freq[a[i]]++;
        }

        long long globalMEX = MEX(a);

        if(globalMEX == 0) {
            if(k % 2 == 1) cout<<0<<endl;
            else cout<<n<<endl;
        } else {
            // ! leastMultipleElementLessThanMEX
            int lMELTM = INT_MAX;
            for(int x:a) {
                if(x < globalMEX && freq[x] > 1) {
                    lMELTM = min(lMELTM, x);
                }
            }

            if(lMELTM == INT_MAX) {
                // ! numberOfElementsGreaterThanMEX
                long long nOEGTM = 0;
                for(int x:a) if(x > globalMEX) nOEGTM++;

                if(nOEGTM == 1) cout<< (globalMEX*(globalMEX+1))/2 <<endl;
                else if(k%2 == 1) cout<< (globalMEX*(globalMEX-1))/2 + globalMEX*nOEGTM<<endl;
                else cout<< (globalMEX*(globalMEX-1))/2 + (globalMEX+1)*nOEGTM<<endl;
            } else {
                if(k == 1) {
                    long long sum = 0;
                    for(int x : a) {
                        if(freq[x] == 1 && x < globalMEX) {
                            sum += x;
                        } else {
                            sum += globalMEX;
                        }
                    }

                    cout<< sum << endl;
                } else {
                    long long sum = 0;
                    for(int x:a) {
                        if(x >= lMELTM && k%2 == 0) sum += lMELTM;
                        else if(x >= lMELTM && k%2 == 1) sum += lMELTM+1;
                        else sum += x;
                    }

                    cout<<sum<<endl;
                }
            }
        }
        
    }
}

int MEX(const vector<int>& input) {
    vector<bool> isPresent(input.size(), false);
    for(int x:input) 
        if(x < input.size())
            isPresent[x] = true;

    for(int i=0; i<isPresent.size(); i++) 
        if (!isPresent[i])
            return i;

    return input.size();
}