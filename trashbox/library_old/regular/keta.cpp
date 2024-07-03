long long keta(long long x){
  int y=0;
  while(x!=0){
    y++;
    x/=10;
  }
  return y;
}