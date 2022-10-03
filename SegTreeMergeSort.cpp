const ll nax=2e5+5;
vector<ll> sg[4 * nax]; // 4 times mem
vector<ll> aa;
void build(ll x, ll lx, ll rx) {
  if (lx == rx) {
    sg[x].pb(aa[lx]);
    return;
  }
  ll mx = (lx + rx) / 2;
  build(2 * x, lx, mx);
  build(2 * x + 1, mx + 1, rx);
  merge(sg[2 * x].begin(), sg[2 * x].end(), 
    sg[2 * x + 1].begin(), sg[2 * x + 1].end(),
    back_inserter(sg[x]));
}
// gives # of values >= val in [l,r]
ll calc(ll x, ll lx, ll rx, ll l, ll r, ll val) {
  if (l > r||l>rx||r<lx)return 0;
  if (lx >= l && rx <= r) {
    return sg[x].end() - lower_bound(all(sg[x]), val);
  }
  ll mx = (lx + rx) / 2;
  return calc(2 * x, lx, mx, l, r, val) + calc(2 * x + 1, mx + 1, rx, l, r, val);
}
