/*
Platform :- Codeforces
Contest :- Codeforces Round 797 Div 3
Approach :- Here each permutation value can act as a node , and we are goinng to form a cycle from them ,
            we will have 'x' disjoint set union or components and all having cycle.
            We will find the string formed by the component , then we will find the minimum operation to find the 
            intial string again . Atmax 'n' - length of intial string . 
            So we will have 'x' no of such minimum operations and the final answer is LCM of all the values.
 Time Complexity :- O(n)
*/
