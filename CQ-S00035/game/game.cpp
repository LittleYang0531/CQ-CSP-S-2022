#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m,q,ma1[20][N],ma2[20][N],mi1[20][N],mi2[20][N],lg[N]= {-1},Ma[20][N],Mi[20][N];
int ask1(int l,int r,int ma[20][N]) {
	int len=lg[r-l+1];
	return max(ma[len][l],ma[len][r-(1<<len)+1]);
}
int ask2(int l,int r,int mi[20][N]) {
	int len=lg[r-l+1];
	return min(mi[len][l],mi[len][r-(1<<len)+1]);
}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int x,i=1; i<=n; i++) {
		scanf("%d",&x),ma1[0][i]=mi1[0][i]=x,lg[i]=lg[i>>1]+1;
		if(x>=0) Mi[0][i]=x,Ma[0][i]=-2e9;
		else Mi[0][i]=2e9,Ma[0][i]=x;
	}
	for(int i=1; i<=m; i++) scanf("%d",&ma2[0][i]),mi2[0][i]=ma2[0][i],lg[i]=lg[i>>1]+1;
	for(int j=1; j<=lg[n]; j++) for(int i=1; i<=n-(1<<j)+1; i++) {
			ma1[j][i]=max(ma1[j-1][i],ma1[j-1][i+(1<<j-1)]);
			mi1[j][i]=min(mi1[j-1][i],mi1[j-1][i+(1<<j-1)]);
			Ma[j][i]=max(Ma[j-1][i],Ma[j-1][i+(1<<j-1)]);
			Mi[j][i]=min(Mi[j-1][i],Mi[j-1][i+(1<<j-1)]);
		}
	for(int j=1; j<=lg[m]; j++) for(int i=1; i<=m-(1<<j)+1; i++) {
			ma2[j][i]=max(ma2[j-1][i],ma2[j-1][i+(1<<j-1)]);
			mi2[j][i]=min(mi2[j-1][i],mi2[j-1][i+(1<<j-1)]);
		}
	for(int l1,r1,l2,r2,i=1; i<=q; i++) {
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int x=ask1(l1,r1,ma1),y=ask2(l1,r1,mi1);
		int x1=ask1(l1,r1,Ma),y1=ask2(l1,r1,Mi);
		int X=ask1(l2,r2,ma2),Y=ask2(l2,r2,mi2);
		if(X<0) printf("%lld\n",1ll*y*(y<0?X:Y));
		else if(Y>0) printf("%lld\n",1ll*x*(x>0?Y:X));
		else {
			long long asw=-1e18;
			if(x1>-2e9) asw=max(asw,1ll*X*x1);
			if(y1<2e9) asw=max(asw,1ll*Y*y1);
			printf("%lld\n",asw);
		}
	}
	return 0;
}
