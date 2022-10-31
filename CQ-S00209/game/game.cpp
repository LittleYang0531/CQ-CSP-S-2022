#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=1e5+5;
int n,m,Q,Log[N];
ll a[N],b[N];
ll st1[N][20],st2[N][20],st3[N][20],st4[N][20];
ll st5[N][20],st6[N][20];
vector<ll>ask(int l,int r){
	int k=Log[r-l+1];vector<ll>tmp({max(st1[l][k],st1[r-(1<<k)+1][k]),min(st3[l][k],st3[r-(1<<k)+1][k]),min(st2[l][k],st2[r-(1<<k)+1][k]),max(st4[l][k],st4[r-(1<<k)+1][k])});
	return tmp;
}
vector<ll>ask2(int l,int r){
	int k=Log[r-l+1];vector<ll>tmp({max(st5[l][k],st5[r-(1<<k)+1][k]),min(st6[l][k],st6[r-(1<<k)+1][k])});
	return tmp;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>Q;for(int i=2;i<=max(n,m);i++)Log[i]=Log[i/2]+1;
	for(int i=1;i<=n;i++)cin>>a[i];for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<=m;i++)st5[i][0]=st6[i][0]=b[i];
	for(int j=1;j<20;j++){
		for(int i=1;i<=m-(1<<j)+1;i++){
			st5[i][j]=max(st5[i][j-1],st5[i+(1<<j-1)][j-1]);
			st6[i][j]=min(st6[i][j-1],st6[i+(1<<j-1)][j-1]);
		}
	}
	for(int i=1;i<=n;i++){
		st1[i][0]=st2[i][0]=a[i];
		st3[i][0]=(a[i]>=0)?a[i]:inf;
		st4[i][0]=(a[i]<0)?a[i]:-inf;
	}
	for(int j=1;j<20;j++){
		for(int i=1;i<=n-(1<<j)+1;i++){
			st1[i][j]=max(st1[i][j-1],st1[i+(1<<j-1)][j-1]);
			st2[i][j]=min(st2[i][j-1],st2[i+(1<<j-1)][j-1]);
			st3[i][j]=min(st3[i][j-1],st3[i+(1<<j-1)][j-1]);
			st4[i][j]=max(st4[i][j-1],st4[i+(1<<j-1)][j-1]);
		}
	}
	for(int i=1;i<=Q;i++){
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		vector<ll>x=ask(l1,r1),y=ask2(l2,r2);
		ll res=-0x3f3f3f3f3f3f3f3f;
		for(int j=0;j<4;j++){
			if(x[j]!=inf&&x[j]!=-inf){
				if(x[j]>=0)res=max(res,(ll)x[j]*y[1]);
				if(x[j]<0)res=max(res,(ll)x[j]*y[0]);
			}
		}
        cout<<res<<"\n";
	}
}
