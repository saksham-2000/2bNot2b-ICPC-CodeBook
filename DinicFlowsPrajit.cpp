struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;
    vector<ll> used;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
        used.assign(n,0);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }

    ll dfs1(ll v) {
        used[v] = 1;
        for(auto it : adj[v]) {
            if(used[edges[it].u]) continue;
            if(edges[it].cap - edges[it].flow > 0) {
                dfs1(edges[it].u);
            }
        }
    }
};

void solve() {
    ll n,m; cin>>n>>m;
    ll t = n + m, s = t, d = t+1;
    Dinic w(t+2,s,d);

    vector<vector<ll>> adj(t+2);
    FOR(i,n) {
        ll x;
        w.add_edge(s,i,1);
    }

    ll temp = w.flow();

    /* 1
    vector<pair<ll,ll>> ans;
    ll sz = w.edges.size();
    ll used[t+2] = {0};
    for(ll i=0; i<sz; i += 2) {
        ll tv = w.edges[i].v, tu = w.edges[i].u;
        if(tv != s && tu != d && w.edges[i].flow == 1) {
            used[tv] = 1;
            used[tu] = 1;
            ans.pb({tv,tu-n});
        }
    }
    */

    /* 2 [for s-t mincut]
    w.dfs1(t);
    ll sz = w.edges.size();
    for(ll i=0; i<sz; i += 2) {
        if(w.used[w.edges[i].v] && w.used[w.edges[i].u]==0 && w.edges[i].cap==w.edges[i].flow) {
            res.pb(id[{w.edges[i].v,w.edges[i].u}]);
        }
    }*/
}
