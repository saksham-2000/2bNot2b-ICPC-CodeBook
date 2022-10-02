const ll mod=1e9+7; //Passing vectors by ref. to avoid TLE.
vector<vector<ll>> mat_mul(vector<vector<ll>>& a, vector<vector<ll>>& b) {
  ll l = sz(a),r=sz(b[0]);
  vector<vector<ll>> res(l, vector<ll>(r));
  for (ll i = 0; i < l; i++){
    for (ll j = 0; j < sz(a[0]); j++){
      for (ll k = 0; k < r; k++){
        res[i][k] += a[i][j] * b[j][k] % mod;
        if (res[i][k] > mod * mod)res[i][k] -= mod*mod;
      }
    }
  }
  for(ll i=0;i<l;i++)for(ll j=0;j<r;j++)res[i][j]%=mod;
    return res; // res = [a]*[b] % mod
}
vector<vector<ll>> powmat(vector<vector<ll>>& a, ll k) { 
  ll n = sz(a);
  vector<vector<ll>> id(n,vector<ll>(n,0));
  for(ll i=0;i<n;i++)id[i][i]=1;
    while (k) {
      if (k & 1) {
        id = mat_mul(id, a);
      }
      a = mat_mul(a, a),k >>= 1;
    }
  return id; // id = [a]^k
}
