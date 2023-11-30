#include<bits/stdc++.h>
using namespace std;

void bfs(){
	//初始化，初始状态存入队列
	//队列首指针 head=0；尾指针 tail=1；
	do{
		//指针head后移一位，指向待拓展结点；
		for(int i=1,i<=max,i++){
			if(/*子节点符合条件*/){
				//tail 指针增加1，把新结点存入列尾；
				if(/*新结点与原已产生结点重复*/){
					//删去该结点（取消入队，tail减1； 
				}else{
					if(/*新结点是目标结点*/){
						//输出并退出； 
					}
				}
			}
		} 
	}while(head<tail);//队列为空 
}

int main(){
	bfs(); 
	return 0;
}

