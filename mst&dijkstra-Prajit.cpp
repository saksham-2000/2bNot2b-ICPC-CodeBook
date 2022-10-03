vector<vector<pair<ll,ll>>> adj;
vector<ll> parent,rk;
vector<pair<ll,pair<ll,ll>>> edge,tp;

void dijkstra(ll s, vector<ll> & d, vector<ll> & p) {
    ll n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    set<pair<ll, ll>> q;
    q.insert({0, s});
    while (!q.empty()) {
        ll v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}

ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap(a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            rk[a]++;
    }
}

void solve() {
    ll n; cin>>n;
    ll a[n][n];
    FOR(i,n) FOR(j,n) cin>>a[i][j];

    adj.clear(); adj.resize(n); tp.clear();
    parent.clear(); rk.clear(); edge.clear();
    FOR(i,n) { parent.pb(i); rk.pb(0); } 
    
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<n; j++) {
            edge.pb(mp(a[i][j],mp(i,j)));
        }
    }
    sort(all(edge));
    for(auto p : edge) {
        if(find_set(p.se.fi)!=find_set(p.se.se)) {
            adj[p.se.fi].pb(mp(p.se.se,p.fi));
            adj[p.se.se].pb(mp(p.se.fi,p.fi));
            tp.pb(p);
            union_sets(p.se.fi,p.se.se);
        }
    }
}
