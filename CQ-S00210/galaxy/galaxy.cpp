#include<iostream>
#include<cstdio>
using namespace std;
int n,m,t;
int f[1000]={};
int p[100][100]={};//连接;
int h[100][100]={};//q中的变化; x=1 3
int k[100]={};//x=2 4
int q,x;
int sum=0;
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	if(n==1) cout<<"NO"<<endl;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cin>>p[i][j];
			f[p[i][j]]=1;//原来是连通的;
		}
	}
	if(n==2&&f[p[1][2]]==1) cout<<"YES"<<endl;
	cin>>q;
	for(int i=1;i<=q;i++){
		for(int j=1;j<=q;j++){
			cin>>x;
			if(x%2!=0) cin>>h[i][j];
			else cin>>k[i];
			if(x=1) f[p[i][j]]=0;//表示不可以走;
			if(x=2) f[p[k[i]][j]]=0,f[p[i][k[i]]]=0;
			if(x=3) f[p[i][j]]=1;
			if(x=4) f[p[k[i]][j]]=1,f[p[i][k[i]]]=1;
		}
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=q;j++){
			if(f[p[i][j]]==1||f[p[j][i]]==1){
				sum+=1;
			}	
		}
		if(sum>1){
			cout<<"NO"<<endl;
			}
		if(sum==1){
			cout<<"YES"<<endl;
			}
		sum=0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
