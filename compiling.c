#include<stdio.h>

#define MY_STRUCT(name)\
struct struct_##name{\
	int a;\
	int b;\
	int c;\
}
MY_STRUCT(wn);

void main(){
	struct struct_wn wn;
}
/*
#define SQUARE(x) printf(#x"*"#x"=%d",x*x);
int main(){
SQUARE(50);
return 0;
}
*/
/*
#define LOG(msg) Log(__FILE__,__LINE__,msg)
void Log(char *file,int line,char* msg){
printf("Log:\n    %s: %s: %s: %d: %s\n", file, __DATE__, __TIME__, line,msg);
}
int main(){
FILE* fp = fopen("TEXT_LOG.txt", "r");
if (NULL == fp){
LOG("Open File Error\n");
return;
}

LOG("Open File Successful");
return 0;
}
*/


/*
int main(){
	printf("%s\n", __FILE__);//�ļ�λ��
	printf("%s\n", __DATE__);//����
	printf("%s\n", __TIME__);//ʱ��
	printf("%d\n", __LINE__);//����
	//printf("%s\n", __STDC__);//��������ѭANSI C ����1������δ����
	return 0;
}
*/