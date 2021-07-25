#include <bits/stdc++.h>
using namespace std;

long long power(long long x,long long n,long long p){
    if(n==0){
        return 1;
    }
    if(n==1){
        return x % p;
    }
    long long temp = power(x,n/2,p);
    temp = (temp % p * temp % p) % p;
    if(n%2==0){
        return temp;
    }
    return (x % p * temp % p) % p;
}