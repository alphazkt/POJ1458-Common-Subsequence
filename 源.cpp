#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

static char str1[1000];
static char str2[1000];
static int maxLen[1000][1000];

int main()
{
	while (cin >> str1 >> str2)
	{
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		int i, j;

		for (i = 0; i <= len1; i++)
			maxLen[i][0] = 0;
		for (i = 0; i < len2; i++)
			maxLen[0][i] = 0;

		for (i = 1; i <= len1; i++)
			for (j = 1; j <= len2; j++)
			{
				if (str1[i - 1] == str2[j - 1])
					maxLen[i][j] = maxLen[i - 1][j - 1] + 1;
				else
					maxLen[i][j] = max(maxLen[i][j - 1], maxLen[i - 1][j]);
			}

		cout << maxLen[len1][len2] << endl;
		
	}return 0;
}

