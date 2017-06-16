#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

long long nums[10];


// times of base (1~9) as first in 1,...,n
long long helper1(int n, int base){
    long long nums = 0;
    if(n <= 0) return 0;

    int t = n;
    int low = 1;
    while(t >= 10) {
        t /= 10;
        low *= 10;
    }

    if(t == base){
      nums += (n - low* t + 1);
      nums += helper1(low-1,base);
    }else if (t > base){
        nums = helper1(low * (base+1) - 1, base);
    }else{
        nums = helper1(low-1,base);
    }
    
    return nums;
}

int firstBit(int n){
    while(n >= 10) n /= 10;
    return n;
}

// l=1, r= n
vector<long long> helper2(int n){
    vector<long long> ret(10,0);
    if(n <= 0) return ret;
    
    int sqrt_n = sqrt(n);
    for(int i=1;i<=sqrt_n;i++){
        int t = firstBit(i);
        ret[t] += n / i;
        
        int l = n / (i+1);
        int r = n / i;
        
        if(r == i) continue;
        for(int k=1;k<=9;k++){
            ret[k] += (helper1(r,k) - helper1(l,k)) * i;
        }

    }
    
    return ret;
}


int main(){
    int l,r;
    cin >> l >> r;
    
    vector<long long> a = helper2(l-1);
    vector<long long> b = helper2(r);
    
    
    for(int i=1;i<=9;i++){
        cout << b[i] - a[i] << endl;
    }
    return 0;
}