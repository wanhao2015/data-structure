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

//插入元素e为新的栈顶元素
Status Push(SqStack *S,SElemType e)
{
	if(S->top==MAXSIZE-1)
		return ERROR;
	S->top++;
	S->data[S->top]=e;
	return OK;
}