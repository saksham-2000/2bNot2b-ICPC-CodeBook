const ll N=2e5+5;
ll par[N],ra[N];

ll find(ll x) {
if(x==par[x])return x;
return x=find(par[x]); // path compression
}
void unio(ll a, ll b) { 
  a = find(a), b = find(b);
  if (a == b)return;
  if(ra[a]<ra[b])swap(a,b);
  par[b]=a,ra[a]+=ra[b]; // union by rank/size
}

/*

using any one optimization will yield O(logn)

However, using BOTH optimizations i,e path compression + union by size/rank will yield O(alpha(n)) complexity 
where alpha = inverse ackermann function (does not exceed 4 for n< 10^600 lol)

if you can't use union by rank directly due to nature of the problem (Painting subarrays offline) 
(if initially ww need to set par[v] = v+1 for eg)
 maintain an additional DS to store this information and don't compromise on not using union by rank

*/
