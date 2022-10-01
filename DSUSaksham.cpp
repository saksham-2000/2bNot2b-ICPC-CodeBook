const ll N=2e5+5;
ll par[N],ra[N];

ll find(ll x) {
while(x!=par[x])x=par[x];
return x;
}
void unio(ll a, ll b) { // union by rank
  a = find(a), b = find(b);
  if (a == b)return;
  if(ra[a]<ra[b])swap(a,b);
  par[b]=a,ra[a]+=ra[b];
}
