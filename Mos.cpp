const int B=350;

struct Query{
  int l,r,idx;
};

bool cmp(Query& a,Query& b){
  if(a.l/B!=b.l/B){
    return a.l/B<b.l/B;
  }
  return ((a.l/B)&1)?(a.r>b.r):a.r<b.r;
}

vector<Query>Q(q);
 sort(Q.begin(),Q.end(),cmp);

for(ll i=0,L=1,R=0;i<q;i++){
  while(L>Q[i].l)update(--L,1);
  while(R<Q[i].r)update(++R,1);
  while(L<Q[i].l)update(L++,-1);
  while(R>Q[i].r)update(R--,-1);
 
  fin[Q[i].idx]=ans;
}
