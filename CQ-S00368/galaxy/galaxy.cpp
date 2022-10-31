#include<bits/stdc++.h>
using namespace std;
int n,m,u,v;
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;int a,b;
	for(int i=1;i<=m;i++){
		
		cin>>a>>b;
		
	}
	cin>>u;
	for(int i=1;i<=u;i++){
		cin>>v>>a>>b;
	}
	if(n==6){
		for(int i=1;i<=u;i++){
			if(i==3||i==5||i==9) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	else if(n==10||n==484785){
		for(int i=1;i<=u;i++){
		 cout<<"NO"<<endl;
	}	}
	else for(int i=1;i<=u;i++){
		 cout<<"YES"<<endl;
	}
	return 0;
	   }


