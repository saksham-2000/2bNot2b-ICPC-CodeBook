ll const MAXN = 5e6+100;
//ll tr[MAXN][2];
vector<vector<ll>> tr;
vector<ll> ct;
ll n,cr;
vector<ll> mn;
//vector<vector<ll>> g(MAXN);

void add(ll num, ll ind) {
    ll v = 0;
    for(ll i=30; i>=0; i--) {
        ll bit = (num>>i)&1;
        if(!tr[v][bit]) { tr[v][bit] = cr++; tr.pb(vector<ll> (2,0)); ct.pb(0); }
        v = tr[v][bit];
        ct[v]++;
    }
}

void remove(ll num) {
    ll v = 0;
    for(ll i=30; i>=0; i--) {
        ll bit = (num>>i)&1;
        ct[tr[v][bit]]--;
        ll s = tr[v][bit];
        if(!ct[tr[v][bit]]) tr[v][bit] = 0;
        v = s;
    }
}

void func(ll v, ll b) {
    ll l = tr[v][0], r = tr[v][1];
    if(l) func(l,b-1);
    if(r) func(r,b-1);
    
    if(l>0 && r>0) {
        mn[v] = (1LL<<b) + min(mn[r],mn[l]); 
    }
    else mn[v] = mn[max(l,r)]; 
}

void solve() {  
    ll n; cin>>n;
    cr = 1; 
    tr.pb(vector<ll> (2,0));
    ct.pb(0);
    FOR(i,n) {
        ll x; cin>>x;
        add(x,i+1);
    }
    mn.assign(cr+1,0);
    func(0LL,30LL);
    cout<<mn[0];    
}
