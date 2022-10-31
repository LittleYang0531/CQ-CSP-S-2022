#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;

namespace Solve{
	const int N=500010;
	int n,m,q;
	struct Graph{
		int head[N],ver[N],ne[N],idx=1;
		void add(int x,int y){
			ver[idx]=y,ne[idx]=head[x],head[x]=idx++;
		}
	}in,out;
	map<pair<int,int>,int>mp;
	namespace SolveNM{
		bool st[N];
		int cnt,all,deg[N];
		void solve(){
			all=m;
			for(int i=1;i<=m;i++)st[i]=1;
			for(int i=1;i<=n;i++){
				for(int j=out.head[i];j;j=out.ne[j])deg[i]++;
				if(deg[i]==0)cnt++;
			}
			while(q--){
				int t;cin>>t;
				if(t==1){
					int u,v;cin>>u>>v;
					int x=mp[{u,v}];
					if(st[x]){
						st[x]=0;
						deg[u]--,all--;
						if(deg[u]==0)cnt++;
					}
				}
				else if(t==2){
					int x;cin>>x;
					for(int i=in.head[x];i;i=in.ne[i]){
						if(st[i]){
							st[i]=0;
							deg[in.ver[i]]--,all--;
							if(deg[in.ver[i]]==0)cnt++;
						}
					}
				}
				else if(t==3){
					int u,v;cin>>u>>v;
					int x=mp[{u,v}];
					if(!st[x]){
						st[x]=1;
						if(deg[u]==0)cnt--;
						deg[u]++,all++;
					}
				}
				else{
					int x;cin>>x;
					for(int i=in.head[x];i;i=in.ne[i]){
						if(!st[i]){
							st[i]=1;
							if(deg[in.ver[i]]==0)cnt--;
							deg[in.ver[i]]++,all++;
						}
					}
				}
				cout<<((all==n&&cnt==0)?"YES\n":"NO\n");
//				cout<<"Now "<<all<<' '<<cnt<<'\n';
			}
		}
	}
	namespace Solve1{
		set<int>pt[N];
		int cnt,all,deg[N];
		void solve(){
			all=m;
			for(int i=1;i<=n;i++)
				for(int j=in.head[i];j;j=in.ne[j])
					pt[i].insert(in.ver[j]),deg[in.ver[j]]++;
			for(int i=1;i<=n;i++)cnt+=(deg[i]==0);
			while(q--){
				int t;cin>>t;
				if(t==1){
					int u,v;cin>>u>>v;
					pt[v].erase(u);
					deg[u]--,all--;
					if(deg[u]==0)cnt++;
				}
				else if(t==2){
					int x;cin>>x;
					while(pt[x].size()){
						int p=*pt[x].begin();
						pt[x].erase(pt[x].begin());
						deg[p]--,all--;
						if(deg[p]==0)cnt++;
					}
				}
				else if(t==3){
					int u,v;cin>>u>>v;
					pt[v].insert(u);
					if(deg[u]==0)cnt--;
					deg[u]++,all++;
				}
				else{
					int x;cin>>x;
					for(int i=in.head[x];i;i=in.ne[i])
						if(pt[x].find(in.ver[i])==pt[x].end()){
							pt[x].insert(in.ver[i]);
							if(deg[in.ver[i]]==0)cnt--;
							deg[in.ver[i]]++,all++;
						}
				}
				cout<<((all==n&&cnt==0)?"YES\n":"NO\n");
//				cout<<"Now "<<all<<' '<<cnt<<'\n';
			}
		}
	}
	void main(){
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			int x,y;cin>>x>>y;
			out.add(x,y),in.add(y,x);
			mp[{x,y}]=i;
		}
		cin>>q;
		if((ll)q*m<=1e8){
			SolveNM::solve();
			return;
		}
		else{
			Solve1::solve();
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	Solve::main();
}

