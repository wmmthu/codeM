#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool dfs(int target, int pos, string& path, bool* used, bool* fail, int n, int* a, int* b)
{
    if(pos == target){
        return true;
    }
    
    if(fail[pos]) return false;
    
    bool success = false;
    int newPos = pos + a[pos];
    if(newPos >= 0 && newPos < n && !used[newPos]){
        used[newPos] = true;
        path += "a";
        if(dfs(target, newPos, path, used, fail, n, a, b)){
            used[newPos] = false;
            return true;
        }
        used[newPos] = false;
        path = path.substr(0,path.size()-1);
    }
    
    
    newPos = pos + b[pos];
    if(newPos >= 0 && newPos < n && !used[newPos]){
        used[newPos] = true;
        path += "b";
        if(dfs(target, newPos, path, used, fail, n, a, b)){
            used[newPos] = false;
            return true;
        }
        used[newPos] = false;
        path = path.substr(0,path.size()-1);
    }
    
    fail[pos] = true;
    return false;
}

int main(){
    int n;
    cin >> n;
    int a[100000];
    int b[100000];
    bool used[100000];
    bool fail[100000];
    used[0] = true;
    
    memset(a,0,100000);
    memset(b,0,100000);
    memset(used,false,100000);
    memset(fail,false,100000);
    
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    
    string path = "";
    if(dfs(n-1,0,path,used,fail,n,a,b)){
        int pos = 0;
        used[0] = false;
        for(int i=0;i<path.size();i++){
            if(path[i] == 'b'){
                memset(fail,false,100000);
                string tmp;
                int _pos = pos + a[pos];
                if(_pos >=0 && _pos < n && dfs(pos,_pos,tmp,used,fail,n,a,b)){
                    cout << "Infinity!"; return 0;
                }
                
                pos += b[pos];
            }else{
                pos += a[pos];
            }
        }
        
        cout << path;
    }else{
        cout << "No solution!";
    }
    
    return 0;
}