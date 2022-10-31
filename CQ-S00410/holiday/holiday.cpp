#include<bits/stdc++.h>
#define pii pair<int,int>
#define id second
#define val first
using namespace std;
const int N = 1e4+14;
int n,m,k,ans,a[N];
set<pii>s[N];
int h[N],e[N],ne[N],tot=1;
bitset<N>vis;
void add(int u,int v){e[tot]=v,ne[tot]=h[u],h[u]=tot++;}
void dfs(int start,int u,int stop){
	if(~stop)s[start].insert({a[u],u});
	vis[u]=1;
	if(stop==k)return;
	for(int i=h[u];i;i=ne[i])
		if(!vis[e[i]])dfs(start,e[i],stop+1);
}
signed main(){
	#ifndef SNOWIO
		freopen("holiday.in","r",stdin);
		freopen("holiday.out","w",stdout);
	#endif
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1,u,v;i<=m;i++)
		scanf("%d%d",&u,&v),
		add(u,v),add(v,u);
	for(int i=1;i<=n;i++)
		vis.reset(),dfs(i,i,-1);
	for(auto i=s[1].rbegin();i!=s[1].rend();i++){
		auto j=i;
		for(++j;j!=s[1].rend();j++){
			for(auto k=s[i->id].rbegin();k!=s[i->id].rend();k++){
				if((*k)==(*j))continue;
				if((*k)==(pii){0,1})continue;
				for(auto l=s[j->id].rbegin();l!=s[j->id].rend();l++){
					if((*k)==(*l)||(*i)==(*l))continue;
					if((*l)==(pii){0,1})continue;
					auto p = s[k->id].find({a[l->id],l->id});
					if(p->id)
						ans=max(ans,a[i->id]+a[j->id]+a[k->id]+a[l->id]);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}