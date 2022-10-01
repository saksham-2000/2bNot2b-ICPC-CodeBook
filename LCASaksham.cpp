const ll N=2e5+5;
ll lca[N][25],dep[N];
vector<ll>arr[N];
// put par=root when calling dfs function
void dfs(ll node, ll par) { 
  lca[node][0] = par;
  for (ll i = 1; i < 25; i++) {
    lca[node][i] = lca[lca[node][i - 1]][i - 1];
  }
  for (auto child : arr[node]) {
    if (child == par)continue;
    dep[child] = dep[node] + 1;
    dfs(child, node);
  }
}
ll find_lCA(ll u, ll v) {
  if (dep[u] < dep[v])swap(u, v);
  ll dif = dep[u] - dep[v];
  for (ll i = 24; i >= 0; i--) {
    if ((1ll << i) & dif) {
      u = lca[u][i];
    }
  }
  if (u == v)return v;
  for (ll i = 24; i >= 0; i--) {
    if (lca[u][i] != lca[v][i]) {
      u = lca[u][i], v = lca[v][i];
    }
  }
  return lca[u][0];
}
