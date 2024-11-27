N Queens Problem (please see the docx version for a better understanding)


You are given an n*n chess board with n queens. You need to find all the configurations of the pieces such that no two queens attack each other.

N Queens Problem
Each valid configuration is a unique list of n strings of length n where ‘Q’ and ‘.’ represents a Queen and empty space respectively.

Example:
Input: n = 4

Output: [["..Q.","Q...","...Q",".Q.."], [".Q..","...Q","Q...","..Q."]]

Testing
Input Format 
The first line contains an integer ‘T’, denoting the number of test cases.
For each test case, a line containing an integer ‘n’ denoting the dimension of the chess board and the number of queens.

Output Format 
For each test case, print all the valid configurations with each row on a separate line.

Examples
Sample Input
2
1
4
Expected Output
Q
..Q.
Q...
...Q
.Q..
.Q..
...Q
Q...
..Q.