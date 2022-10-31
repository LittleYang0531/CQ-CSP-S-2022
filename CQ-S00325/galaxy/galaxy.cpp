#include<iostream>
using namespace std;
int n,m,q;
bool b=1;
int t=0;
int map[1001][1001]={0};
void fj(int i)
{
	if(t>n)
	{
		return;
	}
	for(int j=1;j<=n;j++)
	{
		if(map[i][j]==1)
		{
			t++;
			fj(j);
			if(t>n)
			{
				return;
			}
		}
	}
	return;
}
bool cs(int i)
{
	int time=0;
	for(int j=1;j<=n;j++)
	{
		if(map[i][j]==1)
		{
			time++;
		}
	}
	if(time==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void panduan()
{
	for(int i=1;i<=n;i++)
	{
		t=0;
		fj(i);
		if(t<=n)
		{
			cout<<"NO"<<endl;
			b=0;
			return;
		}
		if(!cs(i))
		{
			cout<<"NO"<<endl;
			b=0;
			return;
		}
	}
	if(b)
	{
		cout<<"YES"<<endl;
		return;
	}
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		map[x][y]=1;
	}
	cin>>q;
	while(q--)
	{
		int a;
		cin>>a;
		if(a==1)
		{
			int x,y;
			cin>>x>>y;
			map[x][y]=-1;
		}
		else if(a==2)
		{
			int x;
			cin>>x;
			for(int i=1;i<=n;i++)
			{
				if(map[i][x]==1)
				{
					map[i][x]=-1;
				}
			}
		}
		else if(a==3)
		{
			int x,y;
			cin>>x>>y;
			map[x][y]=1;
		}
		else if(a==4)
		{
			int x;
			cin>>x;
			for(int i=1;i<=n;i++)
			{
				if(map[i][x]==-1)
				{
					map[i][x]=1;
				}
			}
		}
		panduan();
		b=true;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
