#include<bits/stdc++.h>
using namespace std;
int main()
{
	string pattern; cin >> pattern;
	string s; cin >> s;

	int c; int ans = 0;

	for (int i = 0; i < s.length(); i++)
	{
		int k = i; int c = 0;
		for (int j = 0; j < pattern.length(); j++)
		{
			if (s[k] == pattern[j]) c++;

			if (c == pattern.length())
			{
				ans++;
				cout << "Pattern Matched Index :" << i << " " << endl;

			}
			k++;
		}
	}
	cout << "Number of matches " << ans << endl;

	return 0;
}
/*
abc
abcabcabc
*/
