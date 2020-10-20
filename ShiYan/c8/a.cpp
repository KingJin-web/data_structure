#include <stdio.h>
#include <string.h> 
//本题要求编写程序，从给定字符串中查找某指定的字符。
 
int main()  {  
  	char a[80];
	char b[1];
	int c[80]; //记录下标 输出最大下标
	int count=0; //记录重复下标数量 
	int i=0,j=0;//控制双层循环 
	int d;
	//输入的第一行是一个待查找的字符。第二行是一个以回车结束的非空字符串（不超过80个字符）。 
	scanf("%c",&b[0]); 
	d=getchar();//收掉第一个 \n
		
	d=getchar();
	while(d!='\n'){
		a[i]=(char)d;
   		i++;
   		d=getchar();
   	}
   	
   	
   	for(j=0;j<=i;j++){
   		if(a[j]==b[0]){
  			c[count]=j;
			count++; 			
   		}
   	}
   	
   	int index;
	if(count==0){
   		printf("Not Found");
   	}else{
		for(i=0;i<count;i++){
   			for(j=0;j<count;j++){
   				if(c[i]<=c[j]) index=c[j];
   			}
   		}
   		printf("index = %d",index);
   	}
 
   	
    return 0;  
} 