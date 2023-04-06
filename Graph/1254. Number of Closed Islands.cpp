/*
Platform :- Leetcode
Approach:- We traverse through the matrix and if we found a cell with water that is not visited by us , we start our bfs from it and mark it as closed island
           , if while doing bfs we can go to any of the boundarys we unmark it as closed island .
           If everything goes fine and we are didn't reach any boundarys , then this is a closed island.
           We mark the water cells too such that we don't visit them multiple times .
Time Complexity :- O(m*n)
*/
