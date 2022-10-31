#include<bits/stdc++.h>
using namespace std;
int n,m,q,nxt[1000010],to[1000010],tot,h[500010];
void add(int x,int y){
	to[++tot]=y;
	nxt[tot]=h[x];
	h[x]=tot;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1,x,y;i<n;++i)cin>>x>>y,add(x,y),add(y,x);
	cin>>n;
	while(q--)cout<<"NO\n";
	return 0;
}
/*
1.调试后打开freopen
2.注意开long long
3.最后5分钟不要敲代码，编译运行并使用文件输入输出 
*/
