#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int inf=0x3f3f3f3f;
const int N=1e9;
int random(){
	return rand()*rand()*rand()%N;
}
int n,m;
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	srand(time(0));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		printf("%d\n",abs(random()));
	}
	return 0;
}
