#include<iostream>
#include<algorithm>
using namespace std;
int n,q,k,t=0,an=0,l=0;
int v[2001]={0};
int f;
int m[2001][2001]={1};
void check(int a,int b,int g)
{
	if(m[a][b]==0)
	{
		g++;
		return;
	}
	int flag=g;
	for(int i=1;i<=n;i++)
	{
		g=flag;
		if(m[a][i]==0)
		{
			check(i,b,f);
			an+=v[i];
			g++;
		}
	}
	return;
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
		cin>>n>>q>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		m[x][y]=0;
		m[y][x]=0;
	}
	while(q--)
	{
		int s1,t1;
		cin>>s1>>t1;
		an=v[s1]+v[t1];
		int f=0;
		check(s1,t1,f);
		if(f<=k)
		{
			cout<<an<<endl;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
