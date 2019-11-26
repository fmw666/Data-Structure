#include <stdio.h> 

#define M 100
 
//正整数集合成员数量
int n;
//正整数子集的和
int all;
//正整数集合
int arr[M];
//记录子集成员
int x[M]; 
int mark = 0; 
 
int Constrain(int t)
{
	int i;
	int sum = 0; 
	//子集求和
	for(i=0; i<=t; i++) 
	{
 		if(x[i] == 1) 
		 	sum += arr[i]; 
 	} 
 	if(sum == all)
	{
  		printf("找到最优解"); 
  		//把最优解打印出来
		for(i=0; i<=t; i++)
		{  
			if(x[i] == 1)
				printf("%d ", arr[i]); 
		}
		//只要找到最优解，那么问题就结束 
 		mark=1; 
	} 
}

//检测有没有到达叶子节点
int Bound(int t){
	if(t < n) 
  		return 1;
 	else 
	 	return 0; 
}

int Backtrack(int t){
 	int i;
 
 	if(t < n)
	{
 		for(i=0; i<=1; i++)
		{
  			x[t] = i;
  			if(Constrain(t) && Bound(t))
			{
  				if(mark == 1)
					return 0; 
   				Backtrack(t+1);
  			}
 } 
} 
}
 
int main(){
 int i; 
 scanf("%d %d",&n,&all); 
 
 for(i=0;i<n;i++) {//给正整数集合赋值
 scanf("%d",&arr[i]); 
 } 
 
 for(i=0;i<n;i++) {//记录子集成员，一开始为空，也就是标记集合为全为0
    x[i]=0; 
 } 
 
 Backtrack( 0);
  
}