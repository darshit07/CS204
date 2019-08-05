#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string multi(string s1, string s2)
{   int size1 = s1.size();
	int size2 = s2.size();
	if (size1==0||size2==0)
	return "0";
	vector<int> result(size1+size2, 0);
	int i_n1 = 0;
	int i_n2 = 0;
		for (int i=size1-1; i>=0; i--)
	{
		int c = 0;
		int n1 = s1[i] - '0';
		i_n2 = 0;
        for (int j=size2-1; j>=0; j--)
		{
			int n2 = s2[j] - '0';
 			int sum = n1*n2 + result[i_n1 + i_n2] + c;
			c = sum/10;
			result[i_n1 + i_n2] = sum % 10;
			i_n2++;
		}
		if (c > 0)
			result[i_n1 + i_n2] += c;
		i_n1++;
	}
	int i = result.size() - 1;
	while (i>=0 && result[i] == 0)
	i--;
	if (i == -1)
	return "0";
	string s = "";
		while (i >= 0)
		s += std::to_string(result[i--]);
	return s;
}
int main()
{
	string line1;
	string line2;
	getline(cin, line1);
	getline(cin, line2);
		if((line1.at(0) == '-' || line2.at(0) == '-') &&
		(line1.at(0) != '-' || line2.at(0) != '-' ))
		cout<<"-";
	if(line1.at(0) == '-' && line2.at(0)!='-')
		{
			line1=line1.substr(1);
		}
		else if(line1.at(0)!='-'&&line2.at(0)=='-')
		{
			line2 = line2.substr(1);
		}
		else if(line1.at(0)=='-'&&line2.at(0) == '-')
		{
        line1=line1.substr(1);
        line2=line2.substr(1);
		}
	cout << multi(line1,line2);
	return 0;
}
