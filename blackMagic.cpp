#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>set_t;
typedef cc_hash_table<int, int> umap_t;
#include <ext/rope>
using namespace __gnu_cxx;
int main() {
  rope<char> r[2];
  r[1] = r[0];  // persistenet
  string t = "abc";
  r[1].insert(0, t.c_str());
  r[1].erase(1, 1);
  cout << r[1].substr(0, 2);
}
