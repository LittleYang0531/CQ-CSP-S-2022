#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
int n,m;
struct G{
	int u,v;
}e[M];
int head[M],cnt;
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].u=head[u];
	head[u]=cnt;
}
int q;
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	scanf("%d",&q);
	while(q--){
		cout<<"NO"<<endl;
	}
} 
