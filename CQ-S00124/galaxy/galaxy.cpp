#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstring>

using namespace std;

const int N=5e5+5;

#define Pii pair<int,int>
#define F first
#define S second

struct Node{
	int u,v;
	Node(){}
	Node(int a,int b){
		u=a,v=b;
	}
	bool operator == (const Node &x) const {
		return u==x.u&&v==x.v;
	}
};

struct Hash{
	size_t operator () (Node a) const {
		return a.u*1000000+a.v;
	}
};

int q,n,m,tot,ps[N],V[N],tmp[N];
vector<Pii> E[N];
unordered_map<Node,int,Hash> bj;

void Dfs(int u,int&pd){
	V[u]=1;
	for(auto i:E[u]){
		int k=i.S,v=i.F;
		if(ps[k]){
			continue;
		}
		if(V[v])return void(pd=1);
		Dfs(v,pd);
		if(pd)return;
	}
}

int Cout(){
	memset(tmp,0,sizeof tmp);
	for(int i=1;i<=n;++i){
		for(auto j:E[i]){
			if(!ps[j.S]){
				++tmp[i];
			}
		}
		if(tmp[i]>1)return 0;
	}
	memset(V,0,sizeof V);
	for(int i=1;i<=n;++i){
		if(tmp[i]==1){
			int flag=0;
			Dfs(i,flag);
			return flag;
		}
	}
}

int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int a,b;
		cin>>a>>b;
		E[a].push_back({b,++tot});
		bj[Node(a,b)]=tot;
	}
	cin>>q;
	while(q--){
		int op,u,v;
		cin>>op;
		if(op==1){
			cin>>u>>v;
			int k=bj[Node(u,v)];
			ps[k]=1;
			if(Cout())cout<<"Yes\n";
			else cout<<"No\n";
		}
		else if(op==2){
			cin>>u;
			for(int i=1;i<=n;++i){
				int k=0;
				if(bj.count(Node(i,u)))k=bj[Node(i,u)];
				ps[k]=1;
			}
			if(Cout())cout<<"Yes\n";
			else cout<<"No\n";
		}
		else if(op==3){
			cin>>u>>v;
			int k=bj[Node(u,v)];
			ps[k]=0;
			if(Cout())cout<<"Yes\n";
			else cout<<"No\n";
		}
		else {
			cin>>u;
			for(int i=1;i<=n;++i){
				int k=0;
				if(bj.count(Node(i,u)))k=bj[Node(u,u)];
				ps[k]=0;
			}
			if(Cout())cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	
	return 0;
}
