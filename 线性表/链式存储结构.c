#define MAX_SIZE 100;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Elemtype;		//线性表内元素数据类型
typedef int Status;			//Status是函数的类型,其值是函数结果状态代码，如OK等

//单链表存储结构
typedef struct 
{
	Elemtype data;
	struct Node *next;
}Node;
typedef struct Node *LinkList;

Status InitList(LinkList *L)
{
	*L=(LinkList)malloc(sizeof(Node));
	if(!(*L))
		return ERROR;
	(*L)->next= NULL;
	return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
bool ListEmpty(LinkList L)
{
	if(L->next == NULL)
		return true;
	else
		return false;
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(LinkList *L)
{
	LinkList p,q;
	p=(*L)->next;
	while(p)
	{
		q=p->nxet;
		free(p);
		p=q;
	}
	(*L)->next == NULL;
	return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
Status ListLength(LinkList L)
{
	int j=0;
	LinkList p;
	p=L->nxet;			//p指向第一个结点
	while(p)
	{
		p=p->next;
		j++;
	}
	return j;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值 */
Status GetElem(LinkList L,int i,Elemtype *e)
{
	LinkList p;
	p=L->next;  				//p指向第一个结点
	int j=1;
	while(p && j<i)
	{
		p=p->next;
		j++;
	}
	if(p==NULL||j>i)
		return ERROR;
	else 
		*e=p->data;
	return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
Status LocateElem(LinkList L,Elemtype e)
{
	int i=0;
	LinkList p;
	p=L->next;
	while(p)
	{
		i++;
		if(p->data == e)
			return i;
		p=p->next;
	}
	return 0;
}

/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(LinkList *L,int i,Elemtype e)
{
	LinkList p,s;
	p=*L;  						//p指向头结点
	int j=1;
	while(p && j<i)
	{
		p=p->next;
		j++
	}
	if(p == NULL || j>i)
		return ERROR;
	s=(LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(LinkList *L,int i,Elemtype *e)
{
	LinkList p;
	int j=1;
	p=*L;
	while(p && j<i)
	{
		p=p->next;
		j++;
	}
	if(p->next == NULL || j>i)
		return ERROR;
	*e=p->next->data;
	p->next=p->next->next;
	return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(LinkList L)
{
	LinkList p;
	p=(*L)->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
	return OK;
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
void CreateListHead(LinkList *L,int n)
{
	LinkList p;
	srand(time(0));
	*L=(LinkList)malloc(sizeof(Node));
	(*L)->next=NULL;
	for(int i=0;i<n;i++)
	{
		p=(LinkList)malloc(sizeof(Node));
		p->data=rand()%100+1;
		p->next = (*L)->next;
		(*L)->next=p;
	}
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void CreateListTail(LinkList *L,int n)
{
	LinkList p,r;
	srand(time(0));
	*L=(LinkList)malloc(sizeof(Node));
	r=*L;
	for(int i=0;i<n;i++)
	{
		p=(LinkList)malloc(sizeof(Node));
		p->data=rand()%100+1;
		r->next=p;
		r=p;
	}
	r->next=NULL;
}





