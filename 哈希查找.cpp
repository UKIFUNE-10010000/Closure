#include<stdio.h>
#include<string.h>
int HashArr[200];
#define len 11
#define arrlen 8
void CreatHash(int arr[]){
	int pos=0,j;
	for(int i=0;i<arrlen;++i)
	{
		pos=arr[i]%len;
		if(HashArr[pos]==-1){
			HashArr[pos]=arr[i];
		}
		else {
			j=1;
			while(HashArr[(pos+j)%len]!=-1){
				j++;
			}
			HashArr[(pos+j)%len]=arr[i];
		}
	}
} 
int SearchHash(int temp)
{
	int pos=temp%len;
	if(HashArr[pos]==temp)
	{
		return pos;
	}
	else {
		int j=1;
		while(HashArr[(pos+j)%len]!=temp)
		{
			j++;
		}
		return (pos+j)%len;
	}
}
void ShowHash(int arr[]){
	for (int i = 0; i < len; ++i){
		printf("%4d",i);
	}
	printf("\n----------------------------------------------------------------------\n");
	for (int i = 0;i < len; ++i) {
		if(HashArr[i]==-1)
			printf(" [] ");
		else
			printf("%4d",HashArr[i]);
	}
}
int main()
{
	memset(HashArr,-1,sizeof(HashArr));
	int arr[8]={25,19,15,33,36,41,9,21};
	CreatHash(arr);
	for (int i = 0;i < arrlen ;++i) {
		int position=SearchHash(arr[i]);
		printf("%d的余数：%d 在哈希表的位置为：%-d号位\n",arr[i],arr[i]%len,position);
	}
	printf("\n");
    ShowHash(arr);
	return 0;
}

