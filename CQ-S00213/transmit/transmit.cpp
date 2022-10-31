#include<bits/stdc++.h>
using namespace std;
typedef long long llong;
typedef unsigned long long ullong;
const int MaxN=200000;
const ullong Inf=ULLONG_MAX;
struct Edge{
	int next;
	int to;
	Edge(){}
	Edge(const int next,const int to):next(next),to(to){}
}edge[(MaxN-1)*2+10];
int cnt=0,h[MaxN+10];
inline void AddEdge(const int from,const int to){
	edge[++cnt]=Edge(h[from],to);
	h[from]=cnt;
}
int n,q,k;
ullong a[MaxN+1];
void Read(){
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n-1;i++){
		int x,y;
		cin>>x>>y;
		AddEdge(x,y);
		AddEdge(y,x);
	}
}
int dfsx[MaxN*2+100],deep[MaxN*2+100],fir[MaxN+1],sign=0;
int prt[MaxN+1];
void Dfs(int u,int _deep){
	++sign;
	dfsx[sign]=u;
	deep[sign]=_deep;
	fir[u]=sign;
	for(int i=h[u];i;i=edge[i].next){
		if(edge[i].to!=prt[u]){
			prt[edge[i].to]=u;
			Dfs(edge[i].to,_deep+1);
			++sign;
			dfsx[sign]=u;
			deep[sign]=_deep;
		}
	}
}
int f0[20][MaxN*2+100],f1[20][MaxN*2+100];
void RMQ_Init(){
	Dfs(1,0);
	for(int i=1;i<=sign;i++){
		f0[0][i]=dfsx[i];
		f1[0][i]=deep[i];
	}
	for(int j=1;(1<<j)<=sign;j++){
		for(int i=1;i+(1<<j)-1<=sign;i++){
			if(f1[j-1][i]<f1[j-1][i+(1<<(j-1))]){
				f0[j][i]=f0[j-1][i];
				f1[j][i]=f1[j-1][i];
			}else{
				f0[j][i]=f0[j-1][i+(1<<(j-1))];
				f1[j][i]=f1[j-1][i+(1<<(j-1))];
			}
		}
	}
}
int RMQ(int lu,int ru){
	int l=fir[lu],r=fir[ru];
	if(l>r)swap(l,r);
	int len=log2(r-l+1);
	if(f1[len][l]<f1[len][r-(1<<len)+1]){
		return f0[len][l];
	}else{
		return f0[len][r-(1<<len)+1];
	}
}
void Solve(){
	RMQ_Init();
//cout<<"::"<<RMQ(4,7)<<endl;
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		vector<int>v;
		int lca=RMQ(x,y);
		while(x!=lca){
			v.push_back(x);
			x=prt[x];
		}
		vector<int>v1;
		while(y!=lca){
			v1.push_back(y);
			y=prt[y];
		}
		v.push_back(lca);
		for(int i=(int)v1.size()-1;i>=0;i--)
			v.push_back(v1[i]);
//for(int i=0;i<v.size();i++)
//	cout<<v[i]<<' ';
//cout<<'\n';
		vector<ullong>f(v.size());
		f[0]=a[v[0]];
//cout<<f[0]<<' ';
		for(int i=1;i<(int)v.size();i++){
			f[i]=Inf;
			for(int j=max(0,i-k);j<i;j++){
				f[i]=min(f[i],f[j]+a[v[i]]);
			}
//cout<<f[i]<<' ';
		}
//cout<<'\n';
		cout<<f[v.size()-1]<<'\n';
	}
}
signed main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
//	int T;
//	cin>>T;
//	while(T--){
		Read();
		Solve();
//	}
	return 0;
}

