#include<bits/stdc++.h>
using namespace std;
const long long N=2505;
const long long M=1e4+5;
const long long INF=1e18+5;
struct holiday
{
	vector<long long>v;
};
struct stackk
{
	long long p[N],num;
	void push(long long x)
	{
		num++;
		p[num]=x;
	}
	void pop()
	{
		p[num]=0;
		num--;
	}
	long long size()
	{
		return num;
	}
	long long top()
	{
		return p[num];
	}
	long long find(long long x)
	{
		for(long long i=1;i<=num;i++)
		{
			if(p[i]==x)
			{
				return i;
			}
		}
		return 0;
	}
};
long long n,m,k,x,y,ret;
long long ans[N];
stackk  back;
vector<long long>v[N];
holiday p[N];
void bbfs(long long parent,long long now,long long l)
{
	p[parent].v.push_back(now);
	if(l==0)
	{
		return;
	}
	for(long long i=0;i<v[now].size();i++)
	{
		bbfs(parent,v[now][i],l-1);
	}
}
void bfs(long long now)
{
	for(long long i=0;i<v[now].size();i++)
	{
		bbfs(now,v[now][i],k);
	}
}
void dfs(long long now,long long sum)
{
	if(back.find(now)!=0||(back.size()==4&&now!=1))
	{
		return;
	}
	if(now==1&&back.size()==4)
	{
		ret=max(ret,sum);
		return;;
	}
	back.push(now);
	for(long long i=0;i<p[now].v.size();i++)
	{
		dfs(p[now].v[i],sum+ans[now]);
	}
	back.pop();
}
int main()
{
	ret=-INF;
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=2;i<=n;i++)
	{
		scanf("%lld",&ans[i]);
	}
	for(long long i=1;i<=m;i++){
		scanf("%lld%lld",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(long long i=1;i<=n;i++)
	{
		bfs(i);
	}
	for(long long i=0;i<v[1].size();i++)
	{
		dfs(v[1][i],0);
	}
	printf("%lld",ret);
	return 0;
}
