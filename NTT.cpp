const int mod = 998244353;  // 119 * 2^23 + 1
const int root = powM(3,119,mod);  // (primitive root)^(odd part in mod-1)
const int root_1 = powM(root,mod-2,mod); // inverse of root
const int root_pw = 1 << 23;

const int mod = 7340033; // 7 * 2^20 + 1
const int root = powM(5,7,mod);  // (primitive root)^(odd part in mod-1)
const int root_1 = powM(root,mod-2,mod); // inverse of root
const int root_pw = 1 << 20; 

long long inverse(long long x, int mod) {
  long long res = 1;
  int e = mod - 2;
  while (e) {
    if (e & 1)res = res * x % mod;
    x = x * x % mod,e >>= 1;
  }
  return res;
}

void fft(vector<int> & a, bool invert) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1)j ^= bit;
    j ^= bit;
    if (i < j)swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    int wlen = invert ? root_1 : root;
    for (int i = len; i < root_pw; i <<= 1)wlen = (int)(1LL * wlen * wlen % mod);
    for (int i = 0; i < n; i += len) {
      int w = 1;
      for (int j = 0; j < len / 2; j++) {
        int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
        a[i+j] = u + v < mod ? u + v : u + v - mod;
        a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
        w = (int)(1LL * w * wlen % mod);
      }
    }
  }
  if (invert) {
    int n_1 = inverse(1ll*n, mod);
    assert((n_1*1LL* n )% mod == 1);
    for (int & x : a)x = (int)(1LL * x * n_1 % mod);
  }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
  vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < a.size() + b.size()) n <<= 1;
  fa.resize(n),fb.resize(n);
  fft(fa, false),fft(fb, false);
  for (int i = 0; i < n; i++)fa[i] = (int)(1LL * fa[i] * fb[i] % mod);
  fft(fa, true);
  return fa;
}
