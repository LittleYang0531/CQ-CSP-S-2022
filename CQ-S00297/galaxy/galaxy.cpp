#include<bits/stdc++.h>
using namespace std;
#define ls u<<1
#define rs u<<1|1
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define eb(x) emplace_back(x) 
typedef pair<int,int> pii;
const int N=5e5+10;
int n,m,q,d[N],op[N],stk[N],top,cnt;
pii E[N];
vector<int>v[N],fro[N];
vector<pii>g[N];
vector<int>tr[N<<2];
int state[N];
void modify(int u,int L,int R,int l,int r,int id)
{
	if(l>r) return;
	if(l<=L && R<=r)
	{
		tr[u].eb(id);
		return;	
	}	
	int mid=(L+R)>>1;
	if(l<=mid) modify(ls,L,mid,l,r,id);
	if(mid<r) modify(rs,mid+1,R,l,r,id);
} 

void dfs(int u,int L,int R)
{
	int tmp=top;
	for(auto x:tr[u])
	{
		d[E[x].fi]++;
		if(d[E[x].fi]==1) cnt++;
		else if(d[E[x].fi]==2) cnt--;
		stk[++top]=E[x].fi;
	}
	int mid=(L+R)>>1;
	if(L==R) puts(cnt==n?"YES":"NO");
	else dfs(ls,L,mid),dfs(rs,mid+1,R);
	while(top>tmp)
	{
		d[stk[top]]--;
		if(d[stk[top]]==1) cnt++;
		else if(d[stk[top]]==0) cnt--;
		top--;
	 } 
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		E[i]=mp(a,b);
		g[a].eb(mp(b,i));
		fro[b].eb(i);
	}
	for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
	for(int i=1;i<=m;i++) v[i].eb(1),state[i]=1;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&op[i]);
		int u,v1,pos;
		switch(op[i])
		{
			case 1:{
				scanf("%d%d",&u,&v1);
				auto it=lower_bound(g[u].begin(),g[u].end(),mp(v1,0));
				v[it->se].eb(i);
				state[it->se]=0;
				break;
			} 
			case 2:{
				scanf("%d",&pos);
				for(auto x:fro[pos]) if(state[x]) v[x].eb(i),state[x]=0;
				break;
			}
			case 3:{
				scanf("%d%d",&u,&v1);
				auto it=lower_bound(g[u].begin(),g[u].end(),mp(v1,0));
				v[it->se].eb(i);
				state[it->se]=1;
				break;
			}
			case 4:{
				scanf("%d",&pos);
				for(auto x:fro[pos]) if(!state[x]) v[x].eb(i),state[x]=1;
				break;
			}
		} 
	}
	for(int i=1;i<=m;i++) v[i].eb(q+1);
	for(int i=1;i<=m;i++)
		for(int j=0;j<(int)v[i].size()-1;j++)
			if(j%2==0) modify(1,1,q,v[i][j],v[i][j+1]-1,i);
	dfs(1,1,q);
	
	return 0;
}
