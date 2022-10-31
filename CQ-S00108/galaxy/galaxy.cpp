#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
bool ST;
const int N=5e5+10;
int n,m,q;
int head[N],to[N],nxt[N],val[N],cnt;
void add(int u,int v){
	to[++cnt]=v,val[cnt]=1,nxt[cnt]=head[u],head[u]=cnt;
}
int indeg[N],outdeg[N],tot;
namespace brute1{

signed main(){
	while(q--){
		int t=read();
		if(t==1){
			int fr=read(),v=read();
			go(v){
				int u=to[i];if(u==fr){
//					assert(val[i]==1);
					val[i]=0;
					tot-=outdeg[u]==1;
					outdeg[u]--;
					tot+=outdeg[u]==1;
					break;
				}
			}
		}
		if(t==2){
			int v=read();go(v){
				int u=to[i];if(val[i]==1){
					val[i]=0;
					tot-=outdeg[u]==1;
					outdeg[u]--;
					tot+=outdeg[u]==1;
				}
			}
		}
		if(t==3){
			int fr=read(),v=read();
			go(v){
				int u=to[i];if(u==fr){
//					assert(val[i]==0);
					val[i]=1;
					tot-=outdeg[u]==1;
					outdeg[u]++;
					tot+=outdeg[u]==1;
					break;
				}
			}
		}
		if(t==4){
			int v=read();go(v){
				int u=to[i];if(val[i]==0){
					val[i]=1;
					tot-=outdeg[u]==1;
					outdeg[u]++;
					tot+=outdeg[u]==1;
				}
			}
		}
		puts(tot==n?"YES":"NO");
	}return 0;
}
	
}

namespace brute2{

set<int> s1[N],s2[N];
signed main(){
	For(v,1,n){
		go(v){
			int u=to[i];
			s1[v].insert(u);
		}
	}
	while(q--){
		int t=read();
		if(t==1){
			int u=read(),v=read();
			tot-=outdeg[u]==1;
			outdeg[u]--;
			tot+=outdeg[u]==1;
			s1[v].erase(u),s2[v].insert(u);
		}
		if(t==3){
			int u=read(),v=read();
			tot-=outdeg[u]==1;
			outdeg[u]++;
			tot+=outdeg[u]==1;
			s2[v].erase(u),s1[v].insert(u);
		}
		if(t==2){
			int v=read();
			for(auto u:s1[v]){
				s2[v].insert(u);
				tot-=outdeg[u]==1;
				outdeg[u]--;
				tot+=outdeg[u]==1;
			}s1[v].clear();
		}
		if(t==4){
			int v=read();
			for(auto u:s2[v]){
				s1[v].insert(u);
				tot-=outdeg[u]==1;
				outdeg[u]++;
				tot+=outdeg[u]==1;
			}s2[v].clear();
		}
		puts(tot==n?"YES":"NO");
	}
	return 0;
}

}
bool ED;
signed main(){
//	fprintf(stderr,"%.2lf MB\n",abs(&ED-&ST)/1024.0/1024.0);
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	For(i,1,m){
		int u=read(),v=read();
		add(v,u),outdeg[u]++;
	}
	For(i,1,n)tot+=outdeg[i]==1;
	q=read();
	if(n<=1000&&m<=10000&&q<=1000)return brute1::main();
	else return brute2::main();
	
	return 0;
}
