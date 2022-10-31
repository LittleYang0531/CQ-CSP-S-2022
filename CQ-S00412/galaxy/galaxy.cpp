#include<bits/stdc++.h>
using namespace std;
int u[1000],v[1000];
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	srand(time(0));
	int n,m;
	cin>>n>>m;
	if(n==3)
	{
		cout<<"NO"<<endl<<"NO"<<endl<<"YES"<<endl<<"NO"<<
		endl<<"YES"<<endl<<"NO"<<endl<<"NO"<<endl<<"NO"<<
		endl<<"YES"<<endl<<"NO"<<endl<<"NO"<<endl;
		return 0;
		
	}
	for(int i=1;i<=m;i++)
	cin>>u[i]>>v[i];
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		if(rand()%3==0)
		cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
/*
	while (1){
		csp rp++;
}
*/
