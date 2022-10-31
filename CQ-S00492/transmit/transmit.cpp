#include<iostream>
using namespace std;
int n,q,k;
int t,t1;
int s,s1;
int v[200001];
bool a[2001][2001];
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>q>>k;
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	for(int i=0;i<n-1;i++){
		cin>>t>>t1;
		a[t][t1]+=1;
		a[t1][t]+=1;
	}
	for(int i=0;i<q;i++){
		cin>>s>>s1;
		cout<<v[s];
	}
	return 0;
}
