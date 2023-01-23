/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 329
Approach :- We will use (Recursion + Memoisation) , 
            we will try to find for ith index what is the minimum cost I can get from if I consider [0,i] array
            we have two option either to partition at ith index or not .
            Like knapsack and we try all possible combination of partition using recursion and memoisation.
            We maintain on frequency array ,if fre[ele] == 2,then we add 2 to 'importance value' and for all fre[ele]>2 we increment by '1'
            at the end the (score = importance_value + k + cost_from_(i-1) )
Time Complexity :- O(n^2)
*/
