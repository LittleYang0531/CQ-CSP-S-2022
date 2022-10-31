#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;

namespace Solve{
	const int N=100010,INF=1e9+1,LOG=20;
	int n,m,q,a[N],b[N];
	
	struct SegmentTree{
		struct Node{
			int l,r;
			int pmx,pmi,nmx,nmi,zero;
		}tr[N<<2];
		void pushup(int p){
			tr[p].zero=tr[p<<1].zero+tr[p<<1|1].zero;
			tr[p].pmx=max(tr[p<<1].pmx,tr[p<<1|1].pmx);
			tr[p].nmx=max(tr[p<<1].nmx,tr[p<<1|1].nmx);
			tr[p].pmi=min(tr[p<<1].pmi,tr[p<<1|1].pmi);
			tr[p].nmi=min(tr[p<<1].nmi,tr[p<<1|1].nmi);
		}
		void build(int p,int l,int r,int*arr){
			tr[p].l=l,tr[p].r=r;
			if(l==r){
				if(arr[l]==0){
					tr[p].zero=1;
					tr[p].pmx=-INF,tr[p].pmi=INF;
					tr[p].nmx=-INF,tr[p].nmi=INF;
				}
				else if(arr[l]<0){
					tr[p].zero=0;
					tr[p].pmx=-INF,tr[p].pmi=INF;
					tr[p].nmx=tr[p].nmi=arr[l];
				}
				else{
					tr[p].zero=0;
					tr[p].pmx=tr[p].pmi=arr[l];
					tr[p].nmx=-INF,tr[p].nmi=INF;
				}
				return;
			}
			int mid=(l+r)>>1;
			build(p<<1,l,mid,arr),build(p<<1|1,mid+1,r,arr);
			pushup(p);
		}
		void query(int p,int l,int r,int&pmx,int&pmi,int&nmx,int&nmi,int&zero){
			if(l<=tr[p].l&&tr[p].r<=r){
				pmx=max(pmx,tr[p].pmx);
				nmx=max(nmx,tr[p].nmx);
				pmi=min(pmi,tr[p].pmi);
				nmi=min(nmi,tr[p].nmi);
				zero+=tr[p].zero;
				return;
			}
			if(l<=tr[p<<1].r)query(p<<1,l,r,pmx,pmi,nmx,nmi,zero);
			if(r>=tr[p<<1|1].l)query(p<<1|1,l,r,pmx,pmi,nmx,nmi,zero);
		}
	}seg1,seg2;
	int Abs(int x){
		return x>=0?x:-x;
	}
	void main(){
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=m;i++)cin>>b[i];
		
		seg1.build(1,1,n,a),seg2.build(1,1,m,b);
		while(q--){
			int l1,r1,l2,r2;cin>>l1>>r1>>l2>>r2;
			int f[5]={-INF,INF,-INF,INF,0};
			int g[5]={-INF,INF,-INF,INF,0};
			seg1.query(1,l1,r1,f[0],f[1],f[2],f[3],f[4]);
			seg2.query(1,l2,r2,g[0],g[1],g[2],g[3],g[4]);
			
//			for(int i=0;i<5;i++)cerr<<f[i]<<' ';cerr<<"F\n";
//			for(int i=0;i<5;i++)cerr<<g[i]<<' ';cerr<<"G\n";
			ll ans=-(ll)INF*INF;
			for(int i=0;i<5;i++){
				if(Abs(f[i])==INF)continue;
				ll v1=f[i];
				if(i==4){
					if(!f[i])continue;
					v1=0;
				}
				ll mi=0;bool fir=1;
				for(int j=0;j<5;j++){
					if(Abs(g[j])==INF)continue;
					ll v2=g[j];
					if(j==4){
						if(!g[j])continue;
						v2=0;
					}
					if(fir){
						mi=v1*v2;
						fir=0;
					}
					mi=min(mi,v1*v2);
				}
				if(!fir)ans=max(ans,mi);
			}
			cout<<ans<<'\n';
		}
	}
	
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	Solve::main();
}
