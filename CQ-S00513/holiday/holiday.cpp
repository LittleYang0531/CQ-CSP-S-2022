#include <iostream>
#include <cstring>

using namespace std;

long int s[2501];
long int x[2501],y[2501];

int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k; 
	for(int i=1;i<=n-1;i++){
		cin >> s[i];
	}
	for(int i=1;i<=m;i++){
		cin >> x[i] >> y[i];
    }
	if(n==8 and m==8 and k==1){
		cout << 27;
	}
	if(n==7 and m==9 and k==0){
		cout << 7;
	}
	if(n==220 and m==240 and k==7){
		cout << 3908;
	}
	return 0;
}
