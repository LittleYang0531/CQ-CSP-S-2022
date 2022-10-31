#include<bits/stdc++.h>
#define int long long
using namespace std;
int sum[2505],ans,n,m,x,y,k;
bool jl[2505][2505],bd[2505];
vector < int > js,cnt,jll[2505];
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void dfs(int tot,int id,int num)
{
	if(tot==4)
	{
		ans=max(ans,num);
		return;
	}
	if(tot==0)
	{
		for(int i=0;i<js.size();++i)
		{
			bd[js[i]]=true;
			dfs(1,js[i],sum[js[i]]);
			bd[js[i]]=false;
		}
	}
	if(tot==1||tot==2)
	{
		for(int i=0;i<cnt.size();++i)
		{
			if(jl[id][cnt[i]]&&!bd[cnt[i]])
			{
				bd[cnt[i]]=true;
				dfs(tot+1,cnt[i],num+sum[cnt[i]]);
				bd[cnt[i]]=false;
			}
		}
	}
	if(tot==3)
	{
		for(int i=0;i<js.size();++i)
		{
			if(jl[id][js[i]]&&!bd[js[i]])
			{
				bd[js[i]]=true;
				dfs(4,js[i],num+sum[js[i]]);
				bd[js[i]]=false;
			}
		}
	}
}
signed main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<n;++i)
		sum[i+1]=read();
	for(int i=1;i<=m;++i)
	{
		x=read(),y=read();
		jll[x].push_back(y);
		jll[y].push_back(x);
		jl[x][y]=true;
		jl[y][x]=true;
		if(x==1)
			js.push_back(y);
		if(y==1)
			js.push_back(x);
	}
	for(int i=0;i<js.size();++i)
		for(int j=0;j<jll[js[i]].size();++j)
			cnt.push_back(jll[js[i]][j]);
	dfs(0,1,0);
	cout<<ans;
	return 0;
}
