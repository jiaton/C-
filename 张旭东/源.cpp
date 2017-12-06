/*11.24 钟卓杭*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
const int N = 6;

int cmp(const void *a,const void *b)//带入无类型指针常量a,b参数， 
{ return strcmp(*(char **)a,*(char**)b);//strcmp传入字符串首地址 
}//定义一个比较函数 

void sort(char * language[])
{
  qsort(language,N,sizeof(char *),cmp);
} 

void output(char * language[])
{ int i=0;
  for(i;i<N;i++)
  {
  	printf("%s\n",language[i]);
  }
}
int main()
{ char *Language[] = {"PASCAL","BASIC","C/C++","Fortran","JAVA","Turbo C"};
  sort (Language);
  output (Language); 
  return 0;
} 