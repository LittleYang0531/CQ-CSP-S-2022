#include<algorithm>
#include<cstdio>
#include<vector>
int read(){
	int x=0,tp=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')tp=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*tp;
}
void print(int x){
	if(x>9)print(x/10);
	putchar(x%10+48);
	return;
}
void write(int x,char ch){
	if(x<0)putchar('-'),write(-x,ch);
	else print(x),putchar(ch);
	return;
}
const int maxn=5e5+5;
const int edgm=maxn;
struct edge{
	int to,next;
	int w;
}qxx[edgm];
int qxx_cnt,h[maxn];
void add(int x,int y,int z){
	qxx[++qxx_cnt]=(edge){y,h[x],z};
	h[x]=qxx_cnt;
	return;
}
int n,m,q;
int val[maxn];
bool loop[maxn],vis[maxn];
bool go(int x){
	if(vis[x])return loop[x]=true;
	vis[x]=true;
	bool have=false;
	for(int i=h[x];i;i=qxx[i].next){
		int v=qxx[i].to;
		if((qxx[i].w>0&&val[v]>0)||(qxx[i].w>-val[v])||(val[v]>-qxx[i].w)){
			if(have)return false;
			have=true;
			if(!go(v))return false;
		}
	}
	return have;
}
signed main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y,1);
	}
	for(int i=1;i<=n;i++)val[i]=1;
	scanf("%d",&q);
	for(int i=2;i<=q+1;i++){
		int tp;
		scanf("%d",&tp);
		if(tp==1){
			int x,y;
			scanf("%d%d",&x,&y);
			for(int j=h[x];j;j=qxx[j].next){
				int v=qxx[j].to;
				if(v==y){
					qxx[j].w=-i;
					break;
				}
			}
		}
		else if(tp==2){
			int x;
			scanf("%d",&x);
			val[x]=-i;
		}
		else if(tp==3){
			int x,y;
			scanf("%d%d",&x,&y);
			for(int j=h[x];j;j=qxx[j].next){
				int v=qxx[j].to;
				if(v==y){
					qxx[j].w=i;
					break;
				}
			}
		}
		else{
			int x;
			scanf("%d",&x);
			val[x]=i;
		}
		for(int i=1;i<=n;i++)loop[i]=vis[i]=false;
		bool can=true;
		for(int i=1;i<=n;i++)if(!go(i)){
			can=false;
			break;
		}
		printf("%s\n",can?"YES":"NO");
	}
	return 0;
}
//namespace burningContract
/*
3 6
2 3
2 1
1 2
1 3
3 1
3 2
11
1 3 2
1 2 3
1 1 3
1 1 2
3 1 3
3 3 2
2 3
1 3 1
3 1 3
4 2
1 3 2
*/
