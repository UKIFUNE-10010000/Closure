#include<stdio.h>
#include<stdlib.h>
struct Tree{
	int data; 
	struct Tree * lchild;
	struct Tree * rchild;
}; 
struct Tree * CreateTree()
{
	int data;
	int temp;
	struct Tree * T;
	scanf("%d",&data);
	temp=getchar();
	if(data == -1){
		return NULL;
	}else{
		T = (struct Tree *)malloc(sizeof(struct Tree));
		T->data = data;
		printf("请输入%d的左子树：",data);
		T->lchild = CreateTree();
		printf("请输入%d的右子树：",data);
		T->rchild = CreateTree();
		return T;
	}
}
void ShowXianXu(struct Tree *T)
{
	if(T==NULL)
	{
		return;
	}
	printf("%d",T->data);
	ShowXianXu(T->lchild);
	ShowXianXu(T->rchild);
}
void ShowZhongXu(struct Tree * T)
{
	if(T==NULL)
	{
		return;
	}
	ShowZhongXu(T->lchild);
	printf("%d",T->data);
	ShowZhongXu(T->rchild);
}
void ShowHouXu(struct Tree * T)
{
	if(T==NULL)
	{
		return;
	}
	ShowHouXu(T->lchild);
	ShowHouXu(T->rchild);
	printf("%d",T->data);
}
int main()
{
	struct Tree * S;
	printf("请输入第一个节点的数据：\n");
	S = CreateTree();
	printf("先序遍历的结果：\n");
	ShowXianXu(S);
	printf("\n中序遍历的结果：\n");
	ShowZhongXu(S);
	printf("\n后序遍历的结果：\n");
	ShowHouXu(S);
	return 0;
}
