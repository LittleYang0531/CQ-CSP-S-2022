#include<bits/stdc++.h>
#define int long long 
using namespace std;//zaayyds!
struct XX{
	int shu,id;
}b[1000005];
bool cmp(XX zaax,XX zaay){
	return zaax.shu<zaay.shu;
}
int a[100005];
int u,v,f[100005];
int n,qu,k,nxt[10005],head[10005],to[10005],dis[2501][2501],tot;
bool book[10005];
void add(int a,int b){nxt[++tot]=a,to[tot]=b;}
int q[100005];
int zhan,tl,hd;
bool cnm[100005];
void dij(int zaa){
	tl=2,hd=1;
	q[1]=zaa;
	book[zaa]=1;
	dis[zaa][zaa]=0;
	for(int i=1;i<=n;i++){
		if(dis[zaa][i]==0) q[tl]=i,tl++;
	}
	tl--;
	while(tl>=hd){
		int s=q[hd];
		for(int i=1;i<=tot;i++){
			if(dis[zaa][to[i]]>dis[zaa][nxt[i]]+1){
				dis[zaa][to[i]]=dis[zaa][nxt[i]]+1;
				tl++;
				q[tl]=nxt[i];
			}
		}
		hd++;
	}
}
int minx=1e12;
int dfs(int xx,int yy,int sum){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(dis[xx][i]+dis[i][yy]==dis[xx][yy]){
			ans+=a[i];
		}
	}
	return ans;
}
signed main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	memset(head,-1,sizeof head);
	cin>>n>>qu>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i].shu=a[i];
		b[i].id=i;
	}
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			dis[i][j]=1e12;
		f[i]=i;
	}
	for(int i=1;i<=n-1;i++){
		cin>>u>>v;
		add(u,v);
		add(v,u);
		dis[u][v]=1;
		dis[v][u]=1;
	}
	for(int i=1;i<=n;i++){
		dij(i);
	}
	for(int i=1;i<=qu;i++){
		int ll,rr;
		cin>>ll>>rr;
		if(dis[ll][rr]<=k){
			cout<<dfs(ll,rr,0)<<endl;;
		}
		else if(k>1){
			int s=1;
			while(1){
				if(b[s].id==ll||b[s].id==rr){
					s++;
				}
				else{
					break;
				}
			}
			cout<<a[ll]+a[rr]+b[s].shu<<endl;
		}
		else{
			minx=1e12;
			for(int i=1;i<=n;i++){
				if(ll==i||rr==i) continue;
				if(dis[ll][i]==1||dis[rr][i]==1){
					minx=min(minx,i);
				}
			}
			cout<<a[ll]+a[rr]+b[s].shu<<endl;
		}
	}
	
	//cout<<(int)log(2500);
	return 0;
}/*
1221097936
1086947276
1748274667
887646183
939363946
900059971
964517506
1392379601
992068897
541763489


*/
