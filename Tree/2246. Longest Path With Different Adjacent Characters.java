/*
Platform :- Leetcode
Approach :- The first thought process is what if I am at 'ith' node , I want to find the longest past in subtree with root as 'ith' node , 
            for this we will use DFS , The longest path for each ith node will be ( sum_of_two longest path in subtree of their children + 1) ,'+1' for using 'ith
            node as part of path formed by the 'Largest' and '2nd'Largest path .
            -- Let mx1 = largest path , mx2 = 2nd largest path ,.. now we will return the max_length path for ith parent so that they can form a much larger path if possible.
Time Complexity :- O(n+e)
*/
class Solution {
    int ans = 0;

    public int findCost(int node,List<List<Integer>>tree,String s,int parent){
        int mx1 = 0,mx2 = 0;

        for(int x:tree.get(node)){
            int cur_value = findCost(x,tree,s,node);
            if(mx1<cur_value){
                mx2 = Math.max(mx2,mx1);
                mx1 = cur_value;
            }
            else mx2 = Math.max(mx2,cur_value);
        }
       // System.out.println(node+" "+mx1+" "+mx2);
        ans = Math.max(ans,mx1+mx2+1);
        if(node!=0 && s.charAt(node) == s.charAt(parent))return 0;
        
        return Math.max(mx1,mx2)+1;
    }

    public int longestPath(int[] parent, String s) {
        List<List<Integer>>tree = new ArrayList<>();
        int n = s.length();
        for(int i = 0;i<n;++i){
            tree.add(new ArrayList<>());
        }

        for(int i=1;i<n;++i){
            tree.get(parent[i]).add(i);
        }

        ans = 1;

        int val = findCost(0,tree,s,0);
        return ans;
    }
}
