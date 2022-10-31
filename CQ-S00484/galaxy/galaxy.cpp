#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;

int n,m,t,x,y,op,num=0;
int cd[N],bj[N][N],now[N][N];

int main(){
	
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=m;i++){cin>>x>>y;bj[x][y]=1;now[x][y]=1;cd[x]++;}
	for(int i=1;i<=n;i++)if(cd[i]!=1)num++;
	
	cin>>t;
	while(t--){
		cin>>op;
		if(op==1){cin>>x>>y;if(cd[x]==1)num++;now[x][y]=0;cd[x]--;if(cd[x]==1)num--;}
		if(op==2){
			cin>>x;
			for(int i=1;i<=n;i++)if(bj[i][x]&&now[i][x]){
				now[i][x]=0;if(cd[i]==1)num++;cd[i]--;if(cd[i]==1)num--;
			}
		}
		if(op==3){cin>>x>>y;if(cd[x]==1)num++;now[x][y]=1;cd[x]++;if(cd[x]==1)num--;}
		if(op==4){
			cin>>x;
			for(int i=1;i<=n;i++)if(bj[i][x]&&!now[i][x]){
				now[i][x]=1;if(cd[i]==1)num++;cd[i]++;if(cd[i]==1)num--;
			}
		}
		if(num==0)cout<<"YES\n";else cout<<"NO\n";
	}
	
	return 0;
}
//(/>w<)/fw
