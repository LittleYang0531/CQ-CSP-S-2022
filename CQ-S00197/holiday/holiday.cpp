#include<bits/stdc++.h>
#define int long long
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
inline int read(){
	char ch=' ';int x=0,f=1;
	while((ch<'0'||ch>'9')&&ch!='-'){ch=getchar();}
	if(ch=='-'){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}
	return x*f; 
}
const int N=2505,M=10005,inf=4e18;
bitset<N>cango[N];
int n,m,k;
int s[N];
vector<int>e[N];
int dis[N];
void sec(int st){
	queue<int>q;
	q.push(st);
	cango[st][st]=1;
	dis[st]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(dis[x]==k+1){
			return;
		}
		for(int to:e[x]){
			if(cango[st][to]){
				continue;
			}
			cango[st][to]=1;
			dis[to]=dis[x]+1;
			q.push(to);
		}
	}
}
int f[N][N];
int ans=0;
struct tp{
	int a,b,c;
	bool operator<(const tp &B)const{
		if(a!=B.a){
			return a>B.a;
		}
		if(b!=B.b){
			return b<B.b;
		}
		return c<B.c;
	}
};
pair<int,int> mx[N][4];
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(),m=read(),k=read();
	rep(i,2,n){
		s[i]=read();
	}
	rep(i,1,m){
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
//	puts("?");
	rep(i,1,n){
		sec(i);
	}
	rep(i,2,n){
		rep(j,2,n){
			if(i==j||!cango[1][i]||!cango[i][j]){
				f[i][j]=-inf;
			}
			else{
				f[i][j]=s[i]+s[j]; 
			}
		}
	}
	rep(i,2,n){
		mx[i][1].second=mx[i][2].second=mx[i][3].second=-inf;
	}
	rep(j,2,n){
		rep(i,2,n){
			if(f[i][j]>mx[j][1].first){
				mx[j][3]=mx[j][2];
				mx[j][2]=mx[j][1];
				mx[j][1]=make_pair(f[i][j],i);
			}
			else if(f[i][j]>mx[j][2].first){
				mx[j][3]=mx[j][2];
				mx[j][2]=make_pair(f[i][j],i);
			}
			else if(f[i][j]>mx[j][3].first){
				mx[j][3]=make_pair(f[i][j],i);
			}
		}
	}
	rep(j,2,n){
		multiset<tp>red;
		vector<int>v[N];
		rep(k,2,n){
			if(j!=k&&cango[j][k]){
				rep(i,1,3){
					if(mx[k][i].second!=j){
						red.insert((tp){mx[k][i].first,mx[k][i].second,k});
					}
				}
			}
		}
		rep(i,2,n){
			if(i==j||f[i][j]==-inf){
				continue;
			}
			for(auto it:red){
				if(it.b!=i&&it.c!=i){
					ans=max(ans,it.a+f[i][j]);
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
这个n^2log(n)巨常数代码要是能过，我就在机房跳只因你太美 
*/
