#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ONE_E_7 1000000007
#define ONE_E_7LL 1000000007LL
#define PI acos(-1.0)

#define ll long long
#define v_i vector<int>
#define v_l vector<ll>
#define v_b vector<bool>
#define v_v_l vector<vector<ll>>
#define s_i set<int>
#define s_l set<ll>
#define ms_i multiset<int>
#define ms_l multiset<ll>
#define m_ii map<int, int>
#define m_ll map<ll, ll>
#define um_ii unordered_map<int, int, custom_hash>
#define um_ll unordered_map<ll, ll, custom_hash>

#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define no cout << "NO" << '\n'
#define yes cout << "YES" << '\n'

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;




/**
 * @note 
 * `std::set<T>` with extra operations:
 * 
 * * `find_by_order(k)` - returns iterator to kth element.
 * 
 * * `order_of_key(x)`  - returns count of elements < x, equivalent to idx[0_based] of x in sorted order.
 */
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;




/**
 * @note Use it like this:
 * * `unordered_map<T1, T2, custom_hash>` safe_map;
 */
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
 
    template<typename T>
    size_t operator()(const T& v) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(static_cast<uint64_t>(std::hash<T>{}(v)) + FIXED_RANDOM);
    }
 
    template<class T1, class T2>
    size_t operator()(const pair<T1,T2>& p) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        uint64_t h1 = splitmix64(static_cast<uint64_t>(std::hash<T1>{}(p.first)) + FIXED_RANDOM);
        uint64_t h2 = splitmix64(static_cast<uint64_t>(std::hash<T2>{}(p.second)) + FIXED_RANDOM);
        return h1 ^ (h2 << 1);
    }
 
    template<class... Ts>
    size_t operator() (const tuple<Ts...>& t) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return apply([&](const auto&... elems) {
            size_t h = 0;
            ((h ^= splitmix64(static_cast<uint64_t>(std::hash<std::decay_t<decltype(elems)>>{}(elems)) + FIXED_RANDOM)), ...);
            return h;
        }, t);
    }
};




inline void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}




// ? BIT OPERATIONS -------------------------------------------------
template<typename T>
inline bool checkbit(T x, int n) { return (x >> n) & 1; }
template<typename T>
inline void setbit(T &x, int n) { x |= (static_cast<T>(1) << n); }
template<typename T>
inline void resetbit(T &x, int n) { x &= ~(static_cast<T>(1) << n); }
// ? ----------------------------------------------------------------




// ? BINARY EXPON. ------------------------------------------------------------------------
inline ll power(ll base, ll exp, ll mod = ONE_E_7LL) {
    ll res = 1;
    base %= mod;
    while (exp) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

inline ll modInverse(ll n, ll mod = ONE_E_7LL) { return power(n, mod - 2, mod); }
inline ll mod_inv(ll a, ll m) {
    ll x, y;
    ll g = extended_gcd(a, m, x, y);
    if (g != 1) return -1; // Inverse DNE
    return (x % m + m) % m;
}
// ? --------------------------------------------------------------------------------------




// ? GCD, LCM, DIOPHANTINE-------------------------------------------------------------------------------
inline ll lcm(ll a, ll b) { if (a == 0 || b == 0) return 0; return abs(a / gcd(a, b) * b); }

inline ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

inline bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = extended_gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
// ? ---------------------------------------------------------------------------------------




// ? FACTORIAL TABLES-------------------------------------------
v_l fact;
inline void fill_fact(int m, ll mod = ONE_E_7LL) {
    fact.resize(m+1);
    fact[0] = 1LL;
    for(ll i = 1; i <= m; i++) fact[i] = (fact[i-1] * i) % mod;
}

v_l invfact;
inline void fill_invfact(int m, ll mod = ONE_E_7LL) {
    invfact.resize(m + 1);
    fill_fact(m, mod);

    invfact[m] = modInverse(fact[m], mod);
    for (ll i = m - 1; i >= 0; i--) invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
}
// ?------------------------------------------------------------




// ? nCr TABLE----------------------------------------------------
v_v_l nCr;
inline void fill_nCr_table(int m, ll mod = ONE_E_7LL) {
    nCr.assign(m + 1, v_l(m + 1, 0LL));
    
    for (int i = 0; i <= m; i++) {
        nCr[i][0] = 1LL; // nC0 is always 1
        for (int j = 1; j <= i; j++) {
            // Pascal's Identity: nCr = (n-1)Cr + (n-1)C(r-1)
            nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % mod;
        }
    }
}
// ?--------------------------------------------------------------




// ? EULER'S TOTIENT-----------------------------------------
v_l phi;
inline void fill_phi(int m) {
    phi.resize(m + 1);
    for(ll i = 0; i <= m; i++) phi[i] = i;
    for(ll i = 2; i <= m; i++) 
        if(phi[i] == i)
            for(ll j = i;j <= m;j += i) phi[j] -= phi[j] / i;
}
// ?---------------------------------------------------------




// ? CRT---------------------------------------
struct Congruence{
    ll a, m;
};

ll chinese_remainder_theorem(vector<Congruence> const& congruences) {
    ll M = 1;
    for (auto const& c : congruences) M *= c.m;

    ll solution = 0;
    for (auto const& c : congruences) {
        ll M_i = M / c.m;
        ll N_i = mod_inv(M_i, c.m);
        
        
        ll term = (__int128)c.a * M_i % M * N_i % M;
        solution = (solution + term) % M;
    }
    return (solution + M) % M; 
}
// ?--------------------------------------------




// ? GRAYCODE------------------------------
inline ll graycode (ll n) {
    return n ^ (n >> 1);
}

inline ll reverse_graycode (ll g) {
    ll n = 0;
    for (; g; g >>= 1)
        n ^= g;
    return n;
}
// ?--------------------------------------




// ? LINEAR SIEVE, SPF-------------------
v_i primes, spf;
void linear_sieve(int n) {
    spf.assign(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > spf[i] || i * p > n) break;
            spf[i * p] = p;
        }
    }
}
// ?------------------------------------------




// ? FFT & IFFT ------------------------------------------------
using cd = complex<double>;
// const double PI = acos(-1);

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
        for(int i = 0; i < n; i++) {
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


vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    
    int n = 1;
    while (n < a.size() + b.size() - 1) n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);  // fft_it(fa, false);
    fft(fb, false);  // fft_it(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);   // fft_it(fa, true);

    vector<ll> result(n);
    for (int i = 0; i < n; i++) result[i] = round(fa[i].real());
    return result;
}
// ? -------------------------------------------------------------



void solve() {

}



int main() {
    fastIO();
    int t = 1; 
    cin >> t;
    while(t--) solve();
    
    return 0;
}