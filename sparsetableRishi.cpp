// usage:
//   auto fun = [&](ll i, ll j) { return min(i, j); };
//   sparseTable<ll, decltype(fun)> st(a, fun);
// or:
//   sparseTable<ll> st(a, [&](ll i, ll j) { return min(i, j); });

template <typename T, class F = function<T(const T&, const T&)>>
struct sparseTable {
    ll n;
    vector<vector<T>> x;
    F func;

    sparseTable(const vector<T>& a, const F& f) : func(f) {
        n = static_cast<ll>(a.size());
        ll l = 32 - __builtin_clz(n);
        x.resize(l);
        x[0] = a;
        for (ll j = 1; j < l; j++) {
            x[j].resize(n - (1 << j) + 1);
            for (ll i = 0; i <= n - (1 << j); i++) {
                x[j][i] = func(x[j - 1][i], x[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T get(ll u, ll v) const {
        assert(0 <= u && u <= v && v <= n - 1);
        ll lg = 32 - __builtin_clz(v - u + 1) - 1;
        return func(x[lg][u], x[lg][v - (1 << lg) + 1]);
    }
};
