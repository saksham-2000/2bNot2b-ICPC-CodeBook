vector<ll> bit; // 1 based indexing
void update(ll i, ll delta) { // add 'delta' to pos 'i'
  ll n = sz(bit) - 1;
  while (i <= n) {
    bit[i] += delta,i += i & -i;
  }
}
ll sum(ll i) { // find sum for range [1..i]
  ll ret = 0;
  while (i) {
    ret += bit[i],i -= i & -i;
  }
  return ret;
}
ll find_kth_one(ll k) { // find position of kth one
  ll pos = 0, ret = 0, n=sz(bit);
  for (ll i = 25; i >= 0; i--) {
    if (pos + (1ll << i) < n && ret + bit[pos + (1ll << i)] < k) {
      ret += bit[pos + (1ll << i)];
      pos += 1ll << i;
    }
  }
  return pos + 1;
}
