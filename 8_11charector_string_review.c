
/*
memcpy
memset
memcmp
memmove
memchr


strcpy
strcat
strcmp
strlen
strstr
strtok
strerror

strncpy
strncat
strncmp


toupper
isupper


*/

#include<stdio.h>
#include<string.h>
//#include<assert.h>
#include<cassert>
#include<errno.h>
#include<ctype.h>

void* my_memset(void* des,int c,size_t count){
	assert(des != NULL);
	char* pdes =(char*) des;
	while (count-->0){
		*pdes = c;
		pdes++;
	}
	
}

int main(){
	int a[20]= { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int b[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

	my_memset(a,0,sizeof(a));
	return 0;
}
/*
char* my_strcpy(char* strDestination, const char* strSource){
	if (strDestination == NULL || strSource == NULL)
		return NULL;
	char *my_D = strDestination;
	const char* my_S = strSource;
	while (*my_S != '\0'){
		*my_D++= *my_S++;
		/*my_D++;
		my_S++;
	}
	*my_D = '\0';
	return strDestination;
}

char *my_strcat(char* D, char* S){
	assert(D != NULL && S != NULL);
	char* pD = D;
	char* pS = S;

	while (D != '\0')
		pD++;

	return D;
}

void my_upper(char* str){
	assert(str != NULL);

	//char* ps = str;
	while (*str!='\0'){
		//*str -= 32;
		*str=toupper(*str);
		str++;
	}
}

int  main(){
	char str1[] = "asAAd";
	//char str2[20] = "asdasasd";
	my_upper(str1);
	
	isupper('s');
	return 0;
}
*/
/*
//int main(){
//	FILE* fp = fopen("Text.txt", "r");
//	if (fp == NULL){
//		printf("errno=%d\n", errno);
//		char* err_mes = strerror(errno);
//		printf("err_mess=%s\n", err_mes);
//		return -1;
//	}


	//char str1[50] = "sasd";
	//char* str2 = "sadfaf";
	//char str3[100] = "";
	//strcpy(str3 , str1);
	////char* ret=strcpy(str1, str2);
	////printf("ret=%s\n", str1);
	//char* ret = strcat(str1, str3);
	//printf("ret=%s\n", str1);
	return 0;	
}
*/

//#include<iostream>
//using namespace std;
//#include<string.h>
//int main()
//{
//	char ch[] = "asdasd";
//	char ch2[] = "asdasd";
//	char ch3[] = "asdas2";
//	char ch4[] = "asdasd123";
//	int num = strcmp(ch, ch2);
//	int num2 = strcmp(ch, ch3);
//	int num3 = strcmp(ch, ch4);
//
//	cout << num << endl;
//	cout << num2 << endl;
//	cout << num3 << endl;
//	return 0;
//}
