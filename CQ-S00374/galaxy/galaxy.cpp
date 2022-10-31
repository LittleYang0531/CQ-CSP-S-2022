#include<cstdio>
#include<vector>
using namespace std;
const int N=5e5+5,spN=1e3+5;
struct seg{
	int a[N<<2],b[N<<2],n;
	void pushup(int k){
		a[k]=max(a[k<<1],a[k<<1|1]);
		b[k]=min(b[k<<1],b[k<<1|1]);
	}
	int x,y;
	void upd_1(int k,int l,int r){
		if(l==r)return (void)(a[k]+=y,b[k]+=y);
		int mid=l+r>>1;
		if(x<=mid)upd_1(k<<1,l,mid);
		else upd_1(k<<1|1,mid+1,r);
		pushup(k);
	}
	void upd(int X,int Y){
		x=X,y=Y,upd_1(1,1,n);
	}
	int ask_all(bool op){
		if(op)return a[1];
		return b[1];
	}
}a;
int n,m,q;
bool sp=1,flg[spN][spN];
struct query{int op,u,v;}p[N];
vector<int>e[N],ex[N];
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d %d",&n,&m),a.n=n;
	for(int i=1,u,v;i<=m;i++){
		scanf("%d %d",&u,&v),e[u].push_back(v),ex[v].push_back(u);
		a.upd(u,1);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d %d",&p[i].op,&p[i].u);
		if(p[i].op==1||p[i].op==3)scanf("%d",&p[i].v);
		else sp=0;
	}
//	printf("%d\n",sp);
	for(int i=1;i<=q;i++){
		if(sp){
			if(p[i].op==1)a.upd(p[i].u,-1);
			else a.upd(p[i].u,1);
		}else{
			if(p[i].op==1){
				a.upd(p[i].u,-1),flg[p[i].u][p[i].v]=1;
			}else if(p[i].op==2){
				for(int v:ex[p[i].u])
					if(!flg[v][p[i].u])a.upd(v,-1),flg[v][p[i].u]=1;
			}else if(p[i].op==3){
				a.upd(p[i].u,1),flg[p[i].u][p[i].v]=0;
			}else{
				for(int v:ex[p[i].u])
					if(flg[v][p[i].u])a.upd(v,1),flg[v][p[i].u]=0;
			}
		}
//		for(int u=1;u<=n;u++){
//			for(int v=1;v<=n;v++)printf("%d ",flg[u][v]);
//			printf("\n");
//		}
		printf("%s\n",a.ask_all(0)==1&&a.ask_all(1)==1?"YES":"NO");
	}
	return 0;
}
