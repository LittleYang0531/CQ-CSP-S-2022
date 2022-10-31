#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3000;
const int maxm=1e6;
const ll mod=998244353;
ll a; 
ll val[maxn];
struct Edge{
	int v,w,nxt;
}e[maxm];
int cnt,h[maxn];
void add(int u,int v){
	e[++cnt].v=v; 
	e[cnt].nxt=h[u]; 
	h[u]=cnt;
} 
bool con[3005][3005];
queue<int>q;
int dis1[maxn]; 
bool vis1[maxn];
int afr[maxn],asc[maxn],atd[maxn];
int bfr[maxn],bsc[maxn]; 
int n,m,k;
void BFS(int s){
	for(int i=1;i<=n;i++)vis1[i]=0;
	vis1[s]=1;
	q.push(s);
	dis1[s]=0;
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(!vis1[v]){
				dis1[v]=dis1[u]+1;
				vis1[v]=1;
				q.push(v);
			}
		}	
	}		
}
ll ans;
inline void check(int a,int b,int c,int d){
	if(a==b||a==c||a==d)return ;
	if(!a||!b||!c||!d)return ;
	if(b==c||b==d)return ;
	if(c==d)return ;
//	if(val[a]+val[b]+val[c]+val[d]==30)
//	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	ans=max(ans,val[a]+val[b]+val[c]+val[d]);
}
int main(){ 
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ans=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)scanf("%lld",&val[i]);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++){
		BFS(i);
		for(int j=1;j<=n;j++){
			if(dis1[j]<=k+1)con[i][j]=1;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(i==j)continue;
			if(con[1][j]&&con[j][i]){ 
				if(val[j]>=val[afr[i]]){
					atd[i]=asc[i];
					asc[i]=afr[i];
					afr[i]=j;			
				}
				else if(val[j]>=val[asc[i]]){
					atd[i]=asc[i];
					asc[i]=j;
				}
				else if(val[j]>=val[atd[i]]){
					atd[i]=j;
				}
			}
		}
	} 
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(i==j)continue;
			if(!con[i][j])continue; 
			check(i,j,afr[i],afr[j]);
			check(i,j,asc[i],afr[j]);
			check(i,j,atd[i],afr[j]); 
			check(i,j,afr[i],asc[j]);
			check(i,j,asc[i],asc[j]);
			check(i,j,atd[i],asc[j]); 
			check(i,j,afr[i],atd[j]);
			check(i,j,asc[i],atd[j]);
			check(i,j,atd[i],atd[j]); 
		}
	}
	printf("%lld\n",ans);
	return 0;
}
