/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 285
Approach :- 
*/
#include<bits/stdc++.h>
using namespace std;

void dfs(int v,int &f,vector<vector<int>>&graph,vector<int>&color){
    if(f)return;
  color[v] = 1; // GREY
  for(int w : graph[v]){
     // if(w == parent)continue;
    if(color[w] == 1){
       // cout<<w<<" ";
      f=1;
      return;
    }
    if(color[w] == 0) dfs(w,f,graph,color);
  }
  color[v] = 2; // BLACK
}

int main(){
    int n;
    cin>>n;
    
    set<string>P;
    vector<pair<string,string>>names(n);
    for(int i=0;i<n;++i){
        cin>>names[i].first>>names[i].second;
        P.insert(names[i].first);
        P.insert(names[i].second);
    }
    
    int d = 0;
    map<string,int>compress;
    for(auto&x:P){
        compress[x] = d;
        d++;
    }
    
    vector<vector<int>>graph(d);
    for(auto&x:names){
        int u = compress[x.first];
        int v = compress[x.second];
         
        graph[u].push_back(v);
         
    }
    
    int g = 0;
    vector<int>vis(d);
    for(int i=0;i<d;++i){
        if(vis[i])continue;
        
        int f = 0;
        dfs(i,f,graph,vis);
        if(f){
          //  cout<<i<<"\n";
            g = 1;
            break;
        }
    }
    
    if(g)cout<<"No\n";
    else cout<<"Yes\n";
}
