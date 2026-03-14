#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


// ? FFT & IFFT ------------------------------------
using cd = complex<double>;
const double PI = acos(-1);

int reverse(int n, int lg_n) {
    int res = 0;
    for(int i = 0; i < lg_n; i++) {
        if(n & (1 << i)) {
            res |= 1 << (lg_n - 1 - i);
        }
    }

    return res;
}

void fft_it(vector<cd>& a, bool inverse) {
    int n = a.size();
    int lg_n = 0;
    while((1 << lg_n) < n) lg_n++;

    for(int i = 0; i < n; i++) {
        int __i = reverse(i, lg_n);
        if(i < __i) swap(a[i], a[__i]);
    }

    for(int len = 2; len <= n; len <<= 1 /* len *= 2 */) {
        double angle = 2 * PI / len * (inverse ? -1 : 1);
        cd __w(cos(angle), sin(angle));
        for(int i = 0; i < n; i += len) {
            cd w(1);
            for(int j = 0; j < len/2; j++) {
                cd u = a[i + j], v = w * a[i + j + len/2];
                a[i + j] = u + v;
                a[i + j + len/2] = u - v;
                w *= __w;
            }
        }
    }

    if(inverse) 
        for(auto& e : a)
            e /= n;
    
}

void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    if (n == 1) return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; i < n/2; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; i < n/2; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }

        w *= wn;
    }
}


vector<long long> multiply(vector<long long> const& a, vector<long long> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    
    int n = 1;
    while (n < a.size() + b.size() - 1) n <<= 1;
    fa.resize(n);
    fb.resize(n);

    // fft(fa, false);  
    fft_it(fa, false);
    // fft(fb, false);  
    fft_it(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    // fft(fa, true);   
    fft_it(fa, true);

    vector<long long> result(n);
    for (int i = 0; i < n; i++) result[i] = round(fa[i].real());
    return result;
}
// ? ----------------------------------------------


void solve() {
    int n; cin >> n;
    vector<long long> a(n + 1), b(n + 1);
    for(int i = n; i >= 0; i--) cin >> a[i];
    for(int i = n; i >= 0; i--) cin >> b[i];

    vector<long long> res = multiply(a, b);
    for(int i = 2 * n; i >= 0; i--) cout << res[i] << " ";
    cout << endl;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int t = 1; 
    cin >> t;
    while(t--) solve();

    return 0;
}