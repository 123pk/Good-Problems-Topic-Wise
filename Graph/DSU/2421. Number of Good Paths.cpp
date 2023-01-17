/*
Platform :- Leetcode
Approach :- The basic approach is to form the graph starting with edge with smallest maximum value . We join two disjoint sets and 
            if the max_value in both is same then we can have (count1*count2) no of good paths where count1 & count2  is frequency of max_values .
            After merging we update the parent and count is updated to sum for the parent and made '0' for other node.
Time Complexity :- O(n+e log n)
*/
class Solution {
public:
    vector<int>parent;
    map<int,pair<int,int>>score;

    int find_parent(int val){
        if(parent[val] == val)return val;
        parent[val] = find_parent(parent[val]);
        return parent[val];
    }

    void do_union(int x,int  y){
        int parent_x = find_parent(x);
        int parent_y = find_parent(y);

        if(parent_x == parent_y)return;
        pair<int,int> mv1 = score[parent_x];
        pair<int,int> mv2 = score[parent_y];
        
        int val1 = mv1.first;
        int count1 = mv1.second;
        int val2 = mv2.first;
        int cout2 = mv2.second;

        if(val1 == val2){
            score[parent_y].second += count1;
        }
        else{
            if(val1>val2){
                score[parent_y] = {val1,count1};
            }
        }
        score[parent_x].second = 0;
        parent[parent_x] = parent_y;
        return;
    }
     
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        
        
        sort(edges.begin(),edges.end(),[&](vector<int>&p,vector<int>&q){
            return max(vals[p[0]],vals[p[1]])<max(vals[q[0]],vals[q[1]]);
        });

        int n = vals.size();
        int ans = n;
        parent.resize(n);
        for(int i=0;i<n;++i){
            parent[i] = i;
            score[i] = {vals[i],1};
        }
        
        for(auto&x:edges){
            int u = x[0];
            int v = x[1];
            
            int p = find_parent(u);
            int q = find_parent(v);

            if(score[p].first == score[q].first){
                ans += (score[p].second*score[q].second);
               
            }
           // cout<<u<<" -- "<<p<<" & "<<v<<" -- "<<q<<" -> "<<ans<<"\n";
              do_union(u,v);
        }

        return ans;
    }
};
