struct Fenwick2D {
  vector<vector<int>> bit;
  int n, m; // 1 Based indexing
  Fenwick2D(int n,int m){
    this->n=n,this->m=m;
      bit.assign(n+1,vector<int>(m+1,0));
  }
  int sum(int x, int y) {
    int ret = 0;
    for (int i = x; i > 0; i = (i & (i + 1)) - 1)
      for (int j = y; j > 0; j = (j & (j + 1)) - 1) ret += bit[i][j];
    return ret;
  }
  void update(int x, int y, int delta) {
    for (int i = x; i <=n; i = i | (i + 1))
      for (int j = y; j <=m; j = j | (j + 1)) bit[i][j] += delta;
  }
};
