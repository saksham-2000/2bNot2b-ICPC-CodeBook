const long long N = 2e5 + 5;
const long long MOD = 1e9+7;
long long powM(long long a, long long b, long long m){  // BINARY EXPO
  if(b<0)return 0;
  long long ans = 1;
  while (b){
    if (b & 1)ans = ans * a %m;
    a = a * a %m,b >>= 1;
  }
  return ans;
}

long long fac[N], inv[N];
void fill_comb(long long N, long long p = MOD) {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % p;
inv[N-1] = powM(fac[N-1], p - 2, p);
for(int i=N-2;i>=0;i--)inv[i]=(i+1)*inv[i+1]%p; 
}
long long choose(long long a, long long b, long long p) {
 if (a < b || b < 0 || a < 0)return 0;
  return (fac[a] * inv[a - b] % p) * (inv[b]) % p;
}

// With Euclidean Division

long long inv2[N];
const long long MOD = 1e9+7;

void precomp_inv(){
inv2[1] = 1;
for (int i = 2; i < MOD; i++) { inv2[i] = MOD - MOD / i * inv2[MOD % i] % MOD; }
}
// (precompute the inverse modular of numbers in the range [1,MOD) in O(MOD)
