for (int i = 0; i < k; ++i) {
    x[i] = a[i];
    for (int j = 0; j < i; ++j) {
        x[i] = r[j][i] * (x[i] - x[j]);

        x[i] = x[i] % p[i];
        if (x[i] < 0)
            x[i] += p[i];
    }
}
// if A is ai modulo (pi) (i from 0,k-1)
// then A = summation(xi*prod(i-1)) where prod(j) is p0*(p1)*......(pj) 
