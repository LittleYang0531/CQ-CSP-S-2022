#include<bits/stdc++.h>
#define maxn LONG_LONG_MAX
using namespace std;
int n,m,q;
long long a[10005],b[10005];
int l1,r1,l2,r2,ans;
long long azzx,azzd,afzx,afzd,az,af;
long long bzzx,bzzd,bfzx,bfzd,bz,bf; 
long long lmax(long long x,long long y){return x>y?x:y;}
long long lmin(long long x,long long y){return x<y?x:y;}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)scanf("%lld",&b[i]);
	while(q--){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		azzx=maxn;azzd=0;afzx=0;afzd=-maxn;
		bzzx=maxn;bzzd=0;bfzx=0;bfzd=-maxn;
		az=af=bz=bf=ans=0;
		for(int i=l1;i<=r1;i++)
			if(a[i]>0)az=1,azzx=lmin(azzx,a[i]),azzd=lmax(azzd,a[i]);
			else af=1,afzx=lmin(afzx,a[i]),afzd=lmax(afzd,a[i]);
		for(int i=l2;i<=r2;i++)
			if(b[i]>0)bz=1,bzzx=lmin(bzzx,b[i]),bzzd=lmax(bzzd,b[i]);
			else bf=1,bfzx=lmin(bfzx,b[i]),bfzd=lmax(bfzd,b[i]);
		if(az&&!af&&bz&&!bf)ans=azzd*bzzx;
		else if(!az&&af&&!bz&&bf)ans=afzx*bfzd;
		else if(az&&!af&&!bz&&bf)ans=azzx*bfzd;
		else if(!az&&af&&bz&&!bf)ans=afzd*bzzd;
		else if(az&&af&&bz&&bf)ans=lmax(azzx*bfzx,afzd*bzzd);
		else if(!az&&af&&bz&&bf)ans=afzx*bzzd;
		else if(az&&!af&&bz&&bf)ans=azzx*bfzx;
		else if(az&&af&&!bz&&bf)ans=lmax(azzx*bfzd,afzx*bfzd);
		else if(az&&af&&bz&&!bf)ans=lmax(azzx*bfzd,afzx*bfzd);
		printf("%d\n",ans);
	}
	return 0;
}
