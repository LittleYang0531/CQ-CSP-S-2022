#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
bool ST;
const int N=1e5+10,LG=17;
int n,m,q;
int a[N],b[N],s[N],c[N],z1[N],z2[N];
int get(int x,int l,int r){
	if(x==0)return 0;
	if(x>0){
		int y=1e9;For(i,l,r)y=min(y,b[i]);
		return x*y;
	}
	if(x<0){
		int y=-1e9;For(i,l,r)y=max(y,b[i]);
		return x*y;
	}
	assert(0);
}
struct ST_table{//op==0:max, op==1:min
	int f[LG][N];
	void build(int *a,int n,int op){
		For(i,1,n)f[0][i]=a[i];
		For(j,1,LG-1)For(i,1,n-(1<<j)+1)
			if(op==0)f[j][i]=max(f[j-1][i],f[j-1][i+(1<<j-1)]);
			else f[j][i]=min(f[j-1][i],f[j-1][i+(1<<j-1)]);
	}
	int get(int l,int r,int op){
		int p=__lg(r-l+1);
		if(op==0)return max(f[p][l],f[p][r-(1<<p)+1]);
		else return min(f[p][l],f[p][r-(1<<p)+1]);
	}
}Bmax,Bmin,Amax1,Amin1,Amax2,Amin2;
bool ED;
signed main(){
//	fprintf(stderr,"%.2lf MB\n",abs(&ED-&ST)/1024.0/1024.0);
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),q=read();
	For(i,1,n)a[i]=read(),s[i]=s[i-1]+(a[i]==0),
		z1[i]=z1[i-1]+(a[i]>0),
		z2[i]=z2[i-1]+(a[i]<0);
	For(i,1,m)b[i]=read();
	Bmax.build(b,m,0),Bmin.build(b,m,1);
	//positive only
	For(i,1,n){c[i]=a[i];if(a[i]<=0)c[i]=-1e9;}
	Amax1.build(c,n,0);
	For(i,1,n){c[i]=a[i];if(a[i]<=0)c[i]=1e9;}
	Amin1.build(c,n,1);
	//negative only
	For(i,1,n){c[i]=a[i];if(a[i]>=0)c[i]=-1e9;}
	Amax2.build(c,n,0);
	For(i,1,n){c[i]=a[i];if(a[i]>=0)c[i]=1e9;}
	Amin2.build(c,n,1);
	while(q--){
		int l1=read(),r1=read(),l2=read(),r2=read();
		int ans=-1e18;if(s[r1]-s[l1-1])ans=0;
		int mx=Bmax.get(l2,r2,0),mn=Bmin.get(l2,r2,1);
		if(z1[r1]-z1[l1-1]){
			ans=max(ans,Amax1.get(l1,r1,0)*mn);
			ans=max(ans,Amin1.get(l1,r1,1)*mn);
		}
		if(z2[r1]-z2[l1-1]){
			ans=max(ans,Amax2.get(l1,r1,0)*mx);
			ans=max(ans,Amin2.get(l1,r1,1)*mx);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

