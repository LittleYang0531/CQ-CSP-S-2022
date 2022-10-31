#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100000,V=2e9;
int n,m,q,a[N+5],b[N+5],mx[2][20][N+5],mn[2][20][N+5],mxg[20][N+5],mng[20][N+5],lg2[N+5];
//0正 1负
int Qmx(int o,int l,int r){
	int k=lg2[r-l+1];
	return max(mx[o][k][l],mx[o][k][r-(1<<k)+1]);
}
int Qmn(int o,int l,int r){
	int k=lg2[r-l+1];
	return min(mn[o][k][l],mn[o][k][r-(1<<k)+1]);
}
int Qmxg(int l,int r){
	int k=lg2[r-l+1];
	return max(mxg[k][l],mxg[k][r-(1<<k)+1]);
}
int Qmng(int l,int r){
	int k=lg2[r-l+1];
	return min(mng[k][l],mng[k][r-(1<<k)+1]);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q),lg2[0]=-1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),lg2[i]=lg2[i>>1]+1;
		if(a[i]>=0){
			mx[0][0][i]=a[i];
			mn[0][0][i]=a[i];
			mx[1][0][i]=-V;
			mn[1][0][i]=V;
		}
		else {
			mx[0][0][i]=-V;
			mn[0][0][i]=V;
			mx[1][0][i]=a[i];
			mn[1][0][i]=a[i];
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		mxg[0][i]=mng[0][i]=b[i];
	}
	for(int o=0;o<2;o++){
		for(int i=1;i<=17;i++){
			for(int j=1;j+(1<<i)-1<=n;j++){
				mn[o][i][j]=min(mn[o][i-1][j],mn[o][i-1][j+(1<<i-1)]);
				mx[o][i][j]=max(mx[o][i-1][j],mx[o][i-1][j+(1<<i-1)]);
			}
		}
	}
	for(int i=1;i<=17;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			mng[i][j]=min(mng[i-1][j],mng[i-1][j+(1<<i-1)]);
			mxg[i][j]=max(mxg[i-1][j],mxg[i-1][j+(1<<i-1)]);
		}
	}
	for(int i=1,l1,r1,l2,r2;i<=q;i++){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		ll ans=-1e18;
		//如果先手>=0
		int w=Qmng(l2,r2);
		if(w>=0){
			int t=Qmx(0,l1,r1);
			if(t!=-V)ans=max(ans,1ll*w*t);
		}
		else {
			int t=Qmn(0,l1,r1);
			if(t!=V)ans=max(ans,1ll*w*t);
		}
		//<0
		w=Qmxg(l2,r2);
		if(w<0){
			int t=Qmn(1,l1,r1);
			if(t!=V)ans=max(ans,1ll*w*t);
		}
		else {
			int t=Qmx(1,l1,r1);
			if(t!=-V)ans=max(ans,1ll*w*t);
		}
		cout<<ans<<'\n';
	} 
}
