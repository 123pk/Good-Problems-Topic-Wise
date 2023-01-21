/*
Platform :- Codeforces
Contest :- Codeforces Round #845 (Div. 2) and ByteRace 2023
Approach :- We want to cover all the vvalues from 1 to m or we want a group where the factors of numbers in that group union to all the values from (1 to m) 
            We can find the factors of a value in O(sqrt(A[i])) . 
            So the basic idea is to sort the values in increasing order ,then we maintain on SET which store the factors we need to find 
            Once the set becomes empty ,it means that we have found all the factors .
            We also maintain one 'left' pointer . which points to the smallest element of our group. The score is 'current' value - 'smallest' element. 
            We move the pointer if ( SET is empty) till the time it becomes un empty of started pointer to current value
 Time Complexity :- O(n*log n + O(n*sqrt(n))
*/
