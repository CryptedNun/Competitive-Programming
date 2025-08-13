#include <iostream>
using namespace std;

int main() {
    long long arr[30];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 5;
    arr[3] = 11;

    int t; cin>>t;
    for(int i=1; i<=t; i++) {
        int n; cin>>n;
        for(int j=4; j<=n; j++) {

            arr[j] = arr[j-1] + 5*arr[j-2] + arr[j-3] - arr[j-4];
            
        }
        cout<<i<<" "<<arr[n]<<endl;
    }
}