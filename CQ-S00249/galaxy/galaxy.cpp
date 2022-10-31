#include<bits/stdc++.h>
#define maxn 20002
using namespace std;
int wch[1001][1001],wcha[1001][1001];
struct node{
	int to,nxt;
}mm[maxn],ma[maxn];
int head[maxn],cntt,heada[maxn],cnta;
void add(int u,int v){
	mm[++cntt].nxt=head[u];
	mm[cntt].to=v;
	head[u]=cntt;
	wch[u][v]=cntt;
}
void adda(int u,int v){
	ma[++cnta].nxt=heada[u];
	ma[cnta].to=v;
	heada[u]=cnta;
	wcha[u][v]=cnta;
}
struct cntm{
	int in,out;
}now[maxn];
int n,m,T;
bool brk[maxn],brka[maxn];
bool vis[maxn];
int dfn[maxn],low[maxn],cnt,mch[maxn];
bool ins[maxn];
stack<int>s;
void tarjan(int x){
	//cout<<x<<endl;
	dfn[x]=low[x]=++cnt;
	s.push(x);
	ins[x]=1;
	for(int i=head[x];i;i=mm[i].nxt){
		int v=mm[i].to;
		//cout<<x<<" "<<v<<" "<<brk[wch[x][v]]<<" "<<brka[wcha[x][v]]<<endl;
		if(brk[wch[x][v]]||brka[wcha[x][v]]) continue;
		if(!dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}else if(ins[v]){
			low[x]=min(low[x],dfn[v]);
		}
	}
	if(dfn[x]==low[x]){
		int cntc=1;
		while(s.size()&&s.top()!=x){
			int now=s.top();
			ins[now]=0;
			s.pop();
			cntc++;
		}
		s.pop();
		mch[++cnt]=cntc;
	}
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		adda(v,u);
		now[v].in++;
		now[u].out++;
	}
	scanf("%d",&T);
	while(T--){
		int t;
		scanf("%d",&t);
		if(t==1){
			int u,v;
			scanf("%d%d",&u,&v);
			brk[wch[u][v]]=1;
			//brka[wcha[u][v]]=1;
			now[u].out--;
			now[v].in--;
		}
		if(t==2){
			int u;
			scanf("%d",&u);
			now[u].in=0;
			for(int i=heada[u];i;i=ma[i].nxt){
				int v=ma[i].to;
				//cout<<v<<" "<<u<<endl;
				brka[wcha[v][u]]=1;
				now[v].out--;
			}
		}
		if(t==3){
			int u,v;
			scanf("%d%d",&u,&v);
			brk[wch[u][v]]=0;
			brka[wcha[u][v]]=0;
			now[u].out++;
			now[v].in++;
		}
		if(t==4){
			int u;
			scanf("%d",&u);
			for(int i=heada[u];i;i=ma[i].nxt){
				int v=ma[i].to;
				now[v].out++;
				now[u].in++;
				brka[wcha[v][u]]=0;
			}
		}
		bool flag=1;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			if(now[i].out>1){
				printf("NO\n");
				flag=0;
				break;
			}
		}
		if(!flag) continue;
		flag=0;
		memset(dfn,0,sizeof(dfn));
		memset(ins,0,sizeof(ins));
		memset(low,0,sizeof(low));
		memset(mch,0,sizeof(mch));
		for(int i=1;i<=n;i++){
			if(!dfn[i]) tarjan(i);
		}
		for(int i=1;i<=cnt;i++){
			if(mch[i]>1){
				flag=1;
				break;
			}
		}
		if(flag){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}

