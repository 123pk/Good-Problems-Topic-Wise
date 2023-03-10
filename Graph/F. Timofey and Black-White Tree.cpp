/*
Platform :- Codeforces
Contest :- Codeforces Round 847 Div 3
Approach :- If you are familiar with fiding (a%b) using a = a-b else b = b-a process , it is similar like that 
            The main thought process behind , the value of length decreases as we move ahead ,
            'B' --- 1 -- 2 -- 3 -- 4 -- 5 -- B ,
            here we have 7 node out of which two black nodes , the max distance that we can have is (7/2) FOR node 3,
            so if we have to color node 2 ,
            B -- 1 -- 2 -- B -- 4 -- 5 -- B
            now the max we can have is 1 , so oviously the distance is decreasing by 2 at one point we will only have option of '1'
            
            Steps 
            1. So we find parent for each node using DFS
            2. We start from the first black node and let us root the tree at node 1, we now find the distance from that node to '1' and maintain one array
               where we store the min distance of each node from black node
            3. Now we traverse for all the white nodes in order and go to ancestors till the time 'curent_distance' < ans .
               we keep oon updatign the values too in  our array.
               
Time Complexity :- O(n log n)
*/
/*
Platform :- Codeforces
Contest :- Codeforces Round 847 Div 3
Approach :- If you are familiar with fiding (a%b) using a = a-b else b = b-a process , it is similar like that 
            The main thought process behind , the value of length decreases as we move ahead ,
            'B' --- 1 -- 2 -- 3 -- 4 -- 5 -- B ,
            here we have 7 node out of which two black nodes , the max distance that we can have is (7/2) FOR node 3,
            so if we have to color node 2 ,
            B -- 1 -- 2 -- B -- 4 -- 5 -- B
            now the max we can have is 1 , so oviously the distance is decreasing by 2 at one point we will only have option of '1'
            
            Steps 
            1. So we find parent for each node using DFS
            2. We start from the first black node and let us root the tree at node 1, we now find the distance from that node to '1' and maintain one array
               where we store the min distance of each node from black node
            3. Now we traverse for all the white nodes in order and go to ancestors till the time 'curent_distance' < ans .
               we keep oon updatign the values too in  our array.
               
Time Complexity :- O(n log n)
*/
#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>>&graph,int p,vector<int>&parent){
    
     
    for(auto&x:graph[node]){
        if(x == p)continue;
        parent[x] = node;
        
        dfs(x,graph,node,parent);
    }
    
     
}

//initial distance fill

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,root;
        
        cin>>n;
        
        vector<int>order(n);
         
        for(int i=0;i<n;++i){
            cin>>order[i];
            order[i]--;
        }
        
        vector<vector<int>>graph(n);
        for(int i=1;i<n;++i){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<int>parent(n);
        parent[0] = -1;
        dfs(0,graph,-1,parent);
       
        vector<int>score(n,1e6);
        int ans = 1e6;
        
         
        
        for(int i=0;i<order.size();++i){
            int cur_dist1 = 0;
            int node1 = order[i];
            while(node1 != -1 && cur_dist1<ans){
                ans = min(ans,(cur_dist1 + score[node1]));
                score[node1] = min(cur_dist1,score[node1]);
                 
                node1 = parent[node1];
                cur_dist1++;
            }
            
            if(i)cout<<ans<<" ";
        }
        cout<<"\n";
        
    }
}
