struct TRIE {
  int cnt = 0;
  TRIE* child[2];
  TRIE() {
    memset(child, 0, sizeof(child));
  }
};

TRIE* root;

void insert(int x) {
  TRIE* cur = root;
  for (int i = 30; i >= 0; i--) {
    int bit = (x >> i) & 1;
    if (cur->child[bit] == NULL) {
      cur->child[bit] = new TRIE();
    }
    cur = cur->child[bit];
    (cur->cnt)++;
  }
}

void remove(int x) {
  TRIE* cur = root;
  for (int i = 30; i >= 0; i--) {
    int bit = (x >> i) & 1;
    if (cur->child[bit] == NULL) {
      cur->child[bit] = new TRIE();
    }
    cur = cur->child[bit];
    (cur->cnt)--;
  }
}

int calc(int val) {
  int ans = 0;
  TRIE* cur = root;
  for (int i = 30; i >= 0; i--) {
    int b1 = (val >> i) & 1;
    if (cur->child[1 - b1] != NULL && (cur->child[1 - b1])->cnt > 0) {
      ans += (1ll << i);
      cur = cur->child[1 - b1];
    } else cur = cur->child[b1];
  }
  return ans;
}
