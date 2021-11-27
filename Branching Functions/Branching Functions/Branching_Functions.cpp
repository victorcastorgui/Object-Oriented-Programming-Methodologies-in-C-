// Branching_Functions.cpp
// 2a-Lab-03
//

#include <iostream>

using namespace std;

double mean_of_3(int n1, int n2, int n3);
int max_of_5(int n1, int n2, int n3, int n4, int n5);
int min_of_5(int n1, int n2, int n3, int n4, int n5);
bool sides_make_triangle(int a, int b, int c);
bool angels_make_triangle(int A, int B, int C);
bool is_a_leap_year(int yyyy);


//This function returns the mean the three numbers passed
// in as parameters. Note that the mean may not be a round
// number. So you must use the double datatype for it.
double mean_of_3(int n1, int n2, int n3)
{
    return ((n1 + n2 + n3)/3.0);
}

//This function returns the maximum of the 5 given numbers.
int max_of_5(int n1, int n2, int n3, int n4, int n5)
{
    if (n1 > n2 && n1 > n3 && n1 > n4 && n1 > n5)
    {
        return n1;
    }
    else if (n2 > n1 && n2 > n3 && n2 > n4 && n2 > n5)
    {
        return n2;
    }
    else if (n3 > n1 && n3 > n2 && n3 > n4 && n3 > n5)
    {
        return n3;
    }
    else if (n4 > n1 && n4 > n2 && n4 > n3 && n4 > n5)
    {
        return n4;
    }
    else return n5;
}

// This function returns the minimum of the 5 given numbers.
int min_of_5(int n1, int n2, int n3, int n4, int n5)
{
    if (n1 < n2 && n1 < n3 && n1 < n4 && n1 < n5)
    {
        return n1;
    }
    else if (n2 < n1 && n2 < n3 && n2 < n4 && n2 < n5)
    {
        return n2;
    }
    else if (n3 < n1 && n3 < n2 && n3 < n4 && n3 < n5)
    {
        return n3;
    }
    else if (n4 < n1 && n4 < n2 && n4 < n3 && n4 < n5)
    {
        return n4;
    }
    else return n5;
}

// Given three lengths, this function should return whether they can be the
// sides of some triangle. The heuristic you code should check if the
// sum of the two smallest sides is greater than or equal to the third side.
// Treat extreme cases as valid trianges. E.g. a+b == c means valid triangle.
// The challenge is to do it without using arrays.
bool sides_make_triangle(int a, int b, int c)
{
    if(a + b <= c || a + c <= b || b + c <= a)
    {
        return false;
    }
    else
        return true;
}

// Given three angles as integer degrees, this function should return whether
// they can be internal angles of some triangle, Treat extreme cases as
// valid triangles. E.g. (0, 0, 180) is a valid triangle.
bool angles_make_triangle(int A, int B, int C)
{
    if (A+B+C == 180)
        return true;
    else
        return false;
}

// Return true if the year yyyy is a leap year and false if not.
bool is_a_leap_year(int yyyy)
{
    if (yyyy % 4 == 0)
    {   if(yyyy % 100 == 0)
        {
            if(yyyy % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;
}
