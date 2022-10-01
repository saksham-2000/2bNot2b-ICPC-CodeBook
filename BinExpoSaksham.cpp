ll poww(ll a, ll b){  // BINARY EXPO
  if(b<0)return 0;
  ll ans = 1;
  while (b){
    if (b & 1)ans = ans * a;
    a = a * a,b >>= 1;
  }
  return ans;
}
ll mulmod(ll a, ll b, ll c) { 
  ll ans = 0,y=a%c;     
  while (b) {
    if (b & 1) {
      (ans += y) %= c;
    } // for calc. [a*b]%c where c> 1e9,this prevents overflow
    y = y * 2 % c,b >>= 1;
  }
  return ans;
}
ll powMbig(ll a, ll b, ll m){
  if (a <= 0)return 0; 
  ll ans = 1LL,a=a%m;
  while (b){
    if (b & 1) ans = mulmod(ans, a, m);
    a = mulmod(a, a, m),b >>= 1;
  }
  return ans; // (a^b) %m for m >1e9 (to avoid overflow) 
}
// Primality test in logN time (non-deterministic)
bool fermatprime(ll x) {
  if (x <= 3)return (x == 2 || x == 3);
  for (ll iter = 0; iter < 20; iter++) {
    ll a = rng() % (x - 3) + 2; // random base in [2,x-2]
    ll temp = powMbig(a, x - 1, x);
    if (temp != 1) {
      return false;
    }
  } // Beware ! Can lead to 'psuedo' primes.
  return true;
}
