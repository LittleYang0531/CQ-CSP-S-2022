//Author: Zealous_YH in CSP-S2022
//Su Chanzi & Xiaobao
#include <bits/stdc++.h>
#define ET return 0
#define fr1(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define fr2(i,a,b) for(int (i)=(a);(i)>=(b);(i)++)
#define fv(i,p) for(int (i)=0;(i)<(p).size();(i)++)
#define ll long long
#define ull unsigned ll
#define mp make_pair
#define pb push_back
#define ptc putchar
#define il inline
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define int ll
#define se second
using namespace std;
const int N=2010;
int n,q,k;
int v[N];
vector <int> p[N];
int f[N][15];
int dp[N];
int s,t;
void dfs(int x,int fa){
	fv(i,p[x]){
		if(p[x][i]!=fa){
			f[p[x][i]][0]=x;
			dfs(p[x][i],x);
		}
	}
}
signed main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q>>k;
	fr1(i,1,n){
		cin>>v[i];
	}
	fr1(i,1,n-1){
		int x,y;
		cin>>x>>y;
		p[x].pb(y);
		p[y].pb(x);
	}
	while(q--){
		cin>>s>>t;
		fr1(i,1,n){
			dp[i]=LONG_LONG_MAX;
		}
		memset(f,0,sizeof(f));
		f[t][0]=t;
//		f[t][1]=t;
		dfs(t,0);
		dp[s]=0;
		fr1(i,1,n){
			f[i][1]=f[f[i][0]][0];
		}
		while(s!=t){
			if(k>=1){
				dp[f[s][0]]=min(dp[f[s][0]],dp[s]+v[s]);
			}
			if(k>=2){
				dp[f[s][1]]=min(dp[f[s][1]],dp[s]+v[s]);
			}
			if(k>=3){
				dp[f[f[s][1]][0]]=min(dp[f[f[s][1]][0]],dp[s]+v[s]);
			}
//			cout<<s<<","<<dp[s]<<","<<f[s][0]<<","<<f[s][1]<<"?"<<dp[t]<<endl;
			s=f[s][0];	
		}
		cout<<dp[t]+v[t]<<endl;
	}
	ET;
}
//RP++
//Don't FST.

