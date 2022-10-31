#include<bits/stdc++.h>
using namespace std;
const unsigned int N=4e3+15;
int n,m,q;
bool des_node[N],des_edge[N][N];
int deg[N],head[N],head2[N],num_edge,cst_deg[N],dfs_flag=false;
bool vis[N];
struct Edge{
	int next;
	int to;
}a[N*5],b[N*5];
inline void read(int &x){
	x=0;
	int y=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')
		y=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar(); 
	}
	x*=y;
}
void add_edge(int from,int to){
	a[++num_edge].next=head[from];
	a[num_edge].to=to;
	head[from]=num_edge;
	deg[from]++;
	cst_deg[from]++;
	b[++num_edge].next=head2[to];
	b[num_edge].to=from;
	head2[to]=num_edge;
}
void init(){
	for(register int i=1;i<=n;i++)
	vis[i]=false;
}
void dfs(int x){
	for(register int i=head[x];i;i=a[i].next){
		int v=a[i].to;
		if(des_edge[x][v])
		continue;
		if(vis[x]){
			dfs_flag=true;
			return;
		}
		vis[x]=true;
		dfs(v);
	}
}
signed main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	read(n);
	read(m);
	for(register int i=1;i<=m;i++){
		int u,v;
		read(u);
		read(v);
		add_edge(u,v);
	}
	read(q);
	while(q--){
		int t,u,v;
		bool flag=false;
		read(t);
		if(t==1){
			read(u);
			read(v);
			if(des_edge[u][v]==false)
			deg[u]--;
			des_edge[u][v]=true;
		}
		if(t==2){
			read(u);
			for(register int i=head2[u];i;i=b[i].next){
				int v=b[i].to;
				if(!des_edge[v][u]){
					des_edge[v][u]=true;
					deg[v]--;
				}
			}
		}
		if(t==3){
			read(u);
			read(v);
			if(des_edge[u][v]==true){
				deg[u]++;
				des_edge[u][v]=false;	
			}	
		}
		if(t==4){
			read(u);
			for(register int i=head2[u];i;i=b[i].next){
				int v=b[i].to;
				if(des_edge[v][u]){
					deg[v]++;
					des_edge[v][u]=false;
				}
			}
		}
		for(register int i=1;i<=n;i++){
			//printf("deg[%d]=%d\n",i,deg[i]);
			if(deg[i]!=1){
				if(!flag)
				puts("NO");
				flag=true;
				break;
			}
		}
		if(!flag){
			for(register int i=1;i<=n;i++){
				init();
				dfs(i);
				if(!dfs_flag){
					flag=true;
					puts("NO");
					break;
				}
			}
			if(!flag)
			puts("YES");
		}
	}
	return 0;
}
//40pts
//Xiao Ting wo zhen de hao xi huan ni!
