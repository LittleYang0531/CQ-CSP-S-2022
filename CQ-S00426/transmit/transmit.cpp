#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
#define x first
#define y second

const int N = 2*1e5+10;

int n,pd,k;

int h[N],e[N*2],ne[N*2],cnt,f[N],c[N],cds[N];long long dis[N],CSP_RP_S_J;
bool arr[N];

vector<int> v[N];

int gf(int u){
	if(f[u]!=u) f[u]=gf(f[u]);
	return f[u];
}

void add(int a,int b,int ct)
{
	e[++cnt]=b;
	ne[cnt]=h[a];
	h[a]=cnt;
	c[cnt]=ct;
}
//T4!@%$%$%%@#^Ê÷ÐÎdp£¡ 
priority_queue<PII> q;
void dij(int rt){
	while(q.size()) q.pop();
	memset(dis,0x3f,sizeof(dis));memset(arr,0,sizeof(arr));
	dis[rt]=cds[rt];
	q.push({0,rt});
	while(q.size()){
		int u=q.top().y;q.pop();
		if(arr[u]) continue;arr[u]=1;
		for(int i=h[u];i;i=ne[i]){
			int j=e[i];
			if(dis[j]>dis[u]+c[i]){
				dis[j]=dis[u]+c[i];
				q.push({dis[j],j});
			}
		}
	}
}
 
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&pd,&k);
	for(int i=1;i<=n;i++) scanf("%d",&cds[i]);
	f[n]=1;
	for(int i=1,a,b;i<n;i++){
		f[i]=i;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);v[b].push_back(a);
		add(a,b,cds[b]);add(b,a,cds[a]);
	}
	if(k==1){
		int rt,td;
		while(pd--){
			scanf("%d%d",&rt,&td);
			dij(rt);
			printf("%lld\n",dis[td]);
		}
		return 0;
	}
	while(CSP_RP_S_J< 1ll<<40) CSP_RP_S_J+=1e9;
	return 0;
}
