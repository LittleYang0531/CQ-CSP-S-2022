#include<iostream>
#include<climits>

using namespace std;
using ll=long long;

const int N=1e5+5;

int n,m,q;
ll a[N],b[N],B1[N][20],B2[N][20],Log[N];

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	
	cin>>n>>m>>q;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=m;++i)cin>>b[i],B1[i][0]=B2[i][0]=b[i];
	for(int i=2;i<=m;++i)Log[i]=Log[i>>1]+1;
	for(int j=1;j<=Log[m];++j){
		for(int i=1;i+(1ll<<j)-1<=m;++i){
			B1[i][j]=min(B1[i][j-1],B1[i+(1ll<<j-1)][j-1]);
			B2[i][j]=max(B2[i][j-1],B2[i+(1ll<<j-1)][j-1]);
		}
	}
//	cout<<B2[1][2]<<" :KJG:LSKJ:LKJ:LKFS:LJLSFJGSDSDF\n";
//	if(n<=1000&&m<=1000){
		while(q--){
			int l1,r1,l2,r2;
			cin>>l1>>r1>>l2>>r2;
			ll len=Log[r2-l2+1];
			ll k1=min(B1[l2][len],B1[r2-(1ll<<len)+1][len]);
			ll k2=max(B2[l2][len],B2[r2-(1ll<<len)+1][len]);
			ll Max=LONG_LONG_MIN,h;
			for(int i=l1;i<=r1;++i){
				if(a[i]>=0){
					if(a[i]*k1>Max){
						Max=a[i]*k1;
						h=i;
					}
				}
				else {
					if(a[i]*k2>Max){
						Max=a[i]*k2;
						h=i;
					}
				}
			}
//			cout<<k2<<":FKJ FD:LKS:LKDFJSFS\n";
			if(a[h]>=0){
				cout<<a[h]*k1<<'\n';
			}
			else cout<<a[h]*k2<<'\n';
		}
//	}
	
	return 0;
}
