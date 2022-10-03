void solve(ll u, ll v) {

  while (1) {
    ll x = head[u], y = head[v];
    if (x == y) {
      ll p1 = pos[u], p2 = pos[v];
      if (p1 > p2)swap(p1, p2);
      chmax(ans, calc(1, 0, n - 1, p1 + 1, p2));
      cout << ans << endl;
      return;
    }
    if (dep[x] > dep[y]) {
      ll p1 = pos[x], p2 = pos[u];
      chmax(ans, calc(1, 0, n - 1, p1, p2));

      u = pa[x];
    } else {
      ll p1 = pos[y], p2 = pos[v];
      chmax(ans, calc(1, 0, n - 1, p1, p2));
      v = pa[y];
    }

  }
}
