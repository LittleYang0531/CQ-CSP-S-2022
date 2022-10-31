//你有没有感受到城市在分崩离析！
//估分100 
#include<cstdio>
#include<cctype>
namespace SOLVE{
	typedef long long ll;
	const int M=1e5+5;
	int n,m,q,a[M],b[M],AS[M],BS[M];int t[M];
	inline ll max(const ll&a,const ll&b){
		return a>b?a:b;
	}
	inline ll min(const ll&a,const ll&b){
		return a>b?b:a;
	}
	inline int read(){
		int n(0);char s;bool typ(false);while(!isdigit(s=getchar()))typ|=s==45;
		while(n=n*10+(s&15),isdigit(s=getchar()));return typ?-n:n;
	}
	inline void write(ll n){
		if(n<0)putchar(45),n=-n;
		static char s[30];int top(0);while(s[++top]=n%10^48,n/=10);while(putchar(s[top]),--top);putchar(10);
	}
	struct data{
		int mx,mi;
		data(const int&mx=-1,const int&mi=-1):mx(mx),mi(mi){}
		inline data operator+(const data&g)const{
			return data(!~mx?g.mx:!~g.mx?mx:max(mx,g.mx),!~mi?g.mi:!~g.mi?mi:min(mi,g.mi));
		}
	};
	struct sgt{
		data dat[M<<2];
		inline void update(const int&u){
			dat[u]=dat[u<<1]+dat[u<<1|1];
		}
		inline void Build(int*a,const int&u,const int&L,const int&R){
			if(L==R)return void(dat[u]=data(a[L],a[L]));
			const int&mid=L+R>>1;Build(a,u<<1,L,mid);Build(a,u<<1|1,mid+1,R);update(u);
		}
		inline data Qry(const int&u,const int&l,const int&r,const int&L,const int&R){
			if(l>R||L>r)return data();if(l<=L&&R<=r)return dat[u];
			const int&mid=L+R>>1;return Qry(u<<1,l,r,L,mid)+Qry(u<<1|1,l,r,mid+1,R);
		}
	}A1,A2,B1,B2;
	inline void main(){
		n=read();m=read();q=read();for(int i=1;i<=n;++i)a[i]=read();for(int i=1;i<=m;++i)b[i]=read();
		for(int i=1;i<=n;++i)AS[i]=AS[i-1]+(a[i]==0);
		for(int i=1;i<=m;++i)BS[i]=BS[i-1]+(b[i]==0);
		for(int i=1;i<=n;++i)t[i]=a[i]>0?a[i]:-1;A1.Build(t,1,1,n);
		for(int i=1;i<=m;++i)t[i]=b[i]>0?b[i]:-1;B1.Build(t,1,1,m);
		for(int i=1;i<=n;++i)t[i]=a[i]<0?-a[i]:-1;A2.Build(t,1,1,n);
		for(int i=1;i<=m;++i)t[i]=b[i]<0?-b[i]:-1;B2.Build(t,1,1,m);
		while(q--){
			data it;int l1,r1,l2,r2;l1=read();r1=read();l2=read();r2=read();
			static int L1,L2,a[10],b[10];ll ans(-1000000000000000000ll);L1=L2=0;
			if(AS[r1]-AS[l1-1])a[++L1]=0;if(BS[r2]-BS[l2-1])b[++L2]=0;
			it=A1.Qry(1,l1,r1,1,n);if(~it.mx)a[++L1]=it.mx;if(~it.mi)a[++L1]=it.mi;
			it=B1.Qry(1,l2,r2,1,m);if(~it.mx)b[++L2]=it.mx;if(~it.mi)b[++L2]=it.mi;
			it=A2.Qry(1,l1,r1,1,n);if(~it.mx)a[++L1]=-it.mx;if(~it.mi)a[++L1]=-it.mi;
			it=B2.Qry(1,l2,r2,1,m);if(~it.mx)b[++L2]=-it.mx;if(~it.mi)b[++L2]=-it.mi;
			for(int i=1;i<=L1;++i){
				ll w(1000000000000000000ll);for(int j=1;j<=L2;++j)w=min(w,1ll*a[i]*b[j]);ans=max(ans,w);
			}
			write(ans);
		}
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	SOLVE::main();
	return 0;
}
