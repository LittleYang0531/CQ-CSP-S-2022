#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
int n,m,q,a[maxn],b[maxn],mia[maxn][20],maa[maxn][20],mib[maxn][20],mab[maxn][20];
int l1,r1,l2,r2,ans;
int az[maxn][20],af[maxn][20];
int read(){
	int s=0;
	char ch=getchar(),last=' ';
	while(ch<'0'||ch>'9')
		last=ch,ch=getchar();
	while(ch>='0'&&ch<='9')
		s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return last=='-'?-s:s;
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++){
		a[i]=read(),mia[i][0]=a[i],maa[i][0]=a[i];
		if(a[i]<=0)
			af[i][0]=a[i],az[i][0]=1e9+10;
		else
			az[i][0]=a[i],af[i][0]=-1e9-10;
	}
	for(int i=1;i<=m;i++)
		b[i]=read(),mib[i][0]=b[i],mab[i][0]=b[i];
	for(int i=1;i<=17;i++)
		for(int j=1;j<=n&&j+(1<<i)-1<=n;j++){
			mia[j][i]=min(mia[j][i-1],mia[j+(1<<(i-1))][i-1]);
			maa[j][i]=max(maa[j][i-1],maa[j+(1<<(i-1))][i-1]);
			az[j][i]=min(az[j][i-1],az[j+(1<<(i-1))][i-1]);
			af[j][i]=max(af[j][i-1],af[j+(1<<(i-1))][i-1]);
		}
	for(int i=1;i<=17;i++)
		for(int j=1;j<=m&&j+(1<<i)-1<=m;j++){
			mib[j][i]=min(mib[j][i-1],mib[j+(1<<(i-1))][i-1]);
			mab[j][i]=max(mab[j][i-1],mab[j+(1<<(i-1))][i-1]);
		}
	while(q--){
		l1=read(),r1=read(),l2=read(),r2=read();
		int mid=log2(r1-l1+1);
		int xa=max(maa[l1][mid],maa[r1-(1<<mid)+1][mid]);
		int xi=min(mia[l1][mid],mia[r1-(1<<mid)+1][mid]);
		int xz=min(az[l1][mid],az[r1-(1<<mid)+1][mid]);
		int xf=max(af[l1][mid],af[r1-(1<<mid)+1][mid]);
		mid=log2(r2-l2+1);
		int ya=max(mab[l2][mid],mab[r2-(1<<mid)+1][mid]);
		int yi=min(mib[l2][mid],mib[r2-(1<<mid)+1][mid]);
		if(l1==r1){
			if(a[l1]<=0)
				printf("%lld\n",a[l1]*yi);
			else
				printf("%lld\n",a[l1]*ya);
			continue;
		}
		if(l2==r2){
			if(b[l2]<=0)
				printf("%lld\n",b[l2]*xi);
			else
				printf("%lld\n",b[l2]*xa);
			continue;
		}
		if(xi>0){
			if(yi>0)
				ans=xa;
			else
				ans=xi;	
		}
		if(xa<=0){
			if(ya<=0)
				ans=xi;
			else
				ans=xa;	
		}
		if(xi<=0&&xa>0){
			if(yi>0)
				ans=xa;
			if(ya<=0)
				ans=xi;
			if(yi<=0&&ya>0){
				if(xz*yi>xf*ya)
					ans=xz;
				else
					ans=xf;
			}
		}
		if(ans<=0)
			ans*=ya;
		else
			ans*=yi;
		printf("%lld\n",ans);
	}
    return 0;
}
