// NQueensProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

bool IsSafe(int n, std::vector<std::vector<int>>& vv, int row, int col)
{
    if (row == n || col == n)  // these will never happen, put here just in case
        return true;

    // Because we are doing row by row, we only need to check 3 directions:
    //  up, up-left, and up-right. 

    // check up direction
    for (int i = row-1; i >= 0; --i)
        if (vv[i][col] == 1)
            return false;

    // check up-left
    int j = col-1;
    for (int i = row - 1; i >= 0 && j >= 0; --i)
        if (vv[i][j--] == 1)
            return false;

    // check up-right
    j = col+1;
    for (int i = row - 1; i >= 0 && j < n; --i)
        if (vv[i][j++] == 1)
            return false;

    // all directions are good
    return true;
}

std::vector<std::string> ConvertResult(const std::vector<std::vector<int>>& r)
{
    std::vector<std::string> result;
    for (auto& v : r)
    {
        std::string s;
        s.reserve(r.size());
        for (auto n : v)
        {
            if (n == 1)
                s.push_back('Q');
            else
                s.push_back('.');
        }
        result.push_back(std::move(s));
    }

    return result;
}

void NQueenSolutions(int n, std::vector<std::vector<int>> result, std::vector<std::vector<std::string>>& final, int row)
{
    if (row == n)   // if row == n, all the rows are good, return true
        return;
    
    for (int i = 0; i < n; ++i)
    {
        result[row][i] = 1;
        if (IsSafe(n, result, row, i))
        {
            if (row == n - 1)       // Solution found, add it to the result
            {
                final.push_back(ConvertResult(result));
            }
            else
            {
                NQueenSolutions(n, result, final, row + 1);
            }
        }
        result[row][i] = 0;
    }
}

// The return type I prefer std::vector<std::vector<char>>, because string is much slower
//  but the question itself gives the prototype of the function -_-
std::vector<std::vector<std::string>> GetNQueenSolutions(int n)
{
    std::vector<std::vector<std::string>> result;
    std::vector<std::vector<int>> r(n, std::vector<int>(n, 0));

    // Try each column on the first row
    NQueenSolutions(n, r, result, 0);

    return result;
}

int main()
{
    while (true)
    {
        std::cout << "The size of the chess board: ";
        int n;
        std::cin >> n;
        if (n == 0)
            break;

        std::vector<std::vector<std::string>> r = GetNQueenSolutions(n);
        for (auto& v : r)
        {
            for (auto& e : v)
                std::cout << e << " ";
            std::cout << std::endl;
        }
    }
}
