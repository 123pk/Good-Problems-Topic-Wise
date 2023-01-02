/*
Platform :- Leetcode
Approach :- We will root our tree at '0' (we can choose any node) ,
            now using bfs we will compute two things fro each node (sum_of_path_to_all_nodes_in_subtree ,  no_of_node_in_subtree) .
            We will get the score of rooted node,
            now we run the bfs from that root to other nodes,
            -- count = no_of_nodes_in_subtree_with_current_node_as_root
            
            "Score[i] = Score[parent] - count + ( n - count) }"
            --> We subtract because we are moving a distace from (parent --> ith node) that will reduce the score by (count)
            --> and we get additional value added (n-count)
Time Compelxity :- O(n+e)
*/
class Solution {
public:
   //score ,nodes
    pair<int,int> find(int node,vector<vector<int>>&graph,vector<int>&vis,vector<pair<int,int>>&compute){
        vis[node]++;
        pair<int,int>tot = {0,0};
        for(auto&x:graph[node]){
            if(vis[x])continue;
            pair<int,int>temp = find(x,graph,vis,compute);
            tot.second += temp.second;
            tot.first += temp.first;
        } 
        
        return compute[node] = {tot.first+tot.second,tot.second+1};
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        //the first idea is to root the tree at one of the nodes of diameter
        //then do dfs where 
        //we can root at any node let us root it at node 0
          vector<vector<int>>graph(n);
          vector<int>vis(n);
          vector<pair<int,int>>values (n);

          for(auto&x:edges){
              graph[x[0]].push_back(x[1]);
              graph[x[1]].push_back(x[0]);
          }
         
         vector<int>ans(n);
         pair<int,int>val = find(0,graph,vis,values);

         
          
          //node and parent
          queue<pair<int,int>>bfs;
          bfs.push({0,0});
          vector<int>used(n);
          used[0]++;
 
          while(!bfs.empty()){
              pair<int,int>temp = bfs.front();
              bfs.pop();
              int node = temp.first;
              int parent = temp.second;
              

              if(node == 0){
                  ans[node] = val.first;
              }
              else{
                  ans[node] = ans[parent]-values[node].second+(n-values[node].second);
              }

              for(auto&x:graph[node]){
                  if(used[x])continue;
                  used[x]++;
                  bfs.push({x,node});
              }
          }

          return ans;
    }
};
