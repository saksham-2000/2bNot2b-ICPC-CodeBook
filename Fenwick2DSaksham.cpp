struct Fenwick2D{
  vector<vector<ll>> data;
  ll sizeX, sizeY; // 1 Based-Indexing
  Fenwick2D(ll sizeX, ll sizeY){
    this->sizeX = sizeX,this->sizeY = sizeY;
    data.resize(sizeX + 1);
    for(ll i = 0; i <= sizeX; ++i){
      data[i].resize(sizeY);
    }
  }
  void update(ll x, ll y, ll val){
    while(x <= sizeX){
      ll y1 = y;
      while(y <= sizeY){
        data[x][y] += val,y += y & -y;
      }
      y = y1,x += x & -x;
    }
  }
  ll get(ll x, ll y){
    ll result = 0;
    while(x > 0){
      ll y1 = y;
      while(y > 0){
        result += data[x][y];
        y -= y & -y;
      }
      x -= x & -x,y = y1;
    }
    return result;
  }
};
