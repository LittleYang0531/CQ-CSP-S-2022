#include<bits/stdc++.h>
using namespace std;
int read(){
	int f=1,k=0;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		k=k*10+(c-'0');
		c=getchar();
	}
	return f*k;
}
int a[12000][12000];
int n=read(),m=read();
bool d(int x){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(a[x][i]==1) sum++;
	}
	if(sum==1) return 1;
	else return 0;
}
bool f(){
	int k=0,ans=0;
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]==1) sum++;
		}
		if(sum>0) k++,ans+=sum;
		else if(sum==0) return 0;
	} 
	if(k==n && ans>=n) return 1;
	else return 0;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		a[x][y]=1;
	}
	int q=read();
	while(q--){
		int t=read();
		if(t==1){
			int u=read(),v=read();
			a[u][v]=0;
		}
		else if(t==2){
			int u=read();
			for(int i=1;i<=n;i++) a[i][u]=0;
		}
		else if(t==3){
			int u=read(),v=read();
			a[u][v]=1;
		}
		else{
			int u=read();
			for(int i=1;i<=n;i++) a[i][u]=1;
		}
		int e=0;
		for(int i=1;i<=n;i++){
			if(!d(i)){
				printf("NO\n");
				e=1;
				break;
			}
		} 
		if(e==0 && f()) printf("YES\n");
		else if(e==0) printf("NO\n");
	}
	return 0;
} 
