#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void InsertionSort( int A[],int N){
	int P,i,Tmp;
	for (P =1; P<N;P++){
	Tmp = A[P];
	for (i=P;i>0 && A[i-1] > Tmp;i--)
	A[i] = A[i-1];
	
	A[i]=Tmp;
	}
}

int BinarySearch(int arr[],int arr_len,int find_x){
	int left=0;
	int right = arr_len-1; 
	int mid;
	while(left<=right){
		mid=(left+right)/2;
		if(arr[mid]==find_x){
			return mid;
		}
		if(arr[mid]<find_x){
			left=mid+1;
		}
		if(arr[mid]>find_x){
			right=mid-1;
		}
	}
	return -1;
}
void getRandom(int arr[],int arr_len){
	srand( (int)time(NULL));
	for(int i=0;i<arr_len;i++){
		arr[i]=rand()%1000;
	}
}
int main(){
	int arr_len;
	int arr[10000];
	printf("请输入数组大小：");
	scanf("%d",&arr_len);
	getRandom(arr,arr_len);
	InsertionSort(arr,arr_len);
	puts("显示排序后结果：");
	for(int i=0;i<arr_len;i++){
		printf("%5d",arr[i]);
	}
	printf("\n");
	int find_x;
	printf("请输入你要查的数");
	scanf("%d",&find_x);
	int find_ans=BinarySearch(arr,arr_len,find_x);
	if(find_ans==-1)
	printf("查找失败\n");
	else
	printf("查找成功，该数值位于第%d个‘\n",find_ans+1);
	return 0;
}
