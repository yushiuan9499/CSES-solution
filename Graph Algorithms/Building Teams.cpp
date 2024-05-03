#include<bits/stdc++.h>
using namespace std;
 
int n,m;
int a[100005];
vector<int> v[100005];
bool done=0;
bool ans=1;
int f(int x){
    return x==1?2:1;
}
 
void dfs(int x,int y){
    if(done)return;
    a[x]=y;
    for(int i=0;i<v[x].size();i++){
        if(!a[v[x][i]]){
            dfs(v[x][i],f(y));
        }else if(a[v[x][i]]==y){
                ans=0;
                done=1;
                return;
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n&&!done;i++){
        if(!a[i]){
            dfs(i,1);
        }
    }
    if(ans)
        for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    else cout<<"IMPOSSIBLE";
}
