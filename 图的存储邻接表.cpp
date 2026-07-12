#include <stdio.h>
#include <stdlib.h>
#define MaxNum 26
struct Node {
	char data;
	struct Node* next; 
}; 
struct Node* Vertex[MaxNum];
int Num;
int EdgeNum;
void InitGraph() {
	for (int i = 0; i < MaxNum; i++){
		Vertex[i] = NULL;
	}
}
void DirectionGraph() {
	printf("请输入图的顶点数目：");
	scanf("%d",&Num);
	printf("请输入图的边数目：");
	scanf("%d",&EdgeNum);
	printf("请以 A->B 的形式输入边：\n");
	for (int i = 0; i < EdgeNum; i++){
		char str[5];
		scanf("%s",str);
		char a = str[0];
		char b = str[3];
		struct Node* p1 = (struct Node*)malloc(sizeof(struct Node));
		p1->data = b;
		p1->next = Vertex[a - 'A'];
		Vertex[a - 'A'] = p1;
	} 
}
void PrintGraph() {
	printf("\n有向图邻接表：\n");
	for (int i = 0; i < Num; i++) {
		char v = 'A' + i;
		printf("%c ->", v);
		struct Node* p = Vertex[i];
		while (p != NULL) {
			printf(" %c", p->data);
			if (p->next != NULL) {
				printf(" ->");
			}
			p = p->next;
		}
		printf("\n");
	}
}
int main(){
	InitGraph();
	DirectionGraph();
	PrintGraph();
	return 0; 
}
