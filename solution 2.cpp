#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n,x;
    cin >> n;
    vector<int> a;
    int low = 0;
    int mei = 0;
    cin >> mei;
    for(int i=1;i<n;i++){
        cin >> x;
        if(x <= mei) low ++;
    }
    
    int time = 0;
    while(low > 0){
        time ++;
        low --;
        low /= 2;
    }
    
    cout << time;
    return 0;
}