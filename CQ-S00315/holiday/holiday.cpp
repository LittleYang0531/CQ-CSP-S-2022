#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn=303;
long long val[maxn],maxx;
int n,m,k,head[maxn],cnt,head2[maxn],cnt2,dis[maxn],vis[maxn],mx[maxn][maxn][2],id[maxn][maxn][2];//0×î´ó 
bool cn[maxn][maxn];
struct node{int next,to;}e[1003],e2[90003];
void addedge(int x,int y){e[++cnt]=(node){head[x],y},head[x]=cnt;}
void addedge2(int x,int y){e2[++cnt2]=(node){head2[x],y},head2[x]=cnt2;}
struct node2{
	int x,dis;
	bool operator < (node2 &a) const{return dis<a.dis;}
};
queue<node2> q;
void dij(int s){
	for(int i=1;i<=n;++i) dis[i]=0x7fffffff,vis[i]=0;
	q.push((node2){s,0}),dis[s]=0;
	while(!q.empty()){
		while(vis[q.front().x]) q.pop();
		int x=q.front().x;q.pop(); vis[x]=1;
		for(int i=head[x],v;v=e[i].to,i;i=e[i].next){
			if(dis[v]>dis[x]+1) dis[v]=dis[x]+1,q.push((node2){v,dis[v]});
		}
	}for(int i=s+1;i<=n;++i) if(dis[i]<=k) addedge2(s,i),addedge2(i,s),cn[s][i]=cn[i][s]=1;
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k),++k;
	for(int i=2;i<=n;++i) scanf("%lld",&val[i]);
	for(int i=1,u,v;i<=m;++i) scanf("%d%d",&u,&v),addedge(u,v),addedge(v,u);
	for(int i=1;i<n;++i) dij(i);
	for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j) for(int p=1;p<=n;++p) if(cn[i][p]&&cn[j][p]){
		if(val[p]>mx[i][j][0]){
			mx[i][j][1]=mx[i][j][0],mx[i][j][0]=val[p];
			mx[j][i][1]=mx[j][i][0],mx[j][i][0]=val[p];
			id[i][j][1]=id[i][j][0],id[i][j][0]=p;
			id[j][i][1]=id[j][i][0],id[j][i][0]=p;
		}
		else if(val[p]>mx[i][j][1]){
			mx[i][j][1]=val[p];mx[j][i][1]=val[p];
			id[i][j][1]=p;id[j][i][1]=p;
		}
	}
	for(int ii=head2[1],i;i=e2[ii].to,ii;ii=e2[ii].next)
		for(int jj=head2[1],j;j=e2[jj].to,jj;jj=e2[jj].next) if(i!=j)
			for(int pp=head2[i],p;p=e2[pp].to,pp;pp=e2[pp].next) if(p!=j&&p!=1&&id[j][p][0]){
				if(id[p][j][0]==i) maxx=max(maxx,val[i]+val[j]+val[p]+mx[j][p][1]);
				else maxx=max(maxx,val[i]+val[j]+val[p]+mx[j][p][0]);
			}
	cout<<maxx<<'\n';
	return 0;
}
