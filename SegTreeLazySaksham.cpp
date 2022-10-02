vector<ll> aa,sg,lazy;
const ll garbage_val = -1e18;
ll combine(ll x, ll y) {
  return max(x, y);
}
ll pass_on(ll x, ll y) {
  return x + y;
}
void push(ll x) {
  lazy[2 * x] = pass_on(lazy[2 * x], lazy[x]);
  lazy[2 * x + 1] = pass_on(lazy[2 * x + 1], lazy[x]);
  sg[2 * x] = pass_on(sg[2 * x], lazy[x]);
  sg[2 * x + 1] = pass_on(sg[2 * x + 1], lazy[x]);
  lazy[x] = 0;
}
void build(ll x, ll lx, ll rx) {
  if (lx == rx) {
    sg[x] = aa[lx];
    return;
  }
  ll mx = (lx + rx) / 2;
  build(2 * x, lx, mx);
  build(2 * x + 1, mx + 1, rx);
  sg[x] = combine(sg[2 * x + 1],sg[2 * x]);
}
// ADDING value 'v' to the range [l,r]
void update(ll x, ll lx, ll rx, ll l , ll r, ll v) {
  if (lx >= l && rx <= r) {
/* Making changes to lazy[x] along with sg[x],so lazy[x] 
stores info abt updates to 2x & 2x+1 */
    sg[x] += v,lazy[x] += v;
    return;
  }
  if (lx > r || rx < l)return;
  push(x);
  ll mx = (lx + rx) / 2;
  update(2 * x, lx, mx, l, r, v);
  update(2 * x + 1, mx + 1, rx, l, r, v);
  sg[x] = combine(sg[2 * x + 1],sg[2 * x]);
}
// finding max val. in [l,r]
ll calc(ll x, ll lx, ll rx, ll l, ll r) {
  if (lx >= l && rx <= r)return sg[x];
  if (lx > r || rx < l)return garbage_val;
  push(x);
  ll mx = (lx + rx) / 2;
  return combine(calc(2 * x, lx, mx, l, r),
    calc(2 * x + 1, mx + 1, rx, l, r));
}
