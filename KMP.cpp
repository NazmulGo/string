#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define pb push_back
#define MOD 1000000007
#define vll vector<ll>
#define pll pair<ll, ll>
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
const int N = 2e5+123;

ll gcd(ll a,ll b) { return __gcd(a,b); }
ll lcm(ll a,ll b) { return (a*b)/__gcd(a,b); }

int dx[] = {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};


void solve()
{
    // build t (i mean 2nd string)
    string s, t; cin >> s >> t;


    // KMP ALGORITHM BUILD
    vll pi(t.size(), 0);
    for(int i=1, len = 0; i<t.size(); )
    {
        if(t[i] == t[len])
        {
            len++;
            pi[i] = len;
            i++;
        }
        else if(len)
        {
            len = pi[len-1];
        }
        else
        {
            pi[i] = 0; i++;
        }
    }

    // STRING MATCHING
    ll ans = 0;
    for(int i=0, j=0; i<s.size();)
    {
        if(s[i]==t[j]) i++, j++; 

        if(j == t.size())
        {
            ans++;
            j = pi[j-1];
        } 
        else if (i < s.size() && s[i] != t[j]) 
        {
            if (j > 0) 
            { 
                j = pi[j - 1];
            } 
            else 
            {  
                i++;
            }
        }
    }
    cout << ans << endl;
}

// --- Think the problem backwards ---

int main()
{
    Baba_Yaga;
    ll tc = 1; // cin >> tc;
    while(tc--) solve();
}
