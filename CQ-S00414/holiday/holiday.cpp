#include <bits/stdc++.h>
using namespace std;

long long n,m,k;//n是点个数,m是路个数 
int p[10002];
int l[10002][2];
int jishu=0;//计数用 
int score[10002]={0};//定义积分

int doit(int kaishi)
{
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n-i-1;j++)
		{
			if(p[j]<p[j+1])
			{
				int tmp=p[j];
				p[j]=p[j+1];
				p[j+1]=tmp;
			}
		}
	}
	return p[2]+p[3]+p[4]+p[5];
}

int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n-1;i++)
	{
		cin>>p[i];
	}
	for(int i=0;i<m;i++)
	{
		for(int j=1;j<=2;j++)
		{
			cin>>l[i][j];
		}
	}
	cout<<doit(1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
