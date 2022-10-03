ll heavy[N], head[N], dep[N], sub[N], pos[N], pa[N], val[N];

vl arr[N];

ll c_time = 0;

ll dfs(ll node, ll par) {
  sub[node] = 1;
  pa[node] = par;
  ll mx = 0;
  for (auto child : arr[node]) {
    if (child == par)continue;
    dep[child] = dep[node] + 1;
    ll cs = dfs(child, node);
    sub[node] += cs;
    if (cs > mx) {
      mx = cs;
      heavy[node] = child;
    }
  }
  return sub[node];
}


void euler(ll node, ll par, ll boss) {
  a.pb(val[node]);
  pos[node] = c_time;
  c_time++;
  head[node] = boss;
  if (heavy[node])euler(heavy[node], node, boss);
  for (auto child : arr[node]) {
    if (par == child)continue;
    if (child != heavy[node]) {
      euler(child, node, child);
    }
  }
}

ll ans = 0;

void solve(ll u, ll v, ll q_type) {

  while (1) {
    ll x = head[u], y = head[v];
    if (x == y) {
      ll p1 = pos[u], p2 = pos[v];
      if (p1 > p2)swap(p1, p2);
      if (q_type == 2) {
        ans += calc(1, 0, n - 1, p1, p2);
        cout << ans << endl;
      }
      else update(1, 0, n - 1, p1, p2);
      return;
    }
    if (dep[x] > dep[y]) {
      ll p1 = pos[x], p2 = pos[u];
      if (q_type == 2)ans += calc(1, 0, n - 1, p1, p2);
      else update(1, 0, n - 1, p1, p2);
      u = pa[x];
    } else {
      ll p1 = pos[y], p2 = pos[v];
      if (q_type == 2)ans += calc(1, 0, n - 1, p1, p2);
      else update(1, 0, n - 1, p1, p2);
      v = pa[y];
    }

  }
}
