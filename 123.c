#include<stdio.h>
#include<stdbool.h>
#define MaxSize 50
typedef struct{
	int data[MaxSize];
	int length;
}SqList;
void ListInit(SqList *L){
	L->length = 0;
	for (int i = 0; i < MaxSize; i++)
		L->data[i] = 0;

}
bool ListInsert(SqList* L, int i, int e) {
	if (i<1 || i>L->length + 1)
	{

		return false;
	}
	if (L->length >= MaxSize)
		return false;
	for (int j = L->length; j >= i; j--)
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	L->length++;
	return true;
}
void List_Reverse(SqList *L) {
	int temp = 0;
	if (L->length == 0)
		printf("SqList表为空");
	for (int i = 0; i < L->length / 2; i++)
	{
		temp = L->data[i];
		L->data[i] = L->data[L->length - 1 - i];
		L->data[L->length - 1 - i] = temp;
	}

}
void List_Printf(SqList* L) {
	for (int i = 0; i < 5; i++)
		printf("%d  ", L->data[i]);
}
int main()
{
	SqList list;
	SqList *L=&list;
	ListInit(L);
	ListInsert(L, 1, 5);
	ListInsert(L, 2, 2);
	ListInsert(L, 3, 6);
	ListInsert(L, 4, 10);
	int value=0;
	int* a = &value;
	List_Reverse(L);
	List_Printf(L);
	return 0;
}
