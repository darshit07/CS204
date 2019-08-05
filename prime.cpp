#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long STRING1;
    cin>>STRING1;
    bool primenum;
    if (STRING1==1||STRING1==0)
        {
        cout<<"Not a Prime Number.";
        return 0;
        }
    primenum=true;
    for(int i=2; i<=sqrt(STRING1);i++)
    {
        if(STRING1%i == 0)
        {
        primenum=false;
        break;
        }
    }
    if (primenum==true)
        cout<<"Given number is a Prime Number.";
    else
        cout<<"NOT a Prime Number.";
    return 0;
}
