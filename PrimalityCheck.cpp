
// Most basic O(sqrt(n))
bool isPrimeBasic(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}


// Miller Rabin O(logn)

long long powM(long long a, long long b, long long m){  // BINARY EXPO
  if(b<0)return 0;
  long long ans = 1;
  while (b){
    if (b & 1)ans = ans * a %m;
    a = a * a %m,b >>= 1;
  }
  return ans;
}

bool check_composite(long long n, long long a, long long d, long long s) {
    long long x = powM(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(long long n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    long long s = 0;
    long long d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        long long a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}
