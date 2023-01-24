/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 328
Approach :- We want two things from each child for each node , the ( not_removed_sum , removed_sum)
            not_removed_sum - max sum of path of nodes ( we have not removed leaf_value)
            removed_sum - max sum of path of nodes ( we have already removed leaf value )
            
            -- we want to find the max sum in both cases.
               ans = max(ans , Max_not_removed_sum_node1  + max_removed_sum_node2 + current_val )
               where node1 - gives the maximum not_removed_sum
                     node2 - gives the maximum removed_sum
                     node1 != node2 , 
               In case of just one child node , it is max(not_removed_sum , removed_sum + node_val)
 
               
Runtime :- O(n+e)
Use :- DFS
*/
 
class Solution {
public:
    
    pair<long long,long long> find(int node,vector<vector<int>>&tree,vector<int>&price,vector<int>&vis,long long& ans){
        vis[node]++;
        
        
        int c = 0;
        long long sum1 = 0 , sum2 = 0,cur_val = price[node];
        for(auto&x:tree[node]){
            if(vis[x])continue;
            c++;
            pair<long long,long long>temp = find(x,tree,price,vis,ans);
            
             
             if(c>1){
                 ans = max(ans,sum1 + temp.second + cur_val);
                ans = max(ans,sum2 + temp.first + cur_val);
             }   
            else{
                ans = max(ans,temp.first);
                ans = max(ans,temp.second+cur_val);
            }
                sum1 = max(sum1,temp.first);
                sum2 = max(sum2,temp.second);
        }
        
       // cout<<sum1<<" "<<sum2<<" for "<<node<<"\n";
        if(c == 0){
            return {sum1+cur_val,sum2};
        }
        return {sum1+cur_val,sum2+cur_val};
    }
    
     
    
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        long long ans = 0;
        vector<vector<int>>tree(n);
        vector<int>degree(n);
        
        for(auto&x:edges){
            tree[x[0]].push_back(x[1]);
            tree[x[1]].push_back(x[0]);
            degree[x[0]]++;
            degree[x[1]]++;
        }
        int leaf = 0;
        for(int i=0;i<n;++i){
            if(degree[i] == 1){
                leaf = i;
                break;
            }
        }
        //cout<<" leaf "<<leaf<<"\n\n";
        vector<int>vis(n);
        pair<long long,long long>temp = find(leaf,tree,price,vis,ans);
        return ans;
    }
};
