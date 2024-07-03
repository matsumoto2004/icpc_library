std::vector<std::pair<long long,long long>> arg_sort(std::vector<std::pair<long long,long long>> A,std::pair<long long,long long> d = {1,0}){
    // Copyright (c) 2023 0214sh7
    // https://github.com/0214sh7/library/
    long long N = A.size();
    assert(d.first != 0 || d.second != 0);
    long long g = std::gcd(d.first,d.second);
    d.first/=g;d.second/=g;
    A.push_back(d);
    std::sort(A.begin(),A.end(),[&](std::pair<long long,long long> x, std::pair<long long,long long> y){
        assert(x.first != 0 || x.second != 0);
        assert(y.first != 0 || y.second != 0);
        
        long long a,b;
        if(x.first>0 && x.second==0){
            a=0;
        }else if(x.first>0 && x.second>0){
            a=1;
        }else if(x.first==0 && x.second>0){
            a=2;
        }else if(x.first<0 && x.second>0){
            a=3;
        }else if(x.first<0 && x.second==0){
            a=4;
        }else if(x.first<0 && x.second<0){
            a=5;
        }else if(x.first==0 && x.second<0){
            a=6;
        }else{
            a=7;
        }
        
        if(y.first>0 && y.second==0){
            b=0;
        }else if(y.first>0 && y.second>0){
            b=1;
        }else if(y.first==0 && y.second>0){
            b=2;
        }else if(y.first<0 && y.second>0){
            b=3;
        }else if(y.first<0 && y.second==0){
            b=4;
        }else if(y.first<0 && y.second<0){
            b=5;
        }else if(y.first==0 && y.second<0){
            b=6;
        }else{
            b=7;
        }
        
        if(a!=b){
            return (a<b);
        }
        
        if(a%2==0){
            return (std::abs(x.first+x.second) < std::abs(y.first+y.second));
        }
        
        if(y.first*x.second != x.first*y.second){
           return (y.first*x.second < x.first*y.second);
        }
        
        return abs(x.first) < abs(y.first);
    });
    
    std::vector<std::pair<long long,long long>> B(N);
    for(int i=0;i<N+1;i++){
        if(A[i]==d){
            for(int j=i+1;j<N+1;j++){
                B[j-i-1]=A[j];
            }
            for(int j=0;j<i;j++){
                B[N-i+j]=A[j];
            }
            break;
        }
    }
    
    return B;
}
使用例
実行コード
#include <bits/stdc++.h>


std::vector<std::pair<long long,long long>> arg_sort(std::vector<std::pair<long long,long long>> A,std::pair<long long,long long> d = {1,0}){/*省略*/}


int main(void){
    
    long long N = 12;
    
    std::vector<std::pair<long long,long long>> A={
        {-3,0},
        {-1,-2},
        {1,2},
        {0,-3},
        {3,0},
        {-2,-1},
        {-2,1},
        {1,-2},
        {2,1},
        {2,-1},
        {0,3},
        {-1,2}
    };
    
    //Aを(1,0)を基準にソート
    A = arg_sort(A);
    for(int i=0;i<N;i++){
        std::cout << "(" << A[i].first << "," << A[i].second << ")" << " "; 
    }
    std::cout << std::endl;
    
    //Aを(-1,1)を基準にソート
    A = arg_sort(A,{-1,1});
    for(int i=0;i<N;i++){
        std::cout << "(" << A[i].first << "," << A[i].second << ")" << " "; 
    }
    std::cout << std::endl;
    
    return 0;
}
