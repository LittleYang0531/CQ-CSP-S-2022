#include <bits/stdc++.h>

using namespace std;

struct aaa
{
	int s;
	int p;
};



int main(int argc, char** argv)
{
	/*
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	*/
	int n,m,k;
	cin >> n >> m >>k;
	aaa a[n];
	int b2[n]={1};
	int b[m][n+1]={-1};
	a[0].s=0;
	for(int i=0;i<n;i++)
	{
		a[i].p=i+1;
		b[i][0]=i+1;
		if(i!=0) cin >> a[i].s;
	}
	
	for(int i=0;i<n;i++)
	{
		int l;
		cin >>l;
		for(int j=0;j<n;j++)
		{
			if(l==b[j][0])
			{
				cin >> b[i][b2[i]++];
			}
		}
	}
	int ro[n*n]={0},cou=0;
	ro[0]=1;
	while(ro[n*n-1]!=1)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				for(int x=0;x<b2[i];x++)
				{
					if(ro[cou]==b[i][0])
					{
						cou++;
						ro[cou]=b[i][j];
					}
				}
			}
		} 
	}
	int s[n*n]={0},q=0;
	for(int i=0;i<cou;i++)
	{
		for(int j=1;j<n;j++)
		{
			for(int con=0;con<4;con++)
			{
				if(ro[i]==a[j].p)
				{
					s[q]+=a[j].s;
				}
			}
			q++;
		}
	}
	q--;
	sort(s,s+q);
	cout << s[0];
	return 0;
}
