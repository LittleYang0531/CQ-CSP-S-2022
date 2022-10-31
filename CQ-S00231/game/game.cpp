#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void _fre(string txt);
template<typename T> inline void read(T& x);
template<typename... Args> inline void read(Args& ...args);
const int N=1e5+5;
const ll Inf=1e18;
const int Up=1e7;
int n,m,q;
ll a[N],b[N];
int lg[N];
struct st{
	ll max_[N][17+3],min_[N][17+3];
	void init(ll* c,int len){
		for(int i=1;i<=len;i++){
			max_[i][0]=min_[i][0]=c[i];
		}
		for(int k=1;k<=lg[len];k++){
			for(int l=1,r;l+(1<<k)-1<=len;l++){
				r=l+(1<<k)-(1<<(k-1));
				max_[l][k]=max(max_[l][k-1],max_[r][k-1]);
				min_[l][k]=min(min_[l][k-1],min_[r][k-1]);
			}
		}
	}
	inline ll ask_max(int l,int r){
		int k=lg[r-l+1]-1;
		return max(max_[l][k],max_[r-(1<<(k))+1][k]);
	}
	inline ll ask_min(int l,int r){
		int k=lg[r-l+1]-1;
		return min(min_[l][k],min_[r-(1<<k)+1][k]);
	}
};
st L,Q;
int main(){
	_fre("game");
	read(n,m,q);
	for(int i=1;i<=max(n,m);i++) lg[i]=lg[i/2]+1;
	bool flag=1;
	for(int i=1;i<=n;i++) read(a[i]),flag&=(a[i]>0);
	for(int i=1;i<=m;i++) read(b[i]),flag&=(b[i]>0);
	L.init(a,n),Q.init(b,m);
	for(int now=1,l1,r1,l2,r2;now<=q;now++){
		read(l1,r1,l2,r2);
		if(flag){
			printf("%lld\n",L.ask_max(l1,r1)*Q.ask_min(l2,r2));
			continue;
		}
		ll ans=-Inf;
		if(l1==r1){
			if(a[l1]>0) ans=a[l1]*Q.ask_min(l2,r2);
			else ans=a[l1]*Q.ask_max(l2,r2);
			printf("%lld\n",ans);
			continue;
		}
		if(l2==r2){
			if(b[l2]>0) ans=b[l2]*L.ask_max(l1,r1);
			else ans=b[l2]*L.ask_min(l1,r1);
			printf("%lld\n",ans);
			continue;
		}
		for(int i=l1;i<=r1;i++){
			ll minn=Inf;
			for(int j=l2;j<=r2;j++){
				ll c=a[i]*b[j];
				minn=min(minn,c);
			}
			if(minn>ans) ans=minn;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

inline void _fre(string txt){
	string in_buf=txt+".in";
	string out_buf=txt+".out";
	freopen(in_buf.c_str(),"r",stdin);
	freopen(out_buf.c_str(),"w",stdout);
}
template<typename T> inline void read(T& x){
	x=0;bool flag=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') flag=1;
	if(flag) for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)-(ch&15);
	else for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch&15);
}
template<typename... Args> inline void read(Args& ...args){
	int arg[]{(read(args),0)...};
	if(0) *arg=*arg;
}
