#include<algorithm>
#include<cstdio>
#include<vector>
typedef long long ll;
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
void print(ll x){
	if(x>9)print(x/10);
	putchar(x%10+48);
	return;
}
void write(ll x,char ch){
	if(x<0)putchar('-'),write(-x,ch);
	else print(x),putchar(ch);
	return;
}
const int maxn=2e5+5;
const int logn=20;
const int edgm=maxn*2+5;
const ll inf=1152921502459363329;
struct edge{
	int to;
	int next;
}qxx[edgm];
int qxx_cnt,h[maxn];
void add(int x,int y){
	qxx[++qxx_cnt]=(edge){y,h[x]};
	h[x]=qxx_cnt;
	return;
}
void ad(int x,int y){
	add(x,y);
	add(y,x);
	return;
}
int n,q,k;
int d[maxn],fa[maxn],size[maxn],son[maxn];
void divide(int x,int f){
	fa[x]=f,d[x]=d[f]+1,size[x]=1;
	for(int i=h[x];i;i=qxx[i].next){
		int v=qxx[i].to;
		if(v==f)continue;
		divide(v,x);
		size[x]+=size[v];
		if(size[v]>size[son[x]])son[x]=v;
	}
	return;
}
int top[maxn];
int stay[maxn];
ll qzh[maxn],val[maxn][logn];
int over[maxn][logn];
void topen(int x,int tp){
	qzh[x]=stay[x]+qzh[fa[x]],top[x]=tp;
	if(son[x])topen(son[x],tp);
	for(int i=h[x];i;i=qxx[i].next){
		int v=qxx[i].to;
		if(v==fa[x]||v==son[x])continue;
		topen(v,v);
	}
	if(d[x]>=5){
		if(stay[fa[x]]+stay[fa[fa[fa[x]]]]>=stay[fa[fa[x]]])
			val[x][0]=stay[x]+stay[fa[fa[x]]],over[x][0]=fa[fa[fa[fa[x]]]];
		else val[x][0]=stay[x]+stay[fa[x]],over[x][0]=fa[fa[fa[x]]];
	}
	return;
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(d[top[x]]<d[top[y]])std::swap(x,y);
		x=fa[top[x]];
	}
	return d[x]<d[y]?x:y;
}
int fir[maxn],sec[maxn],fcnt,scnt;
ll mi[maxn];
ll query(int x,int y){
	int l=lca(x,y);
	int nx=x,ny=y;
	ll ret=0;
	if(!(n<=2000&&q<=2000)){
		for(int i=logn-2;i>=0;i--)if(d[over[nx][i]]>=d[l]+50)
			ret+=val[nx][i],nx=over[nx][i];
		for(int i=logn-2;i>=0;i--)if(d[over[ny][i]]>=d[l]+50)
			ret+=val[ny][i],ny=over[ny][i];
	}
//	printf("nx=%d,ny=%d\n",nx,ny);
	fcnt=scnt=0;
	while(nx!=l)fir[++fcnt]=nx,nx=fa[nx];
	while(ny!=l)sec[++scnt]=ny,ny=fa[ny];
	fir[++fcnt]=l;
	while(scnt)fir[++fcnt]=sec[scnt--];
	mi[1]=stay[fir[1]];
	if(fcnt>1)mi[2]=stay[fir[2]]+stay[fir[1]];
	for(int i=3;i<=fcnt;i++)mi[i]=stay[fir[i]]+std::min(mi[i-1],mi[i-2]);
	return ret+mi[fcnt];
}
void two(){
	for(int j=1;(1<<j)<=n;j++)for(int i=1;i<=n;i++){
		over[i][j]=over[over[i][j-1]][j-1];
		val[i][j]=val[i][j-1]+val[over[i][j-1]][j-1];
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",query(x,y));
	}
	return;
}
void one(){
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int l=lca(x,y);
		printf("%lld\n",qzh[x]+qzh[y]-qzh[l]-qzh[fa[l]]);
	}
	return;
}
signed main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++)scanf("%d",stay+i);
	for(int i=1;i<=n-1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ad(x,y);
	}
	d[0]=-1;
	divide(1,0),topen(1,1);
	if(k==2)two();
	else one();
	return 0;
}
//namespace burningContract
/*
8 3 1
6 4 2 4 3 5 1 7
1 2
2 3
3 4
2 7
2 5
5 6
7 8
4 8
8 6
4 6
*/
