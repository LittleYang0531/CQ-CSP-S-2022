#include<iostream>
using namespace std;
int n,m,k;
int a[2505][10005],l[2505];
int dfs(int n,int m,int cs,int fs)
{
	if(cs==4)
	{
		for(int i=1;i<=l[1];i++)
		{
			if(a[1][i]==n)
			{
				break;
			}
			if(i==l[1])
			{
				return 0;
			}
		}
		return fs;
	 }
	 cs++;
	 if(cs!=0)
	 {
		for(int i=1;i<=l[m];i++)
		{
			fs+=a[m][0];
			cs++;
			return dfs(m,a[m][i],cs,fs);
		}
	}
	else
	{
		int fffs=0;
		for(int i=1;i<=l[1];i++)
		{
			fffs=max(fffs,dfs(1,a[1][i],1,fs));
		}
		return fffs;
	}
}
int main()
{
	freopen("holiday.in","w",stdin);
	freopen("holiday.out","r",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a[i][0]);
	}
	for(int i=1,ll,rr;i<=m;i++)
	{
		cin>>ll>>rr;
		l[ll]++;
		l[rr]++;
		a[rr][l[rr]]=ll;
		a[ll][l[ll]]=rr;
	}
	cout<<dfs(1,1,0,0);
 } 
