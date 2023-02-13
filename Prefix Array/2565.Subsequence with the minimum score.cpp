/*
Platform :- Leetcode
Contest :- Weekly contest 332
Video Explanation :- https://www.youtube.com/watch?v=-BlFzx80flA&t=916s
Approach :- 
If you will carefully observe ,the score depends on the (maximum and minium index ) deleted and any other index between is useless , so its better to consider or delete all of them . Then (right - left)+1 = length of substring deleted .
And now you know the main hidden problem , Find the minimum length of substring which when deleted makes t subsequency of s .

Approach
Here the string 's' does not change and after removing substring from 't' our t is divided into two parts suffix( part after delted substring to end) and prefix (part from start to just before delted substring) .
We can form two disjoint parts from [0,i] and [i+1, n-1] for each index 'i' , n = length of string 's' . And for [0,i] we want to find the max length of prefix that we can get from [0,i] characters of 's' and for [i+1,n-1] we want to find the length of max suffix of 't' that we can get .

Let x = max_prefix_length (for [0,i])
y = max_suffix_length ( for [i+1,n-1])
m = intial length of string 't'
len = length of string formed from prefix and sufix for 'i' = (x+y)
Lenth of substring deleted = m - len
We find len for each of the 'i' and store the minmum .
Edge case when we derive just prefix or suffix from whole string s.

Time Complexity :- O(n)
*/

