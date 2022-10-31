#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxm=1e3+5,maxn=1e6+5;

int n,m,q;
ll a[maxn],b[maxn];
bool fl=0;
ll mp[maxm][maxm];
ll k[maxn][5];

ll Min(ll a,ll b){
	return a<b?a:b;
}

ll Max(ll a,ll b){
	return a>b?a:b;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int j=1;j<=m;j++){
		scanf("%lld",&b[j]);
	}
	if(n<=200&&m<=200&&q<=200){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				mp[i][j]=a[i]*b[j];
			}
		}
		for(int v=1;v<=q;v++){
			ll l1,l2,r1,r2;
			scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
			ll sma=-0x3f3f3f3f3f3f3f3f;
			for(int i=l1;i<=r1;i++){
				ll smi=0x3f3f3f3f3f3f3f3f;
				for(int j=l2;j<=r2;j++){
					smi=Min(smi,mp[i][j]);
				}
				sma=Max(sma,smi);
			}
			printf("%lld\n",sma);
		}
	}
	else if(n<=1000&&m<=1000&&q<=1000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				mp[i][j]=a[i]*b[j];
			}
		}
		for(int i=1;i<=q;i++){
			scanf("%lld%lld%lld%lld",&k[i][1],&k[i][2],&k[i][3],&k[i][4]);
			if(k[i][1]!=k[i][2]&&k[i][3]!=k[i][4]){
				fl=1;
			}
		}
		if(fl==0){
			for(int i=1;i<=q;i++){
				if(k[i][1]==k[i][2]){
					ll smi=0x3f3f3f3f3f3f3f3f;
					for(int j=k[i][3];j<=k[i][4];j++){
						smi=Min(mp[k[i][1]][j],smi);
					}
					printf("%lld\n",smi);
				}
				else{
					ll sma=-0x3f3f3f3f3f3f3f3f;
					for(int j=k[i][1];j<=k[i][2];j++){
						sma=Max(mp[j][k[i][3]],sma);
					}
					printf("%lld\n",sma);
				}
			}
		}
		else{
			for(int v=1;v<=q;v++){
				ll sma=-0x3f3f3f3f3f3f3f3f;
				for(int i=k[v][1];i<=k[v][2];i++){
					ll smi=0x3f3f3f3f3f3f3f3f;
					for(int j=k[v][3];j<=k[v][4];j++){
						ll p=a[i]*b[j];
						smi=Min(smi,p);
					}
					sma=Max(sma,smi);
				}
				printf("%lld\n",sma);
			}
		}
	}
	else{
		for(int v=1;v<=q;v++){
			ll l1,l2,r1,r2;
			scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
			ll sma=-0x3f3f3f3f3f3f3f3f;
			for(int i=l1;i<=r1;i++){
				ll smi=0x3f3f3f3f3f3f3f3f;
				for(int j=l2;j<=r2;j++){
					smi=Min(smi,a[i]*b[j]);
				}
				sma=Max(sma,smi);
			}
			printf("%lld\n",sma);
		}
	}
	return 0;
}
