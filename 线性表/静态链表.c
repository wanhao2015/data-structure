#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 1000 /* 存储空间初始分配量 */

typedef int Status;           /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char ElemType;        /* ElemType类型根据实际情况而定，这里假设为char */

typedef struct
{
	ElemType data;
	int cur;                  /* 游标(Cursor) ，为0时表示无指向 */
}Componet,StaticLinkList[MAXSIZE];

/* 将一维数组space中各分量链成一个备用链表，space[0].cur为头指针，"0"表示空指针 */
Status InitList(StaticLinkList space)
{
	for(int i=0;i<MAXSIZE-1;i++)
		space[i].cur=i+1;
	space[MAXSIZE-1].cur=0;
	return OK;
}

/* 若备用空间链表非空，则返回分配的结点下标，否则返回0 */
int Malloc_SLL(StaticLinkList space)
{
	int i=space[0].cur;						/* 当前数组第一个元素的cur存的值 */
	                                		/* 就是要返回的第一个备用空闲的下标 */
	if(space[0].cur)
		space[0].cur=space[i].cur;
	return i;
}

/*  将下标为k的空闲结点回收到备用链表 */
void Free_SLL(StaticLinkList space,int k)
{
	space[k].cur=space[0].cur;
	space[0].cur=k;
}

/* 初始条件：静态链表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(StaticLinkList L)
{
	int j=0;
    int i=L[MAXSIZE-1].cur;
	while(i)
	{
		j++;
		i=L[i].cur;
	}
	return j;
}

/*  在L中第i个元素之前插入新的数据元素e   */
Status ListInsert(StaticLinkList *L,int i,ElemType e)
{
	int j,k,l;
	k=MAXSIZE-1;
	if(i < 1 || i > ListLength(L)+1)
		return ERROR;
	j=Malloc_SLL(L);
	if(j)
	{
		L.data[j]=e;
		for(l=0;l<i-1;l++)
			k=L[k].cur;
		L[j].cur=L[k].cur;
		L[k].cur=j;
		return OK;
	}
	return ERROR;
}

/*  删除在L中第i个数据元素   */
Status ListDelete(StaticLinkList L, int i)
{
	int j,k;
	if (i < 1 || i > ListLength(L))   
        return ERROR;
	k=MAXSIZE-1;
	for(j=0;j<i-1;j++)
		k=L[k].cur;
	j=L[k].cur;
	L[k].cur=L[j].cur;
	Free_SSL(L, j);   
    return OK;
} 





