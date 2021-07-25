#include <bits/stdc++.h>
using namespace std;

vector<int> prime(1e6,1);

void sieve(){
    for(long long i=2;i<1e6;i+=2){
        prime[i] = 0;
    }
    prime[0] = prime[1] = 0;
    prime[2] = 1;
    for(long long i=3;i*i<1e6;i+=2){
        if(prime[i]){
            for(long long j=i*i;j<1e6;j+=i){
                prime[j] = 0;
            }
        }
    }
}