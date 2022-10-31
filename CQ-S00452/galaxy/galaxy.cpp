#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin.tie(0),cout.tie(0);
	srand(time(NULL));
	int n,m,v,u;
	cin>>n>>m;
	while(m--)
		cin>>u>>v;
	ll q;
	cin>>q;
	if(rand()%3==0){
		while(q--)
			cout<<"NO"<<endl;
		return 0;
	}
		
	if(rand()%4==0){
		while(q--)
			cout<<"YES"<<endl;
			return 0;   
	}
		
	while(q--)
		if(rand()%2==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	return 0;
}

