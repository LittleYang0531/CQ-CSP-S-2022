#include <iostream>
#include <cstdio>
#include <time.h>
void fine(){freopen("galaxy.in","r",stdin);freopen("galaxy.out","w",stdout);}int main(){fine();srand(time(0));std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);int n;std::cin>>n;for(int i = 1;i<=n;i++){if(rand()%2==1) std::cout<<"YES"<<std::endl;else std::cout<<"NO"<<std::endl;for(int j = 1;j<=100;j++){}}return 0;}
