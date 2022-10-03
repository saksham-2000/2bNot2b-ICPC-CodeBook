int n, l;
vector<vector<pair<int,int>>> adj;
 
int timer;
vector<int> tin, tout;
vector<vector<int>> up,mn,mx;
 
void dfs(int v, int p, int c)
{
    tin[v] = ++timer;
    up[v][0] = p;
    mn[v][0] = c;
    if(c==INF) mx[v][0] = 0;
    else mx[v][0] = c;
 
    for (int i = 1; i <= l; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
        mn[v][i] = min(mn[v][i-1],mn[up[v][i-1]][i-1]);
        mx[v][i] = max(mx[v][i-1],mx[up[v][i-1]][i-1]); 
    }
 
    for (auto u : adj[v]) {
        if (u.fi != p) dfs(u.fi, v, u.se);
    }
 
    tout[v] = ++timer;
}
 
bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
 
pair<int,int> func(int v, int u) {
    
    int p=INF,q=0;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)) {
            p = min(p,mn[u][i]);
            q = max(q,mx[u][i]);
            u = up[u][i];
        }
    }    
    p = min(p,mn[u][0]);
    q = max(q,mx[u][0]);
    return {p,q};
}
 
pair<int,int> lca(int u, int v)
{
    if (is_ancestor(u, v)) {
        return func(u,v);
    }
        
    if (is_ancestor(v, u)) {
        return func(v,u);
    }
        
    
    pair<int,int> p1,p2;
    p1 = func(u,v); p2 = func(v,u);
 
    return {min(p1.fi,p2.fi),max(p1.se,p2.se)};
}
 
void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    mn.assign(n, vector<int>(l + 1));
    mx.assign(n, vector<int>(l + 1));
    dfs(root, root, INF);
}
 
void solve() {
    cin>>n;
    adj.resize(n);
    FOR(i,n-1) {
        int a,b,c; cin>>a>>b>>c;
        a--; b--;
        adj[a].pb(mp(b,c)); adj[b].pb(mp(a,c));
    }
    preprocess(0);
    int k; cin>>k;
    while(k--) {
        int l,r; cin>>l>>r; l--; r--;
        pair<int,int> pp = lca(l,r);
        cout<<pp.fi<<" "<<pp.se<<"\n";
    }
}
