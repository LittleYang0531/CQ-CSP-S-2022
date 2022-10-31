//Linkwish's code
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


const int N=100005;
ll amn[2][N][18],amx[2][N][18];
ll bmn[N][18],bmx[N][18];
int lg[N];
int n,m,q;
ll a[N],b[N];


inline void init(){
	for(int i=1,now=1,cnt=0;i<=max(n,m);i++){
		if(i==(now<<1))now<<=1,cnt++;
		lg[i]=cnt;
	}
	for(int i=1;i<=n;i++){
		if(a[i]>=0){
			amx[0][i][0]=amn[0][i][0]=a[i];
			amx[1][i][0]=-1e18,amn[1][i][0]=1e18;
		}
		else{
			amx[1][i][0]=amn[1][i][0]=a[i];
			amx[0][i][0]=-1e18,amn[0][i][0]=1e18;
		}
	}
	for(int i=1;i<=m;i++)bmn[i][0]=bmx[i][0]=b[i];
	for(int j=1;j<=17;j++){
		for(int i=1;i+(1<<(j-1))<=n;i++){
			for(int k=0;k<=1;k++){
				amn[k][i][j]=min(amn[k][i][j-1],amn[k][i+(1<<(j-1))][j-1]);
				amx[k][i][j]=max(amx[k][i][j-1],amx[k][i+(1<<(j-1))][j-1]);
			}
		}
		for(int i=1;i+(1<<(j-1))<=m;i++){
			bmn[i][j]=min(bmn[i][j-1],bmn[i+(1<<(j-1))][j-1]);
			bmx[i][j]=max(bmx[i][j-1],bmx[i+(1<<(j-1))][j-1]);
		}
	}
}
inline pair<ll,ll> querya(int l,int r,int pos){
	int x=lg[r-l+1];
	return {min(amn[pos][l][x],amn[pos][r-(1<<x)+1][x]),max(amx[pos][l][x],amx[pos][r-(1<<x)+1][x])};
}
inline pair<ll,ll> queryb(int l,int r){
	int x=lg[r-l+1];
	return {min(bmn[l][x],bmn[r-(1<<x)+1][x]),max(bmx[l][x],bmx[r-(1<<x)+1][x])};
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)scanf("%lld",&b[i]);
	init();
	int l,r,_l,_r;
	pair<ll,ll> resb,resaz,resaf;
	ll ans;
	while(q--){
		scanf("%d%d%d%d",&l,&r,&_l,&_r);
		resb=queryb(_l,_r),resaz=querya(l,r,0),resaf=querya(l,r,1),ans=-1e18;
		if(resaz.first!=1e18)ans=max(ans,resaz.first*resb.first);
		if(resaz.second!=-1e18)ans=max(ans,resaz.second*resb.first);
		if(resaf.first!=1e18)ans=max(ans,resaf.first*resb.second);
		if(resaf.second!=-1e18)ans=max(ans,resaf.second*resb.second);
		printf("%lld\n",ans);
	}
	return 0;
}

