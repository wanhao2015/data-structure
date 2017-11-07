#define MAX_SIZE 100;
typedef int Elemtype;				//线性表内元素数据类型
typedef struct
{
	Elemtype data[MAX_SIZE];
	int length;
}SqList;

/* 初始化顺序线性表 */
int InitList(SqList *L)
{
	L->length = 0;
	return 1;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
bool ListEmpty(SqList L)
{
	if(L.length == 0)
		return ture;
	else
		return false;
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
int ClearList(SqList *L )
{
	L->length = 0;
	return 1;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(SqList L)
{
	return L.length;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
int GetElem(SqList L,int i,Elemtype *e)
{
	if(L.length == 0 || i<1 || i>L.length)
		return -1;
	else
		*e=L.data[i-1];
	return 1;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int LocateElem(SqList L,Elemtype e)
{
	if(L.length == 0)
		return 0;
	for(int i=0;i<L.length;i++)
	{
	if(L.data[i] == e)
		break;
	}
	if(i>=L.length)
		return 0;
	return i+1;
}

/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
int ListInsert(SqList *L,int i,Elemtype e)
{
	if(L->length >= MAX_SIZE)
		return 0;
	if(i<1 || i>L->length+1)
		return 0;
	if(i == L->length+1)
		L->data[i-1]=e;
	else
	{
		for(int j=L->length;j>=i;j--)
		{
			L->data[j]=L->data[j-1];
		}
		L->data[i-1]=e;
	}
	L->length++;
	return 1;	
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Elemtype ListDelete(SqList *L,int i,Elemtype *e)
{
	if(L->length == 0 || i<1 || i>L->length)
		 return 0;
	 // if(i == L->length)
		 // *e = L.data[i-1];
	else
	{
		*e = L->data[i-1];
		for(int j=i;j<L->length;j++)
		{
			L->data[j-1]=L->data[j];
		}
		L->length--;
	}
	return *e;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
int ListVisit(SqList L)
{
	for(int i=0;i<L.length;i++)
		printf("d% ",L.data[i]);
	printf("\n");
	return 0;
}

//将所有的在线性表Lb中但不在La中的数据元素插入到La中；改变La，但不会改变Lb
void UnionList(SqList *La,SqList Lb)
{
	int Len_A,Len_B;
	Len_A = ListLength(*La);
	Len_B = ListLength(Lb);
	Elemtype e;
	for(int i=1;i<=Len_B;i++)
	{
		GetElem(Lb,i,&e);				//取出Lb中第i个数据元素赋值给e
		if(!LocateElem(*La,e))			//La中不存在和e相同的元素
			ListInsert(La,++Len_A,e);	//将e插入La尾端
	}
}









