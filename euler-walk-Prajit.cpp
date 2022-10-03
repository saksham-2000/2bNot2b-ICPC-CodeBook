vector<vector<ll>> adj;
vector<ll> tour,vis;
vector<vector<ll>> trav;

ll till;
ll dfs(ll u) {
    vis[u] = 1;
    tour.pb(u);
    trav[u][0] = till;
    till++;
    
    for(ll v : adj[u]) {
        if(vis[v]==0) {
            ll tt = dfs(v);
            tour.pb(tt);
            trav[v][1] = till; till++;
        }
    }
    return u;
}

void solve() {
    ll n; cin>>n;
    
    adj.resize(n+1); 
    vis.assign(n+1,0);
    trav.assign(n+1,vector<ll> (2,-1));
    till = 0;
    tour.clear();
    
    vector<pair<ll,ll>> paths;
    FOR(i,n-1) {
        ll x,y; cin>>x>>y;
        x--; y--;
        adj[x].pb(y);
        adj[y].pb(x);
        paths.pb(mp(x,y));
    }
 
    ll t_val = dfs(0);  
    trav[t_val][1] = till;
    tour.pb(0);
    ll sz = tour.size();
    
    t.assign(4*sz,0);
    lazy.assign(4*sz,0);
    
    // build using some array
    ll arr[sz];
    build(arr,1,0,sz-1);

    ll q; cin>>q;
    ll tsum = 0;
    while(q--) {
        ll k,alb,add; cin>>k>>alb>>add;
        pair<ll,ll> p = paths[alb-1];
        ll st,des;
        if(k==1) st = p.fi; else st = p.se;
        if(k==1) des = p.se; else des = p.fi;
            
        update(1,0,sz-1,trav[st][0],trav[st][1],add);
    }
    for(ll i=0; i<n; i++) {
        cout<<query(1,0,sz-1,trav[i][0],trav[i][0])+tsum<<"\n";
    }    
}
