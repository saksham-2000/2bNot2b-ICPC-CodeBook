template <class T>
struct segtree {
    ll n; T ret;
    vector<T> t;
    T unite(T x, T y) {
        return x + y;
    }// change unite, ret accordingly, this is for sum query
    void build(vector<T> &arr, ll v, ll tl, ll tr) {
        if (tl == tr) {
            t[v] = arr[tl];
        } else {
            ll tm = (tl + tr) / 2;
            build(arr, (2 * v), tl, tm);
            build(arr, (2 * v) + 1, tm + 1, tr);
            t[v] = unite(t[(2 * v)], t[(2 * v) + 1]);
        }
    }
    void modify(ll v, ll tl, ll tr, ll pos, T val) {
        if(tl == tr) {
            t[v] = val;
            return;
        }
        ll tm = (tl + tr) / 2;
        if(pos <= tm)
            modify((2 * v), tl, tm, pos, val);
        else
            modify((2 * v) + 1, tm + 1, tr, pos, val);
        t[v] = unite(t[(2 * v)], t[(2 * v) + 1]);
    }
    T get(ll v, ll tl, ll tr, ll l, ll r) {
        if(tl > r || tr < l)
            return ret;
        if(tl >= l && tr <= r)
            return t[v];
        ll tm = (tl + tr) / 2;
        return unite(get(2 * v, tl, tm, l, r), get((2 * v) + 1, tm + 1, tr, l, r));
    }
    void modify(ll pos, T val) {
        modify(1, 0, n - 1, pos, val);
    }
    T get(ll l, ll r) {
        return get(1, 0, n - 1, l, r);
    }
    segtree(ll _n) {
        n = _n;
        ret = 0;
        t.resize(4 * n + 5);
    }
    segtree(vector<T> &A) {
        n = (ll)A.size();
        ret = 0;
        t.resize(4 * n + 5);
        build(A, 1, 0, n - 1);
    }
};
