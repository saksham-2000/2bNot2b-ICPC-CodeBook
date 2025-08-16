// multiple source shortest path  O(n^3)

/* 
Given directed/undirected weighted graph.
Find the len. of shortest path b/w any pair
*/
for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
  if (d[i][k] < INF && d[k][j] < INF)
d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
}
// Algo works for negative weights (unlike dijsktra) but NOT negative cycles.
