#include <iostream>
#include <climits>
using namespace std;

int main()
{
	int n,m;
    long long diff = LLONG_MAX;
    int a[1000], b[1000];
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    cin >> m;
    for(int i=0;i<m;i++) cin >> b[i];
    
    for(int i=0;i<=m-n;i++){
        long long tmp = 0;
        for(int k=0;k<n;k++){
            tmp += (a[k] - b[i+k]) * (a[k] - b[i+k]);
            if(tmp > diff) break;
        }
        if(tmp < diff) diff = tmp;
    }
    cout << diff;
    
    return 0;
}