#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,q;
bool tsg[100000][10000];
int t[312];
int s[10000];
int g[1000];
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		tsg[u][v]=true;
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>t[i]>>s[i]>>g[i];
		if(t[i]=1&&tsg[s[i]][g[i]])
		cout<<"Yes"<<endl;
		else cout<<"No"<<endl; 
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
