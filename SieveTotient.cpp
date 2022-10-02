const ll N = 2e5 + 5;
ll phi[N],sp[N];
void fill_totient(ll N) { // totient(x): cnt of numbers <x rel. prime to x
  for (ll i = 2; i < N; i++)phi[i] = i;
    for (ll i = 2; i < N; i++) {
      if (phi[i] == i) {
        for (ll j = i; j < N; j += i) {
          phi[j] -= phi[j] / i;
        }
      }
    }
  }
  void fill_sieve(ll N) { // sp[x] : smallest prime factor of x
    for (ll i = 1; i < N; i++)sp[i] = i;
      for (ll i = 2; i < N; i++) {
        if (sp[i] == i) {
          for (ll j = i * i; j < N; j += i) {
            if (sp[j] == j)sp[j] = i;
          }
        }
      }
    }
