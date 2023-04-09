/*
Platform :- Leetcode
Approach :- https://leetcode.com/problems/largest-color-value-in-a-directed-graph/solutions/3397355/video-easy-solution-explanation-beginner-friendly-c-cycle-in-directed-graph-dfs/
Video Explanation :- https://youtu.be/oUhtKGX65vI
Time Complexity :- O((n+m)*26)
*/
void cycle(int v,int &f,vector<vector<int>>&graph,vector<int>&color){
//cycle is found 
if(f)return;

color[v] = 1; 
// we have visited the node
//now we are processing it

  for(int w : graph[v]){
    //it means we have found a child chich is under processing
    //this means cycle
    if(color[w] == 1){
      f=1;
      return;
    }
    if(color[w] == 0) cycle(w,f,graph,color);
  }
  color[v] = 2; // we have completely explored the node 
}

vector<int> dfs(int node,vector<vector<int>>&graph,vector<int>&mark,vector<vector<int>>&score,string& color){

    //we are making array of 26 to store the count of 
    //26 colors possible ( 26 letters in english alphabet )
   vector<int>temp(26);
    mark[node]++;

    for(auto&x:graph[node]){
        if(mark[x]){
            //if neighbor node 'x' is already visited 
            //we will use its score and won't visit again
            for(int i=0;i<26;++i){
               temp[i] = max(temp[i],score[x][i]);
            }
            continue;
        }

        //we get count of colors for this neighbor 'x' of current node 
        vector<int>cur = dfs(x,graph,mark,score,color);

        for(int i=0;i<26;++i)temp[i] = max(temp[i],cur[i]);
        cur.clear();
    }
    
    //updating the count by marking current color
    temp[color[node]-'a']++;
    return score[node] = temp;
} 

class Solution {
public:
    int largestPathValue(string color, vector<vector<int>>& edges) {
        
        
        int ans = 0;
        int n = color.size();
        vector<vector<int>>graph(n);
        vector<int>parent(n,-1);
        for(auto&x:edges){
            graph[x[0]].push_back(x[1]);
            parent[x[1]] = x[0];
        }

        
        vector<int>vis(n);
       
        for(int i=0;i<n;++i){
           //if parent i == -1
           //this is going to be our starting node
           if(parent[i] == -1){
               int f = 0;

               //we are checking for cycle
               cycle(i,f,graph,vis);
               if(f){
                   return -1;
               }
           }
        }

        //so we didn't find cucle
        for(int i=0;i<n;++i){
            //there is cycle
            //this node is till left it means it forms a cycle
            if(vis[i] == 0 )return -1;
        }
        
        //score stores the score of each node 
        vector<vector<int>>score(n,vector<int>(26));
        vector<int>mark(n);
        for(int i=0;i<n;++i){
           //if parent i == -1
           if(parent[i] == -1){
               //do dfs
               //find for each start node I will do dfs and find score
               vector<int> cur_score = dfs(i,graph,mark,score,color);
               for(auto&x:cur_score)ans = max(ans,x);
           }
        }

         

        return ans;
    }
};
