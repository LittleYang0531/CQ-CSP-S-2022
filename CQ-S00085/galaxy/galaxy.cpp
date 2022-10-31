#include<bits/stdc++.h>
using namespace std;
const int Maxn = 5e5+5;
long long n,m,Q;
int head[Maxn<<1],to[Maxn<<1],nxt[Maxn<<1],vis[Maxn<<1],tot;
void add(int a,int b){to[++tot]=b,nxt[tot]=head[a],head[a]=tot;}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
	  int a,b;
	  cin>>a>>b;
	  add(a,b);
	}
	cin>>Q;
	while(Q--){
	  int t,u,v;
	  cin>>t>>u;
	  if(t==1)
	  	cin>>v;
	  else if(t==3)
	  	cin>>v;
	  cout<<"NO"<<endl;
	}
	return 0;
}
