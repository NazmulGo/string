ll base = 137, pref[N];
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

ll hash_of(string s)
{
    ll n = s.size(), hs = 0;
    for(int i=0; i<n; i++)
    {
        hs = hs + (s[i] * big_mod(base, i, MOD) % MOD) % MOD;   
    }
    return hs;
}
void build(string s)
{
    ll n = s.size();
    for(int i=0; i<n; i++)
    {
        pref[i] = s[i] * big_mod(base, i, MOD) % MOD;
        if(i) pref[i] = pref[i] + pref[i-1] % MOD;
    }
}
ll get_hash(ll i, ll j)
{
    ll hs = pref[j];
    if(i) hs = (hs - pref[i-1] + MOD) % MOD;
    ll pp = big_mod(base, i, MOD);
    hs = hs * big_mod(pp, MOD-2, MOD) % MOD;
    return hs;
}

// --- Think the problem backwards ---

int main()
{
    string a, b; cin >> a >> b;
    cout << hash_of(b) << endl;
    build(a);
    cout << get_hash(3, 5) << endl;
}
