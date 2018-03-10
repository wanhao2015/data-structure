#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status; 
typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */

//顺序栈数据结构
typedef struct
{
	SElemType data[MAXSIZE];
	int top;								//用于栈顶指针
}SqStack;

//初始化一个顺序栈
Status InitStack(SqStack *S)
{
	/* S.data=(SElemType *)malloc(MAXSIZE*sizeof(SElemType)); */
	S->top=-1;
	return OK;
}

/* 把S置为空栈 */
Status ClearStack(SqStack *S)
{
	S->top=-1;
	return Ok;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(SqStack S)
{
	if(S.top==-1)
		return TRUE;
	else
		return FALSE;
}

/* 返回S的元素个数，即栈的长度 */
int StackLength(SqStack S)
{
	return S.top+1;
}

/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
Status GetTop(SqStack S,SElemType *e)
{
	if(S.top==-1)
		return ERROR;
	else
		*e=S.data[S.top];
	return OK;
}

//插入元素e为新的栈顶元素
Status Push(SqStack *S,SElemType e)
{
	if(S->top==MAXSIZE-1)
		return ERROR;
	S->top++;
	S->data[S->top]=e;
	return OK;
}
//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
Status Pop(SqStack *S,SElemType *e)
{
	if(S->top==-1)
		return ERROR;
	*e=S->data[S->top];
	S->top--;
	return OK;
}

/* 从栈底到栈顶依次对栈中每个元素显示 */
Status StackTraverse(SqStack S)
{
	int i=0;
	while(i<S.top+1)
	{
		printf("%d ",S.data[i]);
		i++;
	}
	return OK;
}

