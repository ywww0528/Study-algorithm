#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		vector<int> s[10];
		int a[4] = {0, 2, 3, 4};
		s[2].push_back(1);
		s[3].push_back(2);
		s[4].push_back(3);
		int dex = 0;
		for (int i = 1; i <= 12; i++)
		{
			int x, y;
			cin >> x >> y;
			int kk = a[x];
			int kk1 = a[x] + y;
			for (int j = 0; j < s[kk].size(); j++)
			{
				if (s[kk][j] == x)
				{
					dex = j;
					break;
				}
			}
			for (int j = dex; j < s[kk].size(); j++)
			{
				a[s[kk][j]] = kk1;
				s[kk1].push_back(s[kk][j]);
			}
			int len = s[kk].size();
			for (int j = dex; j < len; j++)
			{
				s[kk].pop_back();
			}
		}
		if (s[9].size() == 3)
		{
			cout << "Y" << endl;
		}
		else
		{
			cout << "N" << endl;
		}
	}
	return 0;
}