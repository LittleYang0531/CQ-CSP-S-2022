#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
namespace shik{
	const ll inf=1e18;
	const int N=1e5+5,K=23;
	int lo[N],af[N],az[N],a[N],b[N],s[N];
	inline char gc()
	{
		static char buf[1<<16],*S,*T;
		if(S==T)
		{
			T=(S=buf)+fread(buf,1,1<<16,stdin);
			if(S==T)return EOF;
		}
		return *(S++);
	}
	#define getchar gc
	inline ll read()
	{
		char h=getchar();
		ll y=0,q=1;
		while(h<'0'||h>'9'){if(h=='-')q=-1;h=getchar();}
		while(h>='0'&&h<='9')y=y*10+h-'0',h=getchar();
		return y*q;
	}
	struct ST{
		int f[N][K],a[N];
		int ty;//0:最大值，且0最小   1：最小值，且0最大     2：最大值   3：最小值
		int cmp(int x,int y)//0:x比较优 
		{
			if(ty<=1)
			{
				if(y==0)return 0;
				if(x==0)return 1;
			}
			if(ty==0||ty==2)return x<y;
			return x>y;
		}
		int getmax(int x,int y){return cmp(a[x],a[y])?y:x;}
		inline void init(int n,int buf[])
		{
			for(int i=1;i<=n;i++)a[i]=buf[i],f[i][0]=i;
			for(int j=1;j<=lo[n];j++)
			for(int i=1;i+(1<<j)-1<=n;i++)f[i][j]=getmax(f[i][j-1],f[i+(1<<(j-1))][j-1]);//,cout<<i<<" "<<j<<" "<<f[i][j]<<"%%\n";
		}
		inline int query(int l,int r)
		{
			int k=lo[r-l+1];
//			cout<<l<<' '<<r<<" "<<k<<"&\n";
			return getmax(f[l][k],f[r-(1<<k)+1][k]);
		}
	}s1,s2,s3,s4,s5,s6;
	inline ll calc(int x,int l,int r)
	{
//		cout<<x<<"^^\n";
		if(a[x]==0)return -inf;
		x=a[x];
//		cout<<x<<" "<<l<<" "<<r<<"::";
		if(x<0)return //cout<<b[s5.query(l,r)]<<' '<<1ll*x*b[s5.query(l,r)]<<"&&\n",
		1ll*x*b[s5.query(l,r)];
		return //cout<<b[s6.query(l,r)]<<" "<<1ll*x*b[s6.query(l,r)]<<"&&\n",
		1ll*x*b[s6.query(l,r)];
	}
	int main()
	{
		freopen("game.in","r",stdin);
		freopen("game.out","w",stdout);
		int n=read(),m=read(),q=read();lo[1]=0;
		for(int i=2;i<=n;i++)lo[i]=(lo[i>>1]+1);
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(a[i]<0)af[i]=a[i];
			else if(a[i]>0)az[i]=a[i];
			s[i]=(s[i-1]+(a[i]==0));
		}
		for(int i=1;i<=m;i++)b[i]=read();
		s1.ty=0;s2.ty=1;s3.ty=0;s4.ty=1;s5.ty=2;s6.ty=3;
		s1.init(n,af);s2.init(n,af);s3.init(n,az);s4.init(n,az);s5.init(n,b);s6.init(n,b);
		while(q--)
		{
			int x=read(),y=read(),l=read(),r=read();
//			cout<<x<<" "<<y<<" "<<l<<" "<<r<<"%%\n";
			ll ans=-inf;
			if(s[y]-s[x-1])ans=0;
			ans=max(ans,max(max(calc(s1.query(x,y),l,r),calc(s2.query(x,y),l,r)),max(calc(s3.query(x,y),l,r),calc(s4.query(x,y),l,r))));
			cout<<ans<<"\n";
		}
		return 0;
	}
}
int main(){return shik::main();}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2

6 4 1
3 -1 -2 1 2 0
1 2 -1 -3
1 5 1 4
*/
