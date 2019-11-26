#include <stdio.h>

struct Job
{
	int begin, end;
	bool ok;
};
 
int manage(int n,Job *b)
{
	//count表示还剩余几个活动未安排
	int count=n,roomavail=0,roomnum=0;
	//当count=0就退出while循环s
	while(count > 0)
	{
		for(int i=1; i<=n; i++)
		{
			//如果当前活动未安排并且和会场中已   //有活动不冲突
			if((b[i].begin>roomavail) && (b[i].ok==0))
			{
				//将当前活动加入该会场，并且更新会场的空闲时间
				roomavail = b[i].end;
				//标记该活动已被安排
				b[i].ok = 1;
				//未安排的活动数减1
				count--;
			}
		}
		//把roomavail初始化，相当于重新再找一个房间
		roomavail = 0; 
		//遍历一次，使用的会场数加1
		roomnum++;
	}
	//返回使用的会场数
	return roomnum;
}
 
int main()
{
	int n;
    scanf("%d", &n);
	Job b[n+1];
	b[0].begin = 0;
	b[0].end = 0;
	b[0].ok = 0;
	
	for(int i=1; i<=n; i++){
		scanf("%d %d", &b[i].begin, &b[i].end);
		b[i].ok = 0;
	}
	
    for(int i=1; i<=n; i++){//排序
		for(int j=i+1; j<=n; j++){
			if(b[i].end > b[j].end){
				Job Register = b[i];
				b[i] = b[j];
				b[j] = Register;
			}
		}
	}
	
	int result = manage(n,b);
	printf("%d", result);	

	return 0;
}