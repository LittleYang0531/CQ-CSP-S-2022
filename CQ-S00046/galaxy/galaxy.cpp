#include<iostream>
using namespace std;
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	for(int i=1;i<=50;i++){
		printf("NO\n");
		if(i%3==0)printF("YES\n");
	}
	return 0;
}
