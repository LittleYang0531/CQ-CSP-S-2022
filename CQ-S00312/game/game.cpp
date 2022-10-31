//No more time, No more chance.
#include <cstdio>
#include <algorithm>
using std :: min;using std :: max;
namespace KamiyamaShiki{
	typedef long long ll;
	const int maxn = 1e5+5,inf = 1145141923;
	int n,m,q,a[maxn],b[maxn],ta[maxn];
	struct Seg{
		int mx[maxn<<2],mn[maxn<<2],N;
		void byd(int k,int l,int r,int *a){
			if(l == r)return mx[k] = mn[k] = a[l],void();
			int mid = l+r>>1;byd(k<<1,l,mid,a),byd(k<<1|1,mid+1,r,a);
			mn[k] = min(mn[k<<1],mn[k<<1|1]),mx[k] = max(mx[k<<1],mx[k<<1|1]);
		}
		int Mn(int k,int l,int r,int x,int y){
			if(l>y||r<x)return inf;if(l>=x&&r<=y)return mn[k];
			int mid = l+r>>1;return min(Mn(k<<1,l,mid,x,y),Mn(k<<1|1,mid+1,r,x,y));
		}
		int Mx(int k,int l,int r,int x,int y){
			if(l>y||r<x)return -inf;if(l>=x&&r<=y)return mx[k];
			int mid = l+r>>1;return max(Mx(k<<1,l,mid,x,y),Mx(k<<1|1,mid+1,r,x,y));
		}
		int Min(int l,int r){return Mn(1,1,N,l,r);}
		int Max(int l,int r){return Mx(1,1,N,l,r);}
	}A,B,NA,PA;
	int main(){
		freopen("game.in","r",stdin);
		freopen("game.out","w",stdout);
		scanf("%d %d %d",&n,&m,&q);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=m;++i)scanf("%d",&b[i]);
		A.byd(1,1,n,a),B.byd(1,1,m,b),PA.N = NA.N = A.N = n,B.N = m;
		for(int i=1;i<=n;++i)ta[i] = (a[i]<=0?-a[i]:inf);NA.byd(1,1,n,ta);
		for(int i=1;i<=n;++i)ta[i] = (a[i]>=0?a[i]:inf);PA.byd(1,1,n,ta);
		//0 需要进行一个特殊讨论。上面写上 = 就可以了。 
		//nm 不要写反。 
		while(q--){
			int l1,l2,r1,r2,ta,tb;
			scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
			//烦人。请一个一个一个一个分讨清楚。 
			if((tb=B.Min(l2,r2)) >= 0){
				ta = A.Max(l1,r1);
				if(ta >= 0)printf("%lld\n",1ll*ta*tb);
				else printf("%lld\n",1ll*ta*B.Max(l2,r2));
			}else if((tb=B.Max(l2,r2)) <= 0){
				ta = A.Min(l1,r1);
				if(ta <= 0)printf("%lld\n",1ll*ta*tb);
				else printf("%lld\n",1ll*ta*B.Min(l2,r2));
			}else{
				ll ans = max(1ll*PA.Min(l1,r1)*B.Min(l2,r2),1ll*(-NA.Min(l1,r1))*B.Max(l2,r2)); 
				printf("%lld\n",ans);
			}
		}
		return 0;
	}
}
int main(){return KamiyamaShiki::main();}
/*
检查 Corner Case
检查快读（正负数，buf[1<<!6]）
nmq 不要写反。
对拍不要骗自己。
*/

