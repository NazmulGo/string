#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define pb push_back
#define MOD 1000000007
#define vll vector<ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
#define mem(a,b) memset(a, b, sizeof(a))
#define co(n) cout << n << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define fr(x, n) for (int i = x; i < n; ++i)
#define fraction(x) cout << fixed << setprecision(x)
#define Baba_Yaga ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
 
const double eps = 1e-9;
const int N = 1e6+12;

ll gcd(ll a,ll b) { return __gcd(a,b); }
ll lcm(ll a,ll b) { return (a*b)/__gcd(a,b); }

int dx[] = {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};

ll base1 = 137, base2 = 277, M1 = 1e9+7, M2 = 1e9+9;
pair<ll, ll> pw[N], ipw[N], pref[N];

ll big_mod(ll a, ll b, ll mod)
{
      ll ans = 1;
      while(b)
     {
           if(b & 1) ans = (ans * a) % mod;
           a = (a * a) % mod;
           b >>= 1;
      }
     return ans;
}

void prepower()
{
    pw[0] = {1, 1};
    for(int i=1; i<N; i++)
    {
        pw[i].first = (base1 * pw[i-1].first) % M1;
        pw[i].second = (base2 * pw[i-1].second) % M2;
    }

    ipw[0] = {1, 1};
    ll inb1 = big_mod(base1, M1-2, M1);
    ll inb2 = big_mod(base2, M2-2, M2);
    for(int i=1; i<N; i++)
    {
        ipw[i].first = (inb1 * ipw[i-1].first) % M1;
        ipw[i].second = (inb2 * ipw[i-1].second) % M2;
    }
}

pair<ll, ll> hash_of(string s)
{
    ll n = s.size();
    pair<ll, ll> hs = {0, 0};

    for(int i=0; i<n; i++)
    {
        hs.first = hs.first + (s[i] * pw[i].first % M1) % M1;
        hs.second = hs.second + (s[i] * pw[i].second % M2) % M2;
    }
    return hs;
}

void build(string s)
{
    ll n = s.size();
    for(int i=0; i<n; i++)
    {
        pref[i].first = (s[i] * pw[i].first % M1) % M1;
        if(i) pref[i].first = (pref[i].first + pref[i-1].first) % M1;

        pref[i].second = (s[i] * pw[i].second % M2) % M2;
        if(i) pref[i].second = (pref[i].second + pref[i-1].second) % M2;
    }
}

pair<ll, ll> get_hash(ll i, ll j)
{
    pair<ll, ll> hs = {0, 0};
    hs.first = pref[j].first;
    if(i) hs.first = (hs.first - pref[i-1].first + M1) % M1;
    hs.first = (hs.first * ipw[i].first) % M1;

    hs.second = pref[j].second;
    if(i) hs.second = (hs.second - pref[i-1].second + M2) % M2;
    hs.second = (hs.second * ipw[i].second) % M2;

    return hs;
}

// --- Think the problem backwards ---

int main()
{
    // a = abcdefgh
    // b = def
    prepower();
    string a, b; cin >> a >> b;
    cout << hash_of(b).first << " " << hash_of(b).second << endl;
    build(a);
    cout << get_hash(3, 5).first << " " << get_hash(3, 5).second << endl;
}