#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

void sortPoke(vector<string>& a, int n);
int main()
{
	int input = 0, n = 0;
	string Str, s;
	vector<string> pokeS;

	cin >> input;
	cin.ignore(1, '\n');
	for (int i = 0; i < input; i++)
	{
		getline(cin, Str);
		istringstream cutStr(Str);
		while (getline(cutStr, s, ' '))
		{
			pokeS.push_back(s);
		}
		sortPoke(pokeS, pokeS.size());
		for (int j = 0; j < pokeS.size(); j++)
		{
			if (j == pokeS.size() - 1) cout << pokeS[j] << endl;
			else cout << pokeS[j] << " ";
		}
		pokeS.clear();
	}
	return 0;
}
void sortPoke(vector<string>& a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			string t;
			if (a[i][0] > a[j][0]) { t = a[i]; a[i] = a[j]; a[j] = t; }
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0 + i; j < n; j++)
		{
			if (a[i][0] == a[j][0])
			{
				string t, bN = a[i].substr(1, 2), sN = a[j].substr(1, 2);
				istringstream bigN(bN);
				istringstream smaN(sN);
				int b = 0, s = 0;
				bigN >> b; smaN >> s;
				if (b < s) { t = a[i]; a[i] = a[j]; a[j] = t; }
			}
		}
	}
}