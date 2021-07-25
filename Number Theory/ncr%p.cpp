#include <bits/stdc++.h>
using namespace std;

const int p = 1000000007;

int mpow(int base, int exp = p-2 , int mod = p) {
    base %= mod;
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

const int n = 1e5;
int fact[n],invfact[n];

void init(){
    fact[0] = 1;
    int i;
    for(i=1;i<n;i++){
        fact[i] = i * fact[i-1] % p;
    }
    i--;
    invfact[i] = mpow(fact[i],p-2,p);
    for(i--;i>=0;i--){
        invfact[i] = invfact[i+1] * (i+1) % p;
    }
}