#include <bits/stdc++.h>
using namespace std;

/*
    How many people mst be there in the room to make the probabilitu 100% that at least
    2 people in the room have same birthday
        => 367 (including February 29) else 366

    Probability = 50%
        => 23
*/


// General formula
int find(double prob){
    return  ceil( sqrt ( 2*365*log( 1 / (1-prob) ) ) );
}
