#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */

#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12			//定义散列表表长为数组的长度
#define NULLKEY -32768

typedef struct
{
	int *elem;				//数据元素存储基址，动态分配数组
	int count;				//当前散列表中数据元素个数
}HashTable;

int m=0;					//散列表表长，全局变量

//初始化散列表
Status InitHashTable(HashTable *H)
{
	m=HASHSIZE;
	H->count=m;
	H->elem=(int *)malloc(m*sizeof(int));
	for(int i=0;i<m;i++)
	{
		H->elem[i]=NULLKEY;
	}
	return OK;
}

//散列函数
int Hash(int key)
{
	return key % m;			//除留余数法
}

//插入关键字进散列表中
void InsertHashTable(HashTable *H,int key)
{
	int addr=Hash(key);
	while(H->elem[addr]!=NULLKEY && H->elem[addr]!=key)
		addr=(addr+1)%m;
	H->elem[addr]=key;		
}

//散列表查找关键字
Status SearchHashTable(HashTable H,int key,int *addr)
{
	*addr=Hash(key);
	while(H.elem[*addr]!=key)								//没有找到关键字key
	{
		*addr=(*addr+1)%m;									//开放地址法线性探索
		if(H.elem[*addr]==NULLKEY || *addr==Hash(key))		//如果循环回到原点
			return UNSUCCESS;
	}
	return SUCCESS;											//跳出while循环说明找到关键字key		
}