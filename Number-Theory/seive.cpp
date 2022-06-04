#include<bits/stdc++.h>
using namespace std;

int Prime[300000], nPrime = 0;
int mark[1000002]; // mark[i] = 0--> prime     marl[i] = 1---> not prime


void seive(int n){
    int i, j , limit = sqrt(n*1.0) + 2;

    mark[1] = 1; // 1 is not a prime so mark it
    
    for(int i = 4; i<=n; i+= 2 ) mark[i] = 1; // as all even numbers at not prime

    Prime[nPrime++] = 2;

    for(int i=3; i<= n; i+= 2){
        if(!mark[i]){
            Prime[nPrime++] = i; // i is prime and storing it in the Prime array

            if(i<=limit){  // we are taking to higher limit srqt of n as limit equals that
                for(j = i*i; j<=n; j += i*2) mark[j] = 1;   // j is not a prime and starting from i*i to overcome the overflow of i and //  j+= i*2 for  always -- > even + odd = even
            }
        }
    }

}

int main(){
    seive(1000000);

    for(int i=0; i<10000; i++){
        cout<< "Prime no "<< i+ 1<< " is: "<< Prime[i]<<endl;
    }
}
