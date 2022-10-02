const ll N = 2e5 + 5;
ll fac[N], inv[N];
void fill_comb(ll N, ll p) {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % p;
inv[N-1] = powM(fac[N-1], p - 2, p);
for(int i=N-2;i>=0;i--)inv[i]=(i+1)*inv[i+1]%p; 
}
ll choose(ll a, ll b, ll p) {
 if (a < b || b < 0 || a < 0)return 0;
  return (fac[a] * inv[a - b] % p) * (inv[b]) % p;
}
