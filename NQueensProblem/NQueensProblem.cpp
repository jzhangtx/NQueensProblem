// NQueensProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

bool IsSafe(int n, std::vector<std::vector<std::string>>& vv, int row, int col)
{
    if (row == n || col == n)  // these will never happen, put here just in case
        return true;

    // Because we are doing row by row, we only need to check 3 directions:
    //  up, up-left, and up-right. 

    // check up direction
    for (int i = row-1; i >= 0; --i)
        if (vv[i][col] == "Q")
            return false;

    // check up-left
    int c = col;
    for (int i = row - 1; i >= 0; --i)
        for (int j = --c; j >= 0; --j)
            if (vv[i][j] == "Q")
                return false;
            else
                break;

    // check up-right
    c = col;
    for (int i = row - 1; i >= 0; --i)
        for (int j = ++c; j < n; ++j)
            if (vv[i][j] == "Q")
                return false;
            else
                break;

    // all directions are good
    return true;
}

bool NQueenSolutions(int n, std::vector<std::vector<std::string>>& result, int row, int col)
{
    if (row == n)   // if row == n, all the rows are good, return true
        return true;
    if (col == n)   // if col == n, all columns on the row has been tried and it's not good. so return false
        return false;

    result[row][col] = "Q";     // place the Queen on the current cell
    if (!IsSafe(n, result, row, col))
    {                           // not good, remove the queen from the current cell and try next column on the row.
        result[row][col] = ".";
        return NQueenSolutions(n, result, row, col + 1);
    }
    else        // the current row has passed, go to next row
    {           //  try the row start from the first col
        if (!NQueenSolutions(n, result, row + 1, 0))
        {
            result[row][col] = ".";
            return false;
        }
    }

    return true;
}

// The return type I prefer std::vector<std::vector<char>>, because string is much slower
//  but the question itself gives the prototype of the function -_-
std::vector<std::vector<std::string>> GetNQueenSolutions(int n)
{
    std::vector<std::vector<std::string>> result(n, std::vector<std::string>(n, "."));

    // Try each column on the first row
    for (int i = 0; i < n; ++i)
    {
        if (NQueenSolutions(n, result, 0, i))
        {
            return result;
        }
    }

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
