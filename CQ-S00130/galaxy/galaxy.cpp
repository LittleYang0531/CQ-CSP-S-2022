#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<map> 
#include<iostream>
#include<algorithm>
#include<bitset>
#include<unordered_map>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define LL long long
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int mod=998244353;
inline int add(int x,int y){
	return x+y>=mod?x+y-mod:x+y;
}
inline int dec(int x,int y){
	return x-y<0?x-y+mod:x-y; 
}
inline int qkpow(int a,int b){
	int res=1,base=a;
	while(b){
		if(b&1)res=1ll*res*base%mod;
		base=1ll*base*base%mod;
		b>>=1;
	}
	return res;
}
#define pp pair<int,int>
int deg[500005],n,m,q,cnt;
set<int>S[500005],S2[500005];
vector<int>G[500005];
struct node{
	int op,u,v;
}Q[500005];
void baoli(){
	for(int i=1;i<=n;i++)if(deg[i]==1)cnt++;
	int fk=0;
    for(int i=1;i<=q;i++){
		int op=Q[i].op;
		if(op==1){
			int u,v;
			u=Q[i].u,v=Q[i].v;
			if(S[u].find(v)!=S[u].end()){
				S2[v].erase(u);
				S[u].erase(v);
				if(deg[u]==1)cnt--;
				deg[u]--;
				if(deg[u]==1)cnt++; 
			}
		}else if(op==2){
			int u;
			u=Q[i].u;
			for(auto v:S2[u]){
				S[v].erase(u);
				if(deg[v]==1)cnt--;
				deg[v]--;
				if(deg[v]==1)cnt++; 
			}
			S2[u].clear();
		}else if(op==3){
			int u,v;
			u=Q[i].u,v=Q[i].v;
			if(S[u].find(v)==S[u].end()){
				S2[v].insert(u);
				S[u].insert(v);
				if(deg[u]==1)cnt--;
				deg[u]++;
				if(deg[u]==1)cnt++; 
			}
		}else if(op==4){
			fk++;
			int u;
			u=Q[i].u;
			if(S2[u].size()!=G[u].size()){
				for(auto v:G[u]){
					if(S2[u].find(v)==S2[u].end()){
						S2[u].insert(v);
						S[v].insert(u);
						if(deg[v]==1)cnt--;
						deg[v]++;
						if(deg[v]==1)cnt++; 
					}
				}	
			}
		} 
		puts(cnt==n?"YES":"NO");
	}
}
signed main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int u,v;
		u=read(),v=read();
		deg[u]++;
		G[v].push_back(u);
		S[u].insert(v);
		S2[v].insert(u);
	}
	bool pd=1;
	q=read();
	for(int i=1;i<=q;i++){
		Q[i].op=read();
		pd&=(Q[i].op!=4);
		if(Q[i].op==1||Q[i].op==3){
			Q[i].u=read();
			Q[i].v=read();
		}else Q[i].u=read();
	}
	if(1){
		baoli();
		exit(0);
	}
	return 0;
}
/*
*/
