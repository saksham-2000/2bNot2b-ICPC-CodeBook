// find shortest dist. from v to all other vertices.
// works for negative weights unlike dijsktra
// O(n*m)
void solve(){
    vector<int> d (n, INF);
    d[v] = 0;
    while(1){
        bool any = false;
        for (int j=0; j<m; ++j){
         if (d[e[j].a] >= INF)continue; 
  // to avoid neg. edge weight cases.
         if (d[e[j].b] > d[e[j].a] + e[j].cost){
          d[e[j].b] = d[e[j].a] + e[j].cost;
            any = true;
          }
        }
      if (!any) break;
    }
}
