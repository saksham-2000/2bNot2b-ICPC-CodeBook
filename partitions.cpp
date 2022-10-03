/*

partition function p(n) represents the number of possible
partitions of a non-negative integer n.

p(n)=p(n−1)+p(n−2)−p(n−5)−p(n−7)+p(n−12)+p(n−15)+…

      (k=1) (k=-1) (k=2)  (k=-2) (k=3)   (k=-3) ... 

 eg: p(3) = 3  -> {0,1,2},{0,0,3},{1,1,1}

*/
ll penta1(ll x) {
  // for +ve k's
  return (x * (3 * x - 1)) / 2;
}

ll penta2(ll x) {
  // for -ve k's
  return (x * (3 * x + 1)) / 2;
}

vl partitions;

void calcPartitions(ll N1) {

// O(N1*sqrt(N1))

  partitions.assign(N1, 0);

  partitions[0] = 1;

  for (ll i = 1; i < N1; i++) {
    for (ll k = 1; penta1(k) <= i; k++) {
      if (k % 2) {

        partitions[i] += partitions[i - penta1(k)];
      } else {
        partitions[i] -= partitions[i - penta1(k)];
      }
    }
    for (ll k = 1; penta2(k) <= i; k++) {
      if (k % 2) {

        partitions[i] += partitions[i - penta2(k)];
      } else {
        partitions[i] -= partitions[i - penta2(k)];
      }
    }
    partitions[i] %= M;
    if (partitions[i] < 0)partitions[i] += M;
    // cout << i << " " << partitions[i] << endl;
  }
}
