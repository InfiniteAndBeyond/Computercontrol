
#include <stdio.h>
#include "time.h"
#include "stdlib.h"

#define HASHSIZE 1000 // 定义散列表长为数组的长度
#define NULLKEY -32768

typedef int Status;




struct index {  //定义块的结构

    int key;
    int start;
    int end;
} newIndex[11];   //定义结构体数组

typedef struct{   //hash
    int *elem;    // 数据元素存储地址，动态分配数组
    int count;    //  当前数据元素个数
}HashTable;

// 散列表表长，全局变量
int m = 0;

//函数声明
void InitHashTable(HashTable *hashTable);
Status Hash(int key);
void Insert(HashTable *hashTable,int key);
Status Search(HashTable *hashTable,int key);
void DisplayHashTable(HashTable *hashTable);
int block_search(int key, int a[]);
int binarySearch(int a[], int low, int high, int key);
int hash_search(int a[],int key);
int InsertionSearch(int a[], int value, int low, int high);

 
int main(int argc, const char * argv[])
{  
    double time_length, start, finish; 
    //输出已知数组
    int i, j=-1, k, key,choose;
	int flag=1;
    int a[1000];
	for(i=1;i<1000;i++)
	{
		a[i]=i+1;
		printf("  %d  ",a[i]);
		if (i%10==0)
			printf("\n");
	}
  
    printf("\n\n");
    //输入要查询的数，并调用函数进行查找
	while (1)
	{
		start = 0;
		finish =0;
		printf("请输入您想要查找的数：\n");
		scanf("%d", &key);

		printf("请输入您想使用的算法：\n1--分块查找\n2--二分查找\n3--哈希查找\n4--插值查找\n");
		scanf("%d", &choose);
		if (choose == 1)
		{
			start = clock();//start 
			k = block_search(key, a); 
		}
		else if (choose == 2)
		{
			start = clock();
			k = binarySearch(a,1,1000, key);
		}
		else if (choose == 3)
		{
			start = clock();
			k = hash_search(a,key);
		}
		else if (choose == 4)
		{
			start = clock();
			k = InsertionSearch(a, key, 1, 1000);
		}
		else
			printf("请正确输入选项\n");

		//输出查找的结果

		if (k>0) {
			printf("查找成功！您要找的数在数组中的位置是：%d\n",k+1);
		}else{
			printf("查找失败！您要找的数不在数组中。\n");
		}
		finish = clock();//finish 
		time_length = (double)(finish - start) / CLOCKS_PER_SEC;//根据两个时刻的差，计算出运行的时间  
		printf("Time used is %f second.\n",time_length); 
	}
    return 0;

}

int hash_search(int a[],int key)
{
	int result;
    HashTable hashTable;
    //初始化哈希表
    InitHashTable(&hashTable);
     // 向哈希表中插入数据;
     //也就是把元素使用哈希函数映射到哈希表中；
    for (int i = 0;i < HASHSIZE;i++){
        Insert(&hashTable,a[i]);
    }
    //数据已存到哈希表中，打印观察哈希表，元素的位置和原数组是完全不一样的
   // DisplayHashTable(&hashTable);
    //查找数据
    result = Search(&hashTable,key);
	result --;
	return result;
}

int block_search(int key, int a[]){
	
    int i, j=-1,startValue;
	//确认模块的起始值和最大值
	for (i=0; i<10; i++) {
        newIndex[i].start = j+1;  //确定每个块范围的起始值
        j++;
        newIndex[i].end = j+99;  //确定每个块范围的结束值
        j += 99;
        newIndex[i].key = a[j];  //确定每个块范围中元素的最大值
        
        printf("newIndex[%d].start = %d\n",i, newIndex[i].start);
        printf("newIndex[%d].end = %d\n",i, newIndex[i].end);
        printf("newIndex[%d].key = %d\n\n",i, newIndex[i].key);
    }
    i = 0;
    while (i<10 && key>newIndex[i].key) { //确定在哪个块中，遍历每个块，确定key在哪个块中
        i++;
    }
    if (i>=10) {  //大于分得的块数，则返回0
        return -1;
    }
    startValue = newIndex[i].start;  //startValue等于块范围的起始值
    while (startValue<=newIndex[i].end && a[startValue]!=key) {  //在确定的块内进行查找
        startValue++;
    }
    if (startValue>newIndex[i].end) {  //如果大于块范围的结束值，则说明没有要查找的数，startValue置为0
        startValue = -1;
    }
    return startValue;

}

int binarySearch(int a[], int low, int high, int key)//递归  
{  
    if(low > high)  
        return -1;  
    int mid = (low + high)/2;  
    if(a[mid] == key)   
        return mid;  
    else if(a[mid] < key)  
        return binarySearch(a, mid+1, high,key);  
	else //(a[mid] > key)  
        return binarySearch(a, low, mid-1,key);  
} 

void InitHashTable(HashTable *hashTable){

    m = HASHSIZE;
    hashTable->elem = (int *)malloc(m * sizeof(int)); //申请内存
    hashTable->count = m;
    for(int i = 0;i < m;i++){
        hashTable->elem[i] = NULLKEY;
    }
}

//哈希函数(除留余数法)
Status Hash(int key){
    return key % m;
}

//插入
void Insert(HashTable *hashTable,int key){

    
      //根据每一个关键字，计算哈希地址hashAddress；
     
    int hashAddress = Hash(key); //求哈希地址
    
      //发生冲突，表示该位置已经存有数据
     
    while(hashTable->elem[hashAddress] != NULLKEY){
        //利用开放定址的线性探测法解决冲突
        hashAddress = (hashAddress + 1) % m;
    }
    //插入值
    hashTable->elem[hashAddress] = key;
}

//查找
Status Search(HashTable *hashTable,int key){
    //求哈希地址
    int hashAddress = Hash(key);
    //发生冲突
    while(hashTable->elem[hashAddress] != key){
        //利用开放定址的线性探测法解决冲突
        hashAddress = (hashAddress + 1) % m;
        if (hashTable->elem[hashAddress] == NULLKEY || hashAddress == Hash(key)){
            return -1;
        }
    }
    //查找成功
    return hashAddress;
}

//打印结果
void DisplayHashTable(HashTable *hashTable){
    for (int i = 0;i < hashTable->count;i++){
        printf("%d ",hashTable->elem[i]);
    }
    printf("\n");
}


//插值查找
int InsertionSearch(int a[], int value, int low, int high)
{
    int mid = low+(value-a[low])/(a[high]-a[low])*(high-low);
    if(a[mid]==value)
        return mid;
    if(a[mid]>value)
        return InsertionSearch(a, value, low, mid-1);
    if(a[mid]<value)
        return InsertionSearch(a, value, mid+1, high);
}










