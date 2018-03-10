//顺序查找，a为数组，n为数组长度，key为查找的关键字，（数组元素为下标为1-n）
int Sequential_Search1(int *a,int n,int key)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(a[i]==key)
			return i;
	}
	return 0;
}

//有哨兵顺序查找
int Sequential_Search2(int *a,int n,int key)
{
	int i=n;
	a[0]=key;
	while(a[i]!=key)
		i--;
	return i;
}