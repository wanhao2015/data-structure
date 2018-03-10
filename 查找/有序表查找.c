//折半查找
int Binary_Search(int* a,int n,int key)
{
	int low,mid,high;
	low=1;
	high=n;
	while(low<=high)
	{
		mid=(low+high)/2;  //mid=low+(high-low)/2;
		if(key>a[mid])
			low=mid+1;
		else if(key<a[mid])
			high=mid-1;
		else
			return mid;	
	}
	return 0;
}

//插值查找
int Binary_Search(int* a,int n,int key)
{
	int low,mid,high;
	low=1;
	high=n;
	while(low<=high)
	{
		mid=low+(high-low)*(key-a[low])/(a[high]-a[low]);
		if(key>a[mid])
			low=mid+1;
		else if(key<a[mid])
			high=mid-1;
		else
			return mid;	
	}
	return 0;
}

int Fibonacci(int n)
{
	if(n>=2)
		return Fibonacci(n-1)+Fibonacci(n-2); 
	else
		return n;
}

//斐波那契查找
int Fibonacci_Search(int* a,int n,int key)
{
	int low,high,mid,i,k;
	low=1;							//定义最低下标为记录首位
	high=n;							//定义最高下标为记录末位
	k=0;
	while(low<=high)				//计算n位位于斐波那契数列的位置
		k++;
	for(i=n;i<F[k]-1;i++)			//将不满的数值补全
		a[i]=a[n];
	
	while(low<=high)
	{
		mid=low+F[k-1]-1;			//计算当前分隔的下标
		if(key<a[mid])				//若查找记录小于当前分隔记录
		{
			high=mid-1;				//最高下标调整到分隔下标mid-1处
			k=k-1;					//斐波那契数列下标减一位
		}
		else if(key>a[mid])			//若查找记录大于当前分隔记录
		{
			low=mid+1;				//最低下标调整到分隔下标mid+1处
			k=k-2;					//斐波那契数列下标减两位
		}
		else
		{
			if(mid<=n)
				return mid;			//若相等则说明mid即为查找到的位置
			else
				return n;			//若mid>n说明是补全数值，返回n
		}
	}
	return 0;
}