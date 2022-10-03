struct query {
  ll l, r, idx, lb, rb, k;
};

int64_t gilbertOrder(int x, int y, int pow, int rotate) {
  if (pow == 0) {
    return 0;
  }
  int hpow = 1 << (pow - 1);
  int seg = (x < hpow) ? (
              (y < hpow) ? 0 : 3
            ) : (
              (y < hpow) ? 1 : 2
            );
  seg = (seg + rotate) & 3;
  const int rotateDelta[4] = {3, 0, 0, 1};
  int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
  int nrot = (rotate + rotateDelta[seg]) & 3;
  int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
  int64_t ans = seg * subSquareSize;
  int64_t add = gilbertOrder(nx, ny, pow - 1, nrot);
  ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
  return ans;
}

bool cmp(query a, query b) {
  // if (a.lb != b.lb)return a.lb < b.lb;
  // if (a.lb & 1)return a.rb > b.rb;

  // return a.rb < b.rb;
  return gilbertOrder(a.l, a.r, 21, 0) < gilbertOrder(b.l, b.r, 21, 0);
}
