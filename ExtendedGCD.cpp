ll gcd (ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}
ll extended_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1,y = 0;
        return a;
    } // finds one (xo,yo) s.t ax+by = gcd(a,b) 
    // general solution x=xo+k*(b/g),y=yo-k*(a/g) 
    ll x1, y1;
    ll d = extended_gcd(b, a % b, x1, y1);
    x = y1,y = x1 - y1 * (a / b);
    return d;
}
ll x, y;
// ax+my=1, take %m both sides.
g = extended_euclidean(a, m, x, y);
// finding [a]^-1 % m (m not necessarily prime)
if (g != 1) {
    cout << "No solution!";
}
else {
    x = (x % m + m) % m;
    cout << x << endl;
}
