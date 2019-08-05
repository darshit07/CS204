#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool Smaller(string p1, string p2)
{
	int n1 = p1.length(), n2 = p2.length();
	if (n1 < n2)
	return 1;
	if (n2 < n1)
	return 0;
	for (int i=0; i<n1; i++)
	if (p1[i] < p2[i])
    return 1;
	else if (p1[i] > p2[i])
    return 0;
	return 0;
}
string difference(string p1, string p2)
{
	if (Smaller(p1, p2))
		swap(p1, p2);
	string result = "";
	int n1 = p1.length(), n2 = p2.length();
	reverse(p1.begin(), p1.end());
	reverse(p2.begin(), p2.end());
	int c = 0;
	for (int i=0; i<n2; i++)
	{
		int subt = ((p1[i]-'0')-(p2[i]-'0')-c);
		if (subt < 0)
		{subt = subt + 10;
        c = 1;
		}
		else
        c = 0;
		result.push_back(subt + '0');
	}
	for (int i=n2; i<n1; i++)
	{
		int subt = ((p1[i]-'0') - c);
		if (subt < 0)
        {
        subt = subt + 10;
			c = 1;
		}
		else
			c = 0;
		result.push_back(subt + '0');
	}
	reverse(result.begin(), result.end());
	return result;
}
 main()
{
	string p1;
	string p2;
	getline(cin, p1);
	getline(cin, p2);
	cout << difference(p1, p2);
	return 0;
}
