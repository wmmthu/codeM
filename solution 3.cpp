#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>
using namespace std;

int main(){
    int m;
    cin >> m;
    bool hold[100001];
    memset(hold,false,100001);
    unordered_map<int,int> last_buy;
    unordered_map<int,int> last_use;
    bool sp[500001];
    memset(sp,false,500001);
    
    char input;
    int num;
    for(int i=1;i<=m;i++){
        cin >> input;
        if(input == '?'){
            sp[i] = true;
        }else if(input == 'I'){
            cin >> num;
            if(!hold[num]){
                hold[num] = true;
            }else{
                int last = last_buy[num];
                bool success = false;
                for(int j=last+1;j<i;j++){
                    if(sp[j]){
                        sp[j] = false;
                        success = true;
                        break;
                    }
                }
                if(!success){
                    cout << i; return 0;
                }
            }
            
            last_buy[num] = i;
        }else if(input == 'O'){
            cin >> num;
            if(hold[num]){
                hold[num] = false;
            }else{
                int last = last_use[num];
                bool success = false;
                for(int j=last+1;j<i;j++){
                    if(sp[j]){
                        sp[j] = false;
                        success = true;
                        break;
                    }
                }
                if(!success){
                    cout << i; return 0;
                }
            }
                
            last_use[num] = i;
        }
        
    }
    cout << "-1";
    return 0;
}