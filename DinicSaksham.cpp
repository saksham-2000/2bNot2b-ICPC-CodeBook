// #define S for MAXN, T is S+1 and use add_edge
struct dinic {
	struct edge {ll b, cap, flow, flip;};
	vector<edge> g[S+2];
	ll ans=0, d[S+2], ptr[S+2];

	void add_edge (ll a, ll b, ll cap) {
		g[a].push_back({b, cap, 0, g[b].size()});
		g[b].push_back({a, 0, 0, g[a].size()-1});
	}
	
	ll dfs (ll u, ll flow=LLONG_MAX) {
		if (u==S+1 || !flow) return flow;
		while (++ptr[u] < g[u].size()) {
			edge &e = g[u][ptr[u]];
			if (d[e.b] != d[u]+1) continue;
			if (ll pushed = dfs(e.b, min(flow, e.cap-e.flow))) {
				e.flow += pushed;
				g[e.b][e.flip].flow -= pushed;
				return pushed;
			}
		}
		return 0;
	}

	void calc() {
		do {
			vector<ll> q {S};
			memset(d, 0, sizeof d);
			ll i = -(d[S] = 1);
			while (++i<q.size() && !d[S+1])
				for (auto e: g[q[i]])
					if (!d[e.b] && e.flow<e.cap) {
						q.push_back(e.b);
						d[e.b] = d[q[i]]+1;
					}

			memset(ptr, -1, sizeof ptr);
			while(ll pushed=dfs(S)) ans+=pushed;
		} while (d[S+1]);
	}
};
