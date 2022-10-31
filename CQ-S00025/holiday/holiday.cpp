#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10005],f[10005][10005];
int s(int x,int z,int ans){
	if(x==0){
		if(z==1)return ans;
		else return -1;
	}
	int maxx=-1,y;
	for(int i = 1;i<=f[z][0];i++){
		y=s(x-1,f[z][i],ans+a[f[z][i]]);
		if(maxx<y)maxx=y;
	}
	return maxx;
}
int main(){
	//freopen("holiday.in","r",stdin);
	//freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 2;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		f[x][0]++;
		f[y][0]++;
		f[x][f[x][0]]=y;
		f[y][f[y][0]]=x;
	}
	cout<<s(k+1,1,0);
	return 0;
}
