#include<bits/stdc++.h>
using namespace std;
int n,m,q,t;
int a[15001][15001];
struct rode{
	int num;
	int tnt,a1[15001];
}b[15001];
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);	
	cin >>n >>m;
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%ld%ld",&x,&y);
		a[x][y]=1;
		b[x].num++;
		b[y].tnt++;
		b[y].a1[++b[y].tnt]=x;
	}
	cin >>q;
	for(int i=1;i<=q;i++){
		scanf("%ld",&t);
		if(t==1){
			int u,v;
			scanf("%ld%ld",&u,&v);
			b[u].num--;
			a[u][v]=0;
		}else if(t==2){
			int u;
			scanf("%ld",&u);
			for(int j=1;j<=b[u].tnt;j++){
				b[b[u].a1[j]].num-=(a[b[u].a1[j]][u]==1)?1:0;
				a[b[u].a1[j]][u]=0;
			}
		}else if(t==3){
			int u,v;
			scanf("%ld%ld",&u,&v);
			b[u].num++;
			a[u][v]=1;
		}else{
			int u;
			scanf("%ld",&u);
			for(int j=1;j<=b[u].tnt;j++){
				b[b[u].a1[j]].num+=(a[b[u].a1[j]][u]==0)?1:0;
				a[b[u].a1[j]][u]=1;
			}
		}
		bool flag=1;
		for(int j=1;j<=n;j++){
			if(b[j].num!=1){
				flag=0;
				break;
			}
		}
		if(flag) cout <<"YES\n";
		else cout <<"NO\n";
	}
	return 0;
}
/*
3 6 
2 3 
2 1 
1 2 
1 3 
3 1 
3 2 
11 
1 3 2 
1 2 3 
1 1 3 
1 1 2 
3 1 3 
3 3 2 
2 3 
1 3 1 
3 1 3
4 2 
1 3 2
*/
