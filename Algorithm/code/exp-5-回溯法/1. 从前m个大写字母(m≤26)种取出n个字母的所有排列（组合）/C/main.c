#include <stdio.h>

char *a;
bool check(int i)
{
	for(int j=0; j<i; j++)
	{
		if(a[i] == a[j])//相同
		{
			return false;
		}
	}
	return true;
}

void output(char *a, int n)
{
	for(int i=0; i<n; i++)
	{
		printf("%c ", a[i]);
	}
	printf("\n");
}

//递归回溯法
void backTrack(int i, int n, int m)
{
	if(i >= m)
	{
		output(a, m);
	}
	else
	{
		for(int j=0; j<n; j++)
		{
			a[i] = 'A' + j;
			if(check(i))
			{
				backTrack(i+1, n, m);
			}
		}
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	a = new char[n];
	backTrack(0, n, m);
	return 0;
}