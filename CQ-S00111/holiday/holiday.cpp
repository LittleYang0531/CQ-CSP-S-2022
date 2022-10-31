#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long Ull;
const int MAXN=2505;
int n,m,k;
bool a[MAXN][MAXN];
Ull place[MAXN],ans;

int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c))
		x=x*10+c-'0',c=getchar();
	return x*f;
}

void dfs(Ull value,int point,int sum_place)
{
	if(sum_place==5&&point==1)
	{
		ans=max(ans,value);
		return;
	}
	if(sum_place>=5) return;
	for(int i=1;i<=n;i++)
		if(a[point][i]&&point!=i)
			dfs(value+place[point],i,sum_place+1);
}

int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=2;i<=n;i++) place[i]=read();
	for(int j=1;j<=m;j++)
	{
		int x,y;
		x=read();
		y=read();
		a[x][y]=true;
		a[y][x]=true;
	}
	dfs(0,1,0);
	cout<<ans;
	return 0;
}
