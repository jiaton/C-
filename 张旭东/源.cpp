/*11.24 ��׿��*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
const int N = 6;

int cmp(const void *a,const void *b)//����������ָ�볣��a,b������ 
{ return strcmp(*(char **)a,*(char**)b);//strcmp�����ַ����׵�ַ 
}//����һ���ȽϺ��� 

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