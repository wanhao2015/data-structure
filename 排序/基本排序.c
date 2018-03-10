#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAX_LENGTH_INSERT_SORT 7 /* 用于快速排序时判断是否选用插入排序阙值 */

#define MAXSIZE 10000  /* 用于要排序数组个数最大值，可根据需要修改 */

typedef int Status; 

typedef struct
{
	int r[MAXSIZE+1];		//用于存储要排序数组，r[0]可用作哨兵或临时变量
	int length;				//用于记录顺序表的长度
}SqList;

//交换L中数组r的下标为i和j的值。
void swap(SqList *L,int i,int j)
{
	int temp=L->r[i];
	L->r[i]=L->r[j];
	L->r[j]=temp;
}

//打印顺序表L中的元素
void PrintSqlist(SqList L)
{
	for(int i=1;i<L->length;i++)
	{
		printf("%d ",L.r[i]);
	}
	printf("%d",L.r[i]);
	printf("\n");
}

//对顺序表L作交换排序（冒泡排序初级版）
void BubbleSort0(SqList *L)
{
	for(int i=1;i<L->length;i++)
	{
		for(int j=i+1;j<=L->length;j++)
		{
			if(L->r[i]>L->r[j])
				swap(L,i,j);
		}
	}
}

//对顺序表L作冒泡排序;
void BubbleSort(SqList *L)
{
	for(int i=1;i<L->length;i++)
	{
		for(int j=L->length-1;j>=i;j--)		//注意j是从后往前循环
		{
			if(L->r[j]>L-r[j+1])
				swap(L,j,j+1);
		}
	}
}

//对顺序表L作改进冒泡算法
void BubbleSort2(SqList *L)
{
	Status flag=TRUE;						//flag用来作标记
	for(int i=1;i<L->length && flag;i++)
	{
		flag=FALSE;
		for(int j=L->length-1;j>=i;j--)		//注意j是从后往前循环
		{
			if(L->r[j]>L-r[j+1])
			{
				swap(L,j,j+1);
				flag=TRUE;
			}	
		}
	}
}

//对顺序表L作简单选择排序
void SelectSort(SqList *L)
{
	for(int i=1;i<L->length;i++)
	{
		int min=i;							//将当前下标定义为最小值下标
		for(int j=i+1;j<L->length+1;j++)
		{
			if(L->r[min]>L->r[j])			//如果有小于当前最小值的关键字，将此关键字的下标赋值给min
				min=j;
		}
		if(min!=i)							//若min不等于i，说明找到最小值，则交换下标为i和min的数组值
			swap(L,min,i);
	}
}

//对顺序表L作直接插入排序
void InsertSort(SqList *L)
{
	for(int i=2;i<=L->length;i++)
	{
		if(L->r[i]<L->r[i-1])
		{
			L->r[0]=L->r[i];					//设置哨兵，若第i个值小于已排好序列的最大值，则需要插入，并将其设置成哨兵
			for(int j=i-1;L->r[j]>L->r[0];j--)	//已排好序列中大于哨兵值的记录需要依次后移，直到找到小于哨兵值得元素，并跳出循环
			{
				L->r[j+1]=L->r[j];
			}
			L->r[j+1]=L->r[0];					//将哨兵值插入到第一个小于哨兵值的元素之后。
		}
	}
}

//对顺序表L作希尔排序
void ShellSort(SqList *L)
{
	int increment=L->length;
	do
	{
		increment=increment/3+1;						//增量序列
		for(int i=increment+1;i<=L->length;i++)
		{
			if(L->r[i]>L->r[i-increment])				//需将L->r[i]插入有序增量子表
			{
				L->r[0]=L->r[i];
				for(int j=i-increment;j>0 && L->r[j]>L->r[0];j=j-increment)
					L->r[j+increment]=L->r[j];		//循环，记录后移，当increment变小后，后移的判断次数会逐渐变多，注意j的变化和判断条件
				L->r[j+increment]=L->r[0];				//插入L->r[0]值
			}
		}
	}
	while(increment>1);
}

/*已知L->r[s..m]中记录的关键字除L->r[s]之外均满足堆的定义，
本函数调整L->r[s]的关键字，使L->r[s..m]成为一个大顶堆*/
void HeapAdjust(SqList *L,int s,int m)
{
	int temp=L->r[s];
	for(int i=2*s;i<m;i*=2)				//沿关键字较大的孩子结点向下筛选
	{
		if(i<m && L->r[i]<L->r[i+1])
			i++;						//i为关键字中较大的记录的下标
		if(temp>=L->r[i])				//若temp更大，代表不用移动数据，已经是大顶堆了
			break;
		L->r[s]=L->r[i];
		s=i;
	}
	L->r[s]=temp;						//插入
}

//对顺序表L作堆排序
void HeapSort(SqList *L)
{
	for(int i=L->length/2;i>0;i--)			//i为堆中均有两个孩子的结点的下标；L数组存储堆结构是按层序遍历存入的。L->r[1]为根结点,该值应为最大。
		HeapAdjust(L,i,L->length);
	for(int j=L->length;j>0;j--)
	{
		swap(L,1,j);						//将堆顶记录和当前未经排序子序列的最后一个记录交换
		HeapAdjust(L,1,j-1);				//将L->r[1...j-1]重新调整为大顶堆
	}
}

