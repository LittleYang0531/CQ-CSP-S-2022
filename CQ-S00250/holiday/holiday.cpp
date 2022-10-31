#include<bits/stdc++.h>
using namespace std;
int a[2505][2505],b[2505],n,m,k;
long long dfs(int d1,int d2,int d3,int d4,int d,int j){
	long long max1=0;
	if(j==4){
		if(a[1][d]==0)
			return -1;
		return b[d];
	}
	for(int i=2;i<=n;i++){
		if(a[i][d]==1&&i!=d1&&i!=d2&&i!=d3&&i!=d4)
			max1=max(dfs(d,d1,d2,d3,i,j+1),max1);
	}
	return max1+b[d];
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)
		cin>>b[i];
	for(int i=0,x,y;i<m;i++){
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
	}
	cout<<dfs(0,0,0,0,1,0);
	return 0;
}
