vector<ll>sg,aa; // assign 4* mem. to sg
const ll garbage_val = 2e9;
ll combine(ll x, ll y) {
  return min(x,y);
}
void build(ll x, ll lx, ll rx) {
  if (lx == rx) {
    sg[x] = aa[lx];
    return;
  }
  ll mx = (lx + rx) / 2;
  build(2 * x, lx, mx);
  build(2 * x + 1, mx + 1, rx);
  sg[x] = combine(sg[2 * x + 1] , sg[2 * x]);
}
// set the value at index 'idx' to v.
void update(ll x, ll lx, ll rx, ll idx, ll v) {
  if (lx == rx) {
    sg[x] = v;
    return;
  }
  ll mx = (lx + rx) / 2;
  if (idx <= mx) {
    update(2 * x, lx, mx, idx, v);
  } else {
    update(2 * x + 1, mx + 1, rx, idx, v);
  }
  sg[x] = combine(sg[2 * x + 1] , sg[2 * x]);
}
ll calc(ll x, ll lx, ll rx, ll l, ll r) {
  if (lx >= l && rx <= r)return sg[x];
  if (lx > r || rx < l)return garbage_val;
  ll mx = (lx + rx) / 2;
  return combine(calc(2 * x, lx, mx, l, r),
   calc(2 * x + 1, mx + 1, rx, l, r));
}
