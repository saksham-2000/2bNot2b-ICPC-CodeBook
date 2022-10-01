ll poww(ll a, ll b){  // BINARY EXPO
  if(b<0)return 0;
  ll ans = 1;
  while (b){
    if (b & 1)ans = ans * a;
    a = a * a,b >>= 1;
  }
  return ans;
}

// for calc. [a*b]%c where c> 1e9,this prevents overflow
ll mulmod(ll a, ll b, ll c) { 
  ll ans = 0,y=a%c;     
  while (b) {
    if (b & 1) {
      (ans += y) %= c;
    }
    y = y * 2 % c,b >>= 1;
  }
  return ans;
}
