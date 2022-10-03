set<ll>val[N];
 
vl arr[N];
 
vl ans(N);
 
void dfs(ll node, ll par) {
	ll mx = 0, id = 0;
	for (auto child : arr[node]) {
		if (child == par)continue;
		dfs(child, node);
		if (sz(val[child]) > mx) {
			mx = sz(val[child]);
			id = child;
		}
	}
	if (!id) {
		ans[node] = sz(val[node]);
		return;
	}
	swap(val[id], val[node]);
	for (auto child : arr[node]) {
		if (child == par)continue;
		for (auto d : val[child])val[node].insert(d);
		val[child].clear();
	}
	ans[node] = sz(val[node]);
}
 
