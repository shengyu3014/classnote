#include<iostream> 
using namespace std;
bool vis[100];

int main(){
	int n;
	cin>>n;
	for(int i=2;i<=n;i++){
        if(!vis[i]){
            for(int j=2*i;j<=n;j+=i)	vis[j]=true;
        }
    }
    for(int i=1;i<=n;i++){
    	cout<<i<<" "<<vis[i]<<endl;
	}
	return 0;
}
