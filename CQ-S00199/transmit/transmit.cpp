#include<stdio.h>
#include<algorithm>
using std::min;
const long long inf=1000000000000000000;
struct node{
	int v;
	int nextn;
}b[400005];
int bn,lastn[200005];
int n,q,k;
long long v_[200005];
long long vv[200005];
int u,v;
int size[200005];
int dep[200005];
int son[200005];
int fa[200005];
int top[200005];
int dfn[200005],Dfs;
long long minv[200005][3];
long long minvv[200005][3];
long long t[800005][3][3];
long long tt[800005][3][3];
long long ans[3];
long long ss[3];
int ll[30],rr[30],sz;
inline void in(int u,int v)
{
	++bn;
	b[bn].v=v;
	b[bn].nextn=lastn[u];
	lastn[u]=bn;
}
inline void dfs(int u)
{
//	printf("%d\n",u);
	dep[u]=dep[fa[u]]+1;
	size[u]=1;
	minv[u][0]=v_[u];
	minv[u][1]=inf;
	minv[u][2]=inf;
	for(int i=lastn[u];i>0;i=b[i].nextn)
	{
		if(b[i].v!=fa[u])
		{
			fa[b[i].v]=u;
			dfs(b[i].v);
			size[u]+=size[b[i].v];
			if(size[b[i].v]>size[son[u]])
			{
				son[u]=b[i].v;
			}
			minv[u][1]=min(minv[u][1],minv[b[i].v][0]);
			minv[u][2]=min(minv[u][2],minv[b[i].v][1]);
		}
	}
}
inline void dfs2(int u)
{
	dfn[u]=++Dfs;
	minv[u][1]=min(minv[u][1],minv[fa[u]][0]);
	minv[u][2]=min(minv[u][2],minv[fa[u]][1]);
	if(!top[u])
	{
		top[u]=u;
	}
	if(son[u])
	{
		top[son[u]]=top[u];
		dfs2(son[u]);
	}
	for(int i=lastn[u];i>0;i=b[i].nextn)
	{
		if(b[i].v!=fa[u]&&b[i].v!=son[u])
		{
			dfs2(b[i].v);
		}
	}
}
inline void build(int p,int L,int R)
{
	if(L==R)
	{
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<k;j++)
			{
				tt[p][i][j]=t[p][i][j]=inf;
			}
			if(i>0)
			{
				tt[p][i][i-1]=t[p][i][i-1]=0;
			}
			tt[p][i][k-1]=t[p][i][k-1]=vv[L];
			if(i>0)
			{
				tt[p][i][k-2]=t[p][i][k-2]=min(t[p][i][k-2],minvv[L][1]);
			}
			if(i>1)
			{
				tt[p][i][k-3]=t[p][i][k-3]=min(t[p][i][k-3],minvv[L][2]);
			}
		}
	}
	else
	{
		int mid=(L+R)>>1;
		build(p<<1,L,mid);
		build(p<<1|1,mid+1,R);
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<k;j++)
			{
				tt[p][i][j]=t[p][i][j]=inf;
			}
		}
		for(int l=0;l<k;l++)
		{
			for(int i=0;i<k;i++)
			{
				for(int j=0;j<k;j++)
				{
					t[p][i][j]=min(t[p][i][j],t[p<<1][i][l]+t[p<<1|1][l][j]);
					tt[p][i][j]=min(tt[p][i][j],tt[p<<1|1][i][l]+tt[p<<1][l][j]);
				}
			}
		}
	}
}
inline void query1(int p,int L,int R,int l,int r)
{
	if(l<=L&&r>=R)
	{
//		printf("%d %d:\n",L,R);
//		for(int i=0;i<k;i++)
//		{
//			printf("%lld ",ans[i]);
//		}
//		printf("\n");
//		for(int i=0;i<k;i++)
//		{
//			for(int j=0;j<k;j++)
//			{
//				printf("%lld ",tt[p][i][j]);
//			}
//			printf("\n");
//		}
		for(int i=0;i<k;i++)
		{
			ss[i]=ans[i];
			ans[i]=inf;
		}
		for(int l=0;l<k;l++)
		{
			for(int j=0;j<k;j++)
			{
				ans[j]=min(ans[j],ss[l]+tt[p][l][j]);
			}
		}
//		for(int i=0;i<k;i++)
//		{
//			printf("%lld ",ans[i]);
//		}
//		printf("\n");
	}
	else
	{
		int mid=(L+R)>>1;
		if(r>mid)
		{
			query1(p<<1|1,mid+1,R,l,r);
		}
		if(l<=mid)
		{
			query1(p<<1,L,mid,l,r);
		}
	}
}
inline void query2(int p,int L,int R,int l,int r)
{
	if(l<=L&&r>=R)
	{
		for(int i=0;i<k;i++)
		{
			ss[i]=ans[i];
			ans[i]=inf;
		}
		for(int l=0;l<k;l++)
		{
			for(int j=0;j<k;j++)
			{
				ans[j]=min(ans[j],ss[l]+t[p][l][j]);
			}
		}
	}
	else
	{
		int mid=(L+R)>>1;
		if(l<=mid)
		{
			query2(p<<1,L,mid,l,r);
		}
		if(r>mid)
		{
			query2(p<<1|1,mid+1,R,l,r);
		}
	}
}
inline void queryTree(int u,int v)
{
	sz=0;
	for(int i=0;i<k;i++)
	{
		ans[i]=inf;
	}
	ans[0]=0;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]>dep[top[v]])
		{
			query1(1,1,n,dfn[top[u]],dfn[u]);
			u=fa[top[u]];
		}
		else
		{
			++sz;
			ll[sz]=dfn[top[v]];
			rr[sz]=dfn[v];
			v=fa[top[v]];
		}
//		printf("%d %d\n",u,v);
//		for(int i=0;i<k;i++)
//		{
//			printf("%lld ",ans[i]);
//		}
//		printf("\n");
	}
	if(dfn[u]<dfn[v])
	{
		query2(1,1,n,dfn[u],dfn[v]);
	}
	else
	{
		query1(1,1,n,dfn[v],dfn[u]);
	}
//	for(int i=0;i<k;i++)
//	{
//		printf("%lld ",ans[i]);
//	}
//	printf("\n");
	for(int i=sz;i>=1;i--)
	{
		query2(1,1,n,ll[i],rr[i]);
//		for(int i=0;i<k;i++)
//		{
//			printf("%lld ",ans[i]);
//		}
//		printf("\n");
	}
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&v_[i]);
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		in(u,v);
		in(v,u);
	}
	minv[0][0]=minv[0][1]=minv[0][2]=inf;
	dfs(1);
	dfs2(1);
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d ",son[i]);
//	}
//	printf("\n");
	for(int i=1;i<=n;i++)
	{
		vv[dfn[i]]=v_[i];
		minvv[dfn[i]][0]=minv[i][0];
		minvv[dfn[i]][1]=minv[i][1];
		minvv[dfn[i]][2]=minv[i][2];
	}
	build(1,1,n);
	while(q--)
	{
		scanf("%d%d",&u,&v);
		queryTree(u,v);
		printf("%lld\n",ans[k-1]);
	}
//	sz=0;
//	for(int i=0;i<k;i++)
//	{
//		ans[i]=inf;
//	}
//	ans[0]=0;
//	query1(1,1,n,5,6);
	return 0;
}
/*
10 1 3
835701672 912572995 368308854 156367225 251245604 788978650 385396264 960190423 51944511 479806606
2 1
3 2
4 2
5 3
6 3
7 2
8 7
9 1
10 9
10 5

939363946
*/
