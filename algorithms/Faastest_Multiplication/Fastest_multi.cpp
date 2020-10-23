/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

// int adder(string x, string y){

//     return z;
// }

void paddingLeft(string &xs, string &ys)
{
    // string xs=to_string(x);
    // string ys=to_string(y);
    string zero = "0";

    int n = xs.length() - ys.length();
    if (n < 0)
        n = -n;

    while (   ( xs.length() != ys.length() )  || ( (ys.length() % 4 != 0) || (xs.length() % 4 != 0) ) && ((xs.length() != 2)))
    {
        if (xs.length() < ys.length())
            xs = zero + xs;
        else
            ys = zero + ys;
    }

    // cout << xs << " " << ys << endl;
}

int paddingRight(int num, int n)
{
    string str = to_string(num);
    for (int i = 0; i < n; i++)
        str = str + "0";

    int z = stoi(str);
    return z;
}

int multi(int x, int y)
{

    char a[100] = {0};
    char b[100] = {0};
    char c[100] = {0};
    char d[100] = {0};
    int ac, bd;
    string xs = to_string(x);
    string ys = to_string(y);

    if (xs.length() == 1)
        return x * y;
    else
    {

        if (xs.length() != ys.length() || (ys.length() % 4 != 0 || xs.length() % 4 != 0) && (xs.length() != 2))
        {
            paddingLeft(xs, ys);
        }

        int l = (ys.length()) / 2;
        xs.copy(a, l, 0);
        xs.copy(b, l, l);
        ys.copy(c, l, 0);
        ys.copy(d, l, l);
        // ac
        // cout << a << " " << c << " " << b << " " << d << " " << l << " " << (ys.length()) << endl;
        ac = multi(stoi(a), stoi(c));
        bd = multi(stoi(b), stoi(d));
        return paddingRight(ac, (xs.length())) +
               paddingRight((multi(stoi(a) + stoi(b), stoi(c) + stoi(d)) - ac - bd), (xs.length() / 2)) +
               bd;
    }
}

int main()
{

    int x = 125;
    int y = 125;

    cout << "Multiplication of (" << x << "*" << y << ")  = " << multi(x, y) << endl;

    return 0;
}
