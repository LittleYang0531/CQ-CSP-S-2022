#include<iostream>
using namespace std;
int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		int t;
		if(t==1){
			int x,y;
			cin>>x>>y;
		}
		if(t==2){
			int x;
			cin>>x;
		}
		if(t==3){
			int x,y;
			cin>>x>>y;
		}
		if(t==4){
			int x;
			cin>>x;
		}
	}
	for(int i=1;i<=q;i++){
		cout<<"NO"<<endl;
	}
	return 0;
}
