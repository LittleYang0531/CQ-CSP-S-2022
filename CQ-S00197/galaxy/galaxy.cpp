#include<bits/stdc++.h>
//#define int long long
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
const int N=5e5+5;
int n,m,q;
vector<int>fe[N];
set<int>e[N],s[N],no; 
void baoli(){
	rep(i,1,n){
		if((int)s[i].size()!=1){
			no.insert(i);
		}
	}
	rep(i,1,q){
		int t=read();
		if(t==1){
			int u=read(),v=read();
			s[u].erase(v);
			e[v].erase(u);
			if((int)s[u].size()!=1){
				no.insert(u);
			}
			else{
				no.erase(u);
			}
		}
		if(t==2){
			int u=read();
			for(int v:e[u]){
				s[v].erase(u); 
				if((int)s[v].size()!=1){
					no.insert(v);
				}
				else{
					no.erase(v);
				}
			}
			e[u].clear();
		}
		if(t==3){
			int u=read(),v=read();
			s[u].insert(v);
			e[v].insert(u);
			if((int)s[u].size()!=1){
				no.insert(u);
			}
			else{
				no.erase(u);
			}
		}
		if(t==4){
			int u=read();
			for(int v:fe[u]){
				s[v].insert(u);
				e[u].insert(v);
				if(s[v].size()!=1){
					no.insert(v);
				}
				else{
					no.erase(v);
				}
			}
		}
		puts(no.empty()?"YES":"NO");
	}
}
signed main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout); 
	n=read(),m=read();
	rep(i,1,m){
		int u=read(),v=read();
		s[u].insert(v);
		fe[v].push_back(u);
		e[v].insert(u);
	}
	q=read();
	baoli();
	return 0;
}
