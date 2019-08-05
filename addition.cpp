#include <iostream>
#include<bits/stdc++.h>
using namespace std;
string add(string string1, string string2)
{
	if (string1.length() > string2.length())
		swap(string1, string2);
	string result = "";
    reverse(string1.begin(), string1.end());
	reverse(string2.begin(), string2.end());
	int num1 = string1.length(), num2 = string2.length();
	int c = 0;
	for (int i=0; i<num1; i++)
	{
    int sum = ((string1[i]-'0')+(string2[i]-'0')+c);
    result.push_back(sum%10 + '0');
    c = sum/10;
	}
	for (int i=num1; i<num2; i++)
	{
		int sum = ((string2[i]-'0')+c);
		result.push_back(sum%10 + '0');
		c = sum/10;
	}
	if (c)
    result.push_back(c+'0');
	reverse(result.begin(), result.end());
	return result;
}
int main()
{
	string string1;
	string string2;
	getline(cin, string1);
	getline(cin, string2);
	cout<<add(string1, string2);
	return 0;
}
