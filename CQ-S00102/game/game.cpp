#include<bits/stdc++.h>
#define ll long long
#define N 100000
#define inf 0x7f7f7f7f
#define inff 0x7f7f7f7f7f7f7f7f
using namespace std;

inline int read(){
	int s=0,w=1;char c=getchar();
	while(c<48||c>57) {if(c=='-') w=-1;c=getchar();}
	while(c>=48&&c<=57) s=(s<<1)+(s<<3)+c-48,c=getchar();
	return s*w;
}

inline void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+48);
}

int n,m,q;
int a[N+100],b[N+100];

struct node{
	int ax1,in1,ax2,in2;
}tre[2][N<<4],org;
node merge(node x,node y){
	node tmp=org;
	tmp.ax1=max(x.ax1,y.ax1),tmp.in1=min(x.in1,y.in1);
	tmp.ax2=max(x.ax2,y.ax2),tmp.in2=min(x.in2,y.in2);
	return tmp;
}
void build(int i,int l,int r,bool ca){
	if(l==r){
		int x=(ca?b[l]:a[l]);
		if(x<0) tre[ca][i]=(node){-inf,inf,x,x};
		else tre[ca][i]=(node){x,x,-inf,inf};
		return;
	}
	int mid=l+r>>1;
	build(i<<1,l,mid,ca),build((i<<1)+1,mid+1,r,ca);
	tre[ca][i]=merge(tre[ca][i<<1],tre[ca][(i<<1)+1]);
}
node find(int i,int l,int r,int L,int R,bool ca){
	if(L<=l&&r<=R) return tre[ca][i];
	int mid=l+r>>1;node tmp=org;
	if(L<=mid) tmp=merge(tmp,find(i<<1,l,mid,L,R,ca));
	if(R>mid) tmp=merge(tmp,find((i<<1)+1,mid+1,r,L,R,ca));
	return tmp;
}

ll tpn[10],tpm[10];
int main(){

	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);

	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int j=1;j<=m;j++) b[j]=read();
	
	org=(node){-inf,inf,-inf,inf};
	build(1,1,n,0),build(1,1,m,1);

	while(q--){
		
		int ln=read(),rn=read();
		int lm=read(),rm=read();
		
		node A=find(1,1,n,ln,rn,0);
		node B=find(1,1,m,lm,rm,1);
		tpn[1]=A.ax1,tpn[2]=A.in1,tpn[3]=A.ax2,tpn[4]=A.in2;
		tpm[1]=B.ax1,tpm[2]=B.in1,tpm[3]=B.ax2,tpm[4]=B.in2;
		
		ll ans=-inff;
		for(int i=1;i<=4;i++){
			if(tpn[i]==inf||tpn[i]==-inf) continue;
			ll tmp=inff;
			for(int j=1;j<=4;j++) if(tpm[j]!=inf&&tpm[j]!=-inf)
				tmp=min(tmp,tpn[i]*tpm[j]);
			ans=max(ans,tmp);
		}
		
		write(ans),puts("");
	}

	return 0;
}