//对顺序表L作归并排序
void MergeSort(SqList *L)
{
	MSort(L->r,L->r,1,L->length);
}

//将SR[s...t]归并排序为TR1[s...t]
void MSort(int SR[],TR1[],int s,int t)
{
	int m;
	int SR2[MAXSIZE+1];
	if(s==t)
		TR1[s]=SR[s];
	else
	{
		m=(s+t)/2;
		MSort(SR,SR2,s,m);			//递归将SR[s...m]归并为有序的SR2[s...m];
		MSort(SR,SR2,m+1,t);		//递归将SR[m+1...t]归并为有序的SR2[m+1...t];
		Merge(SR2,TR1,s,m,t);		//将SR2[s...m]和SR2[m+1...t]归并到TR1[s...t]
	}
}

//将有序序列SR[i...m]和有序序列SR[m+1...n]归并为有序序列TR[i...n]
void Merge(int SR[],int TR[],int i,int m,int n)
{
	int j,k,l;
	for(j=m+1,k=i;i<=m && j<=n;k++)
	{
		if(SR[i]<SR[j])
			TR[k]=SR[i++];
		else
			TR[k]=SR[j++];
	}
	if(i<=m)
	{
		for(l=0;l<=m-i;l++)				//将剩余的SR[i..m]复制到TR中
			TR[k+l]=SR[i+l];
	}
	if(j<=n)
	{
		for(l=0;l<n-j;l++)				//将剩余的SR[m+1..n]复制到TR中
			TR[k+l]=SR[j+l];
	}
}

//对顺序表L作归并非递归排序
void MergeSort2(SqList *L)
{
	int k=1;
	int *TR=(int *)malloc(L->length*sizeof(int));
	while(k<L->length)
	{
		MergePass(L->r,TR,k,L->length);
		k=2*k;								//子序列长度加倍，
		MergePass(TR,L->r,k,L->length);		//两次调用，替换之前的函数递归；
		k=2*k;
	}
}

//将SR[]中相邻长度为s的子序列两两归并到TR[]中；
void MergePass(int SR[],int TR[],int s,int n)
{
	int i=1;
	int j;
	while(i<=n-2*s+1)							//判断条件要求n>=i+2*s-1
	{
		Merge(SR,TR,i,i+s-1,i+2*s-1);			//两两归并
		i=i+2*s;
	}
	if(i<n-s+1)									//判断条件要求 i+2*s-1>n>i+s-1
		Merge(SR,TR,i,i+s-1,n);					//归并最后两个序列，且两个序列长度不一样
	else										//最终归并只剩下一个子序列，即L->length为2幂次方。
	{
		for(j=i;j<=n;j++)						
			TR[j]=SR[j];
	}
}

//对顺序表L作快速排序
void QuickSort(SqList *L)
{
	QSort(L,1,L->length);
}

//对顺序表L中的子序列L->r[low...high]作快速排序
void QSort(SqList *L,int low,int high)
{
	int pivot;
	if(low<high)
	{
		pivot=Partition(L,low,high);		//将L->r[low...high]一分为二，算出枢轴值pivot
		QSort(L,low,pivot-1);				//对低子表递归排序
		QSort(L,pivot+1,high);				//对高子表递归排序
	}
}

//交换顺序表L中子表的记录，使枢轴记录到位，并返回其所在位置
//此时在它之前（后）的记录均不大（小）于它；
int Partition(SqList *L,int low,int high)
{
	int pivotkey=L->r[low];
	while(low<high)
	{
		while(low<high && L->r[high]>=pivotkey)
			high--;
		swap(L,low,high);
		while(low<high && L->r[low]<=pivotkey)
			low++;
		swap(L,low,high);
	}
	return low;
}

//对快排进行优化，
//当数据很多时，用快排；数据很少时，用直接插入排序
void QSort(SqList *L,int low,int high)
{
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		while(low<high)
		{
			pivot=Partition_new(L,low,high);		//将L->r[low...high]一分为二，算出枢轴值pivot
			QSort(L,low,pivot-1);					//对低子表递归排序
			low=pivot+1;							//尾递归
		}	
	}
	else
		InsertSort(L);
}

//快速排序优化核心算法
int Partition_new(SqList *L,int low,int high)
{
	int pivotkey;
	int m=(low+high)/2;
	if(L->r[high]<L->r[low])
		swap(L,low,high);
	if(L->r[high]<L->r[m])
		swap(L,m,high);
	if(L->r[low]<L->r[m])
		swap(L,low,m);
	
	pivotkey=L->r[low];		//此时L->r[low]已经为整个序列左中右三个关键字的中间值
	
	L->r[0]=pivotkey;		//将枢轴关键字备份到L->r[0];
	while(low<high)
	{
		while(low<high && L->r[high]>=pivotkey)
			high--;
		L->r[low]=L->r[high];	//使用替换而不是交换的方式进行操作，可以减少交换数据操作，是性能得到提升。
		//swap(L,low,high);
		while(low<high && L->r[low]<=pivotkey)
			low++;
		L->r[high]=L->r[low];
		//swap(L,low,high);
	}
	L->r[low]=L->r[0];			//将枢轴值替换回L->r[low];跳出上面循环的条件为low和high相等.
	return low;
}
