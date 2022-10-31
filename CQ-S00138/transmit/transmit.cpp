#include<bits/stdc++.h>
using namespace std;
int n,m,k; 
int ans=0;
struct {
	int x;
	int goal;
}a[3000];
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
		cin>>n>>m>>k;
	for(int i=2;i<=n;i++){
		cin>>a[i].goal;
		a[i].x=i;
	}

	for(int i=2;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i].goal<a[j].goal)
			swap(a[i].goal,a[j].goal);
		}
	} 
	for(int i=1;i<=4;i++){
		ans+=a[i].goal;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
