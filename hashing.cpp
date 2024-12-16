const int p1 = 137, p2 = 277;
const int M1 = 1e9+7, M2 = 1e9+9;
int pw1[N], pw2[N];

void prePower()
{
    pw1[0] = 1, pw2[0] = 1;
    for(int i=1; i<N; i++)
    {
        pw1[i] = (1LL * pw1[i-1] * p1) % M1;
        pw2[i] = (1LL * pw2[i-1] * p2) % M2;
    }
}

pair<ll, ll> get_hash(string s)
{
    ll n = s.size();
      
    ll hs1 = 0, hs2 = 0;
    for(int i=0; i<n; i++)
    {
        hs1 +=  (s[i] * pw1[i] ) % M1;
        hs1 %= M1;

        hs2 +=  (s[i] * pw2[i] ) % M2;
        hs2 %= M2;
    }
    return {hs1, hs2};
    // return (hs1 * M2 + hs2);
}
