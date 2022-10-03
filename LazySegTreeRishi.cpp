// Change -> unite, push, modify and ret


template<class T, class M>
struct lazy_segtree {
    ll n; T ret;
    vector<T> t;
    vector<M> lazy;
    T unite(T x, T y){
        return x + y;
    }
    void push(ll v, ll tl, ll tm, ll tr) {
        t[2 * v] += lazy[v];
        t[(2 * v) + 1] += lazy[v];
        lazy[2 * v] += lazy[v];
        lazy[(2 * v) + 1] += lazy[v];
        lazy[v] = 0;
    }

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
    void modify(ll v, ll tl, ll tr, ll l, ll r, ll val) {
        if(tl > r || tr < l)
            return;
        if(tl >= l && tr <= r){
            t[v] += val;
            lazy[v] += val;
            return;
        }
        ll tm = (tl + tr) / 2;
        push(v, tl, tm, tr);
        modify((2 * v), tl, tm, l, r, val);
        modify((2 * v) + 1, tm + 1, tr, l, r, val);
        t[v] = unite(t[(2 * v)], t[(2 * v) + 1]);
    }
    T get(ll v, ll tl, ll tr, ll l, ll r) {
        if(tl > r || tr < l)
            return ret;
        if(tl >= l && tr <= r)
            return t[v];
        ll tm = (tl + tr) / 2;
        push(v, tl, tm, tr);
        return unite(get((2 * v), tl, tm, l, r), get((2 * v) + 1, tm + 1, tr, l, r));
    }
 
    void modify(ll l, ll r, ll val){
        modify(1, 0, n - 1, l, r, val);
    }
 
    T get(ll l, ll r){
        return get(1, 0, n - 1, l, r);
    }

    lazy_segtree(ll _n) {
        n = _n;
        ret = 0;
        t.resize(4 * n + 5);
        lazy.resize(4 * n + 5);
    }
    lazy_segtree(vector<T> &A) {
        n = (ll)A.size();
        ret = 0;
        t.resize(4 * n + 5);
        lazy.resize(4 * n + 5);
        build(A, 1, 0, n - 1);
    }
};
