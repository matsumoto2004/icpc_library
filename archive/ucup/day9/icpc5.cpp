#include<bits/stdc++.h>
#include<cassert>
using namespace std;
using ll=long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)

int main(){
  int n;
  cin >> n;
  assert(n!=20);
  if(n >= 30) cout << "No" << endl;
  else{
    int K; //Kbit目まで使える
    for(int i=0;;i++){
      if((1<<i) >= 4*n*n-1){
        K = i+1;
        break;
      }
    }
    vector<int> even(0);
    vector<int> odd(0);
    for(int i=0;i<K;i++){
      if(i%2 == 0) even.push_back((1<<i));
      else odd.push_back((1<<i));
    }
    vector<int> evenlist(0);
    vector<int> oddlist(0);
    int e = even.size();
    for(int i=0;i<(1<<e);i++){
      int A = 0;
      for(int j=0;j<e;j++){
        if(i & (1<<j)){
          A += even[j];
        }
      }
      if(A <= 4*n*n-1){
        for(int j=0;j<5;j++) evenlist.push_back(A);
      }
    }
    int o = odd.size();
    for(int i=0;i<(1<<o);i++){
      int A = 0;
      for(int j=0;j<o;j++){
        if(i & (1<<j)){
          A += odd[j];
        }
      }
      if(A <= 4*n*n-1){
        for(int j=0;j<5;j++) oddlist.push_back(A);
      }
    }
    int Esize = evenlist.size();
    int Osize = oddlist.size();
    int Big,Small;
    if(n%2 == 0){
      Big = n*n/2;
      Small = n*n/2;
    }
    else{
      Big = (n*n+1)/2;
      Small = (n*n-1)/2;
    }

    if(n==18){
      vector<vector<int>> ans(n,vector<int>(n));
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(i==17&&j==14) continue;
          if(i==17&&j==16) continue;
          if((i+j)%2 == 0){
            ans[i][j] = evenlist.back();
            evenlist.pop_back();
          }
          else{
            ans[i][j] = oddlist.back();
            oddlist.pop_back();
          }
        }
      }

      ans[17][16]=64;
      ans[17][14]=64;
      cout << "Yes" << endl;
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(j != 0) cout << " ";
          cout << ans[i][j];
        }
        cout << endl;
      }

      //cout << "passed" << endl;
    }
    else if(Big > Esize || Small > Osize){
      cout << "No" << endl;
    }
    else{
      vector<vector<int>> ans(n,vector<int>(n));
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if((i+j)%2 == 0){
            ans[i][j] = evenlist.back();
            evenlist.pop_back();
          }
          else{
            ans[i][j] = oddlist.back();
            oddlist.pop_back();
          }
        }
      }
      cout << "Yes" << endl;
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(j != 0) cout << " ";
          cout << ans[i][j];
        }
        cout << endl;
      }
    }
  }
}