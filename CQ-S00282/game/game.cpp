#include<algorithm>
#include<cstdio>
#include<vector>
namespace burningContract{
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
const int maxn=1e5+5;
const int logn=20;
const int iinf=1073741823;
const ll inf=1152921502459363329;
int val[maxn][2],lg[maxn];
struct stb{
	struct node{
		int pmx,pmi,nmx,nmi;
		bool zero;
	}got[maxn][logn];
	node merge(node now,node oth){return (node){
		std::max(now.pmx,oth.pmx),now.pmi||oth.pmi?std::min(now.pmi?now.pmi:iinf,oth.pmi?oth.pmi:iinf):0,
		std::min(now.nmx,oth.nmx),now.nmi||oth.nmi?std::max(now.nmi?now.nmi:-iinf,oth.nmi?oth.nmi:-iinf):0,
			now.zero||oth.zero};}
	void build(int n,int id){
		for(int i=1;i<=n;i++){
			if(val[i][id]>0)got[i][0].pmx=got[i][0].pmi=val[i][id];
			else if(val[i][id]<0)got[i][0].nmx=got[i][0].nmi=val[i][id];
			else got[i][0].zero=true;
		}
		for(int j=1;(1<<j)<=n;j++)for(int i=1;i+(1<<j)-1<=n;i++)
			got[i][j]=merge(got[i][j-1],got[i+(1<<(j-1))][j-1]);
		return;
	}
	node query(int l,int r){
		int k=lg[r-l+1];
		return merge(got[l][k],got[r-(1<<k)+1][k]);
	}
}row,col;
int n,m,q;
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=2;i<=maxn-2;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)val[i][0]=read();
	for(int i=1;i<=m;i++)val[i][1]=read();
	row.build(n,0),col.build(m,1);
	for(int i=1;i<=q;i++){
		int rl=read(),rr=read(),cl=read(),cr=read();
//		printf("i=%d\n",i);
		stb::node ro=row.query(rl,rr),co=col.query(cl,cr);
//		if(i==19){
//			printf("ro.pmx=%d,ro.pmi=%d,ro.nmx=%d,ro.nmi=%d,ro.zero=%d\n",ro.pmx,ro.pmi,ro.nmx,ro.nmi,ro.zero);
//			printf("co.pmx=%d,co.pmi=%d,co.nmx=%d,co.nmi=%d,co.zero=%d\n",co.pmx,co.pmi,co.nmx,co.nmi,co.zero);
//		}
		if((ro.pmx&&!co.nmx)||(ro.nmx&&!co.pmx)){
			if(co.zero)write(0,'\n');
			else if(co.pmi)write(1ll*ro.pmx*co.pmi,'\n');
			else write(1ll*ro.nmx*co.nmi,'\n');
		}
		else{
			if(ro.zero)write(0,'\n');
			else write(std::max(ro.nmi?1ll*ro.nmi*co.pmx:-inf,ro.pmi?1ll*ro.pmi*co.nmx:-inf),'\n');
		}
//		if(i==19)break;
	}
	return 0;
}
//namespace burningContract
}
signed main(){return burningContract::main();}
