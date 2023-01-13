/*
Platform :- Leetcode
Approach :- The first thought process is what if I am at 'ith' node , I want to find the longest past in subtree with root as 'ith' node , 
            for this we will use DFS , The longest path for each ith node will be ( sum_of_two longest path in subtree of their children + 1) ,'+1' for using 'ith
            node as part of path formed by the 'Largest' and '2nd'Largest path .
            -- Let mx1 = largest path , mx2 = 2nd largest path ,.. now we will return the max_length path for ith parent so that they can form a much larger path if possible.
Time Complexity :- O(n+e)
*/
