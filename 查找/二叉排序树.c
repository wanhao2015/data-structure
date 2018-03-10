#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */

//二叉树的二叉链表结点结构定义
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//递归查找二叉排序树中是否存在元素key
//指针f指向T的双亲，其初始调用为NULL
//若查找成功，则指针*p指向该数据元素结点，并返回true
//否则指针*p指向查找路径上访问的最后一个结点并返回false
Status SearchBST(BiTree T,int key,BiTree f,BiTree *p)
{
	if(!T)
	{
		*p=f;
		return FALSE;
	}
	else if(key==T->data)
	{
		*p=T;
		return TRUE;
	}
	else if(key<T->data)
		return SearchBST(T->lchild,key,T,*p);
	else if(key>T->data)
		return SearchBST(T-rchild,key,T,*p);
}

//当二叉排序树T中不存在元素等于key时
//插入key并返回true，否则返回false
Status InsertBST(BiTree *T,int key)
{
	BiTree s,p;
	if(SearchBST(*T,key,NULL,&p))
		return FALSE;
	else
	{
		s=(BiTree)malloc(sizeof(BiTNode));
		s->data=key;
		s->lchild=s->rchild=NULL;
		if(!p)
			*T=s;
		else if(key<p->data)
			p->lchild=s;
		else
			p->rchild=s;
		return TRUE;
	}
}

//创建一颗排序二叉树
int createBST()
{
	int a[10]={62,88,58,47,35,73,51,99,37,93};
	BiTree T=NULL;
	for(int i=0;i<10;i++)
		InsertBST(&T,a[i]);			//创建排序二叉树时会把第一个数作为树的根结点。
	return TRUE;
}

//从二叉排序树中删除结点p，并重接它的左或右子树；
Status Delete(BiTree *p)
{
	BiTree q,s;
	if((*p)->lchild==NULL)
	{
		q=*p;*p=(*p)->rchild;free(q);
	}
	else if((*p)->rchild==NULL)
	{
		q=*p;*p=(*p)->lchild;free(q);
	}
	else
	{
		q=*p;s=(*p)->lchild;		//p结点始终为被删除的结点
		while(s->rchild)			//找到待删结点的直接前驱
		{
			q=s;s=s->rchild;
		}
		(*p)->data=s->data;			//s指向被删结点的直接前驱，q指向s结点的双亲
		if(q!=*p)					//若q指向的不是被删除的的结点
			q->rchild=s-lchild;
		else
			q->lchild=s->lchild;
		free(s);
		
		/* q=*p;s=(*p)->rchild;
		while(s->lchild)
		{
			q=s;s=s->lchild;
		}
		(*p)->data=s->data;
		if(q!=*p)
			q->lchild=s->rchild;
		else
			q->rchild=s->rchild;
		free(s); */					//用后继结点来替换
	}
	return TRUE;
}

//若二叉排序树T中存在关键字key的数据元素时，则删除该数据元素结点，并返回TRUE;否则返回false；
Status DeleteBST(BiTNode *T,int key)
{
	if(!*T)											//不存在关键字等于key的数据元素；
		return FALSE;
	else
	{
		if(key==(*T)->data)							//找到关键字等于key的数据元素；
			return Delete(*T);
		else if(key<(*T)->data)
			return DeleteBST(&(*T)->lchild,key);
		else if(key>(*T)->data)
			return DeleteBST(&(*T)->rchild,key);
	}
}