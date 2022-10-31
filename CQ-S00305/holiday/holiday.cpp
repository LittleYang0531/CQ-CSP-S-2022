#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,val[2505],q,w,p[2505],top,ans=-1,val1[2505],sh[8];
bool b[2505],co[2505];
struct node{int to,ne;}a[20002];
void add(int x,int y)
{
	a[++top].to=y;
	a[top].ne=p[x];
	p[x]=top;
}
void dfs(int x,int z,int ov,int lov)
{
//	printf("%d %d %d %d %d\n",x,z,sh[ov],ov,lov);
	if(z+sh[ov]<=ans)return;
	if(x==1&&ov==4){ans=max(ans,z);return;}
	for(int i=p[x];i;i=a[i].ne)
	{
		int v=a[i].to;
		if(lov<k)dfs(v,z,ov,lov+1);
	}
	if(ov>3||b[x])return;
	b[x]=1;
	for(int i=p[x];i;i=a[i].ne)
	{
		int v=a[i].to;
		if(v!=1&&!b[v])dfs(v,z+val[v],ov+1,0);
	}
	b[x]=0;
	return;
}
signed main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=2;i<=n;i++)scanf("%lld",&val[i]),val1[i]=val[i];
	sort(val1+2,val1+1+n);
	if(n>1)sh[3]=val1[n];
	if(n>2)sh[2]=sh[3]+val1[n-1];
	if(n>3)sh[1]=sh[2]+val1[n-2];
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&q,&w);
		add(q,w);add(w,q);
	}
	dfs(1,0,0,0);
	printf("%lld",ans);
	return 0;
}