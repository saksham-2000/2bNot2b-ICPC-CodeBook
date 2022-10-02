const int nax=20;
int basis[nax]; // basis[i] keeps the mask of the vector whose f value is i
int basis_size; // Current size of the basis
void insertVector(int mask) {
  for (int i = 0; i < nax; i++) {
    if ((mask & 1 << i) == 0) continue; // continue if i != f(mask)
    if (!basis[i]) { // If there is no basis vector with the i'th bit set, then insert this vector into the basis
      basis[i] = mask;
      ++basis_size;
      return;
    }
    mask ^= basis[i]; // Otherwise subtract the basis vector from this vector
  }
}
