const int N = 1e6 + 5;

// O(NloglogN)
  bool is_prime[N];
  void basic_sieve(int N) { 
    for (long long i = 1; i < N; i++)is_prime[i] = true;
      for (long long i = 2; i < N; i++) {
        if (is_prime[i]) {
          for (long long j = i * i; j < N; j += i) {
            if (is_prime[j])is_prime[j] = false;
          }
        }
      }
    }

// O(N)
int sp[N];
void linear_sieve(int N){
  // sp[x] : smallest prime factor of x
  vector<int>pr;
  for(int i=2;i<N;i++){
      if(sp[i]==0){
        sp[i]=i;
        pr.push_back(i);
      }
        for(int j=0;j<pr.size() && i*pr[j]<N;j++){
            sp[i*pr[j]]=pr[j];
            if(pr[j] == sp[i])break;
        }
  }
}

int phi[N];
void totient(int N) { // totient(x): cnt of numbers <x rel. prime to x
  for (long long i = 2; i < N; i++)phi[i] = i;
    for (long long i = 2; i < N; i++) {
      if (phi[i] == i) {
        for (long long j = i; j < N; j += i) {
          phi[j] -= phi[j] / i;
        }
      }
    }
  }

