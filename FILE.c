#include<stdio.h>

#include <stdio.h>
int main()
{
	int a = 10000;
	FILE* pf = fopen("test.txt", "wb");
	fwrite(&a, 4, 1, pf);//二进制的形式写到文件中
	fclose(pf);
	pf = NULL;
	return 0;
}
/*
int main(){
	int arr[256];
	FILE* fp = fopen("Text_ARR.txt", "rb");
	if (fp == NULL){
		printf("Open File Error\n");
		return;
	}
	fread(arr, sizeof(int), 256, fp);
	int pos = 0;
	int value = 0;
	while (1){
		printf("input position:>");
		scanf("%d", &pos);
		fseek(fp, (pos - 1)*4, SEEK_SET);
		//rewind(fp);
		int offset = ftell(fp);
		printf("%d pos value:>%d\n", pos, value);
		offset = ftell(fp);
	}
	fclose(fp);
	return 0;
}
*/
/*fseek()///fscanf()///ftell()///rewind()///
int main(){
	int arr[10];
	FILE* fp = fopen("Text_ARR.txt", "r");
	if (fp == NULL){
		printf("Open File Error\n");
		return;
	}

	long offset = ftell(fp);
	fscanf(fp, "%d", &arr[0]);
	offset = ftell(fp);
	size_t pos = 0;
	int value = 0;
	while (1){
		printf("input position:>");
		scanf("%d", &pos);
		fseek(fp, (pos-1)*2, SEEK_CUR);
		rewind(fp);
		offset = ftell(fp);
		fscanf(fp, "%d", &value);
		printf("%d pos value:>%d\n", pos, value);
		offset = ftell(fp);
	}
	fclose(fp);
	return 0;
}
*/
/*
int main(){
	int arr[10];
	FILE* fp = fopen("Text_ARR.txt", "r");
	if (fp == NULL){
		printf("Open File Error\n");
		return;
	}

	long offset = ftell(fp);
	fscanf(fp, "%d",&arr[0]);
	offset = ftell(fp);

	fclose(fp);
	return 0;
}
*/
/*
int main(int argc,char* argv[]){
	FILE* fp = fopen(argv[1], "rb");
	if (fp == NULL){
		printf("Open File Errer\n");
		return;
	}
	FILE* fp1 = fopen(argv[2], "wb");
	if (fp == NULL){
		printf("Open File Errer\n");
		return;
	}
	/*while (!feof(fp)){
		char ch = fgetc(fp);
		fputc(ch,fp1);
	}
	char ch[256] = { 0 };
	while (!feof(fp)){
		size_t sz = fread(ch, sizeof(char), 256, fp);
		if (sz == 0)
			break;
		fwrite(ch, sizeof(char), sz, fp1);
		/*char* res=fgets(ch, 256, fp);
		if (res == NULL)
			break;
		fputs(ch, fp1);
	}
	/*char ch= fgetc(fp);
	while (ch != EOF){
		fputc(ch, fp1);
		ch = fgetc(fp);
	}
	fputc(ch, fp1);
	fclose(fp);
	fclose(fp1);
	return 0;
}
*/
/*
int main(){
	char arr[10];
	int n = 10;
	FILE* fp = fopen("Text_ARR.txt", "a+");
	for (int i = 0; i < n; ++i){
		fscanf(fp, "%d", &arr[i]);
	}
	for (int i = 0; i < n; ++i){
		fprintf(fp, "%d ", arr[i]);
	}

	fclose(fp);
	return 0;
}
*/

/*
int main(){
	int arr[] = { 1,1,4,4,5};
	int n = sizeof(arr) / sizeof(arr[0]);
	FILE* fp = NULL;
	//FILE* fp1 = NULL;

	fp = fopen("Text_ARR1.txt", "r");
	if (fp == NULL){
		printf("Open File Error.\n");
		return;
	}
	//fwrite(arr, sizeof(int), n, fp);
	fread(arr, sizeof(int), n, fp);
	/*fp1 = fopen("Text_ARR1.txt", "w");
	if (fp1 == NULL){
		printf("Open File Error.\n");
		return;
	}*/

	//for (int i = 0; i < n; ++i){
	//	//scanf("%d", &arr[i]);
	//	fscanf(fp, "%d", &arr[i]);
	//}
	//for (int i = 0; i < n; ++i){
	//	//printf("%d  ",arr[i]);
	//	fprintf(fp, "%d  ", arr[i]);
	//}

	

/*
int main(){
	int arr[] = { 1, 2, 3, 4, 5, 12, 34, 56, 68, 89, 90,100 };
	int n = sizeof(arr) / sizeof(arr[0]);

	FILE* fp = NULL;
	FILE* fp1 = NULL;

	fp = fopen("Text_ARR.txt", "w");
	fp1 = fopen("Text_ARR1.txt", "w");
	
	if (fp == NULL){
		printf("Open File Error.\n");
		return;
	}

	for (int i = 0; i < n; ++i){
		//printf("%d  ",arr[i]);
		fprintf(fp, "%d  ", arr[i]);
	}

	
	fclose(fp);
	return 0;
}
*/