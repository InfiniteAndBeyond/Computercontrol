
/*

#include <iostream>  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
using namespace std;  
struct student  
{   
  int id;  // 学号  
  char name[30]; // 姓名  
  char sex[2];  // 性别   
  float gread; // 成绩  
};  
typedef struct student DataType; //  指定struct student为DataType  
struct SeqList  
{  
 int MAX;     // 顺序表中最大元素的个数  
 int count;         // 存放线性表中元素的个数count <= MAXLENGTH  
 DataType* element;  // element[0], element[1], ..., element[n - 1]存放线性表中的元素  
};  
typedef struct SeqList *MySeqList;   
// 初始化并创建空顺序表  
MySeqList initSeqList(int m);  
// 判断线性表是否为空  
int isEmptySeqList(MySeqList mySeqList);  
// 在顺序表中求某元素的下标  
int locateSeqList(MySeqList mySeqList, int id);  
// 在顺序表中修改值  
int updateSeqList(MySeqList mySeqList, int id);  
// 顺序表的插入(元素p之前插入)  
int insertPreSeqList(MySeqList mySeqList, int p, DataType x);  
// 顺序表的插入(元素p之后插入)  
int insertNextSeqList(MySeqList mySeqList, int p, DataType x);  
// 顺序表的删除(根据下标删除)  
int deleteSeqList(MySeqList mySeqList, int p);  
// 顺序表的删除(根据元素值删除)  
int deleteSeqListByValue(MySeqList mySeqList, int id);  
// 将顺序表表示的线性表逆置  
int reverseSeqList(MySeqList mySeqList);  
  
int deleteAllVSeqList(MySeqList mySeqList, DataType x);  
// 求出下标为i的元素的前驱和后继  
int findPrePostSeqList(MySeqList mySeqList, int i, DataType &m, DataType &n);  
// 顺序表实现部分：找出值为x的元素的前驱和后继的存储位置(即下标)  
int locatePrePostSeqList(MySeqList mySeqList, DataType x, int &i, int &j);  
// 输出线性表的元素值  
void printSeqList(MySeqList &mySeqList);  
// 根据学生id,输出线性表的元素值  
void printSeqListById(MySeqList &mySeqList,int id);  
// 在顺序表中修改值  
int updateSeqList(MySeqList mySeqList, int id)   //学生信息登入  
{  
 int iRc = locateSeqList(mySeqList, id);  
 if (iRc == -1)  
 {  
  printf("不存在指定下标!\n");  
  return (0);  
 }  
   
 cout<<"学号   姓名   性别    成绩 "<<endl;  
 cin>>mySeqList->element[iRc].id>>mySeqList->element[iRc].name>>mySeqList->element[iRc].sex>>mySeqList->element[iRc].gread;  
  return 1;  
}  

// 功能: 创建空顺序表
MySeqList initSeqList(int m)
{
 MySeqList mySeqList = (MySeqList)malloc(sizeof(struct SeqList)); // 分配内存空间
 if (mySeqList != NULL)
 {
  mySeqList->element = (DataType*)malloc(sizeof(DataType) * m);   // 为里面的元素分配m个DataType大小的内存空间,相当于初始化了一个长度为m的数组
  if (mySeqList->element)
  {
   mySeqList->MAX = m;  // 如果创建了元素，MAXLENGTH为最大元素的个数
   mySeqList->count = 0;  // 空表长度为0
   return (mySeqList);
  }
  else
   free(mySeqList);        // 记得要手动释放空间，否则很容易产生内存泄漏
 }
 printf("内存空间不足，请关闭一些程序，然后再试!\n"); // 存储分配失败，提示空间不足
 return NULL;
}
// 功能: 判断线性表是否为空
int isEmptySeqList(MySeqList mySeqList)
{
 return (mySeqList->count ==0);
}
// 功能:在顺序表中求某元素的下标,没有查找到，则返回-1
int locateSeqList(MySeqList mySeqList, int id)
{
 for (int i = 0; i < mySeqList->count; ++i)
  if (mySeqList->element[i].id == id)             // 传入一个元素x,查找到后返回下标i
   return (i);
 return (-1);
}
// 功能:顺序表的pos下标前面插入,插入成功返回1,失败返回0
int insertPreSeqList(MySeqList mySeqList, int pos, DataType x)
{
 ++mySeqList->count;
 if (mySeqList->count > mySeqList->MAX)      // 溢出
 {
  --mySeqList->count;    
  printf("表产生了溢出!\n");
  return (0);
 }
 if (pos < 0 || pos >= mySeqList->count)         // 不存在下标为pos的元素
 {
  --mySeqList->count;
  printf("不存在指定下标!\n");
  return (0);
 }
 for (int i = mySeqList->count - 1; i != pos; --i)
  {mySeqList->element[i] = mySeqList->element[i - 1]; // 插入位置及之后的元素均后移一个位置
 mySeqList->element[i] = x;                          // 插入元素x
 return (1);
 }
}
// 功能:顺序表的pos下标后面插入,插入成功返回1,失败返回0
int insertNextSeqList(MySeqList mySeqList, int pos, DataType x)
{
 if (pos < 0 || pos >= mySeqList->count)
 {
  printf("不存在指定下标!\n");
  return (0);
 }
 ++mySeqList->count;
 if (mySeqList->count >= mySeqList->MAX)
 {
  --mySeqList->count;
  printf("表产生了溢出!\n");
  return (0);
 }
 
 for (int i = mySeqList->count - 1; i != pos + 1; --i)
  {mySeqList->element[i] = mySeqList->element[i - 1];  // 同样地，把pos+1插入位置及之后的元素均后移一个位置
 mySeqList->element[i] = x;                           // 插入元素x
 return (1);
 }
}

// 功能:顺序表的删除(根据下标删除)
int deleteSeqList(MySeqList  mySeqList, int pos)
{
 if (pos < 0 || pos >= mySeqList->count)      // 不存在下标为pos的元素,注意下标范围是从0到count-1
 {
  printf("不存在指定下标!\n");
  return (0);
 }
 
 for (int i = pos; i < mySeqList->count - 1; ++i)
  mySeqList->element[i] = mySeqList->element[i + 1];   // 被删除元素之后的元素均前移一个位置
 --mySeqList->count;                                  // 元素个数减1
 return (1);
}
// 功能:根据元素值删除，实现顺序表的删除
int deleteSeqListByValue(MySeqList mySeqList, int id)
{
 int pos = locateSeqList(mySeqList, id);
 if (pos == -1)
 {
  printf("不存在指定下标!\n");
  return (0);
 }
 deleteSeqList(mySeqList, pos);
 return (1);
}
 

int deleteAllSeqListByValue(MySeqList mySeqList, int x)
{
 if (mySeqList->count == 0)
 {
  printf("该表为空!\n");
  return (0);
 }
 for (int i = 0; i != mySeqList->count; ++i)
 {
 
  if (mySeqList->element[i].id == x )
  {  
      deleteSeqListByValue(mySeqList,x);             // 删除x,删除后要将下标减少1
      i--;
  }
 }
 return (1);
}

int deleteAllVSeqList(MySeqList mySeqList, int x)
{
 if (mySeqList->count == 0)
 {
  printf("该表为空!\n");
  return (0);
 }
 int p = 0, q = 0;
 while (mySeqList->element[p].id != x && p != mySeqList->count - 1)  // 跳过开始不是x的元素
 {
  ++p;
  ++q;
 }
 for (; p != mySeqList->count - 1; ++p)                            // 遍历元素，不遍历最后一个元素(为了防止越界)
 {
  while (mySeqList->element[p].id == x && p != mySeqList->count - 1) // 如果元素是x，则游标p后移(用while处理多个x连续的情况)
  {
   ++p;
  }
  if (p != mySeqList->count - 1)
  {
   mySeqList->element[q] = mySeqList->element[p];
   ++q;
  }
 }
 if (mySeqList->element[mySeqList->count - 1].id != x)
 {
  mySeqList->element[q] = mySeqList->element[mySeqList->count - 1];
  ++q;
 }
 mySeqList->count = q;
 return (1);
}
 
// 功能：找出值为x的元素的前驱和后继的存储位置(即下标)
int locatePrePostSeqList(MySeqList mySeqList, int x, int &i, int &j)
{
 int k = locateSeqList(mySeqList, x);
 if (k == -1)
  return (0);
 if (k == 0)
  i = -1;
 else
  i = k - 1;
 if (k == mySeqList->count - 1)
  j = -1;
 else
  j = k + 1;
 return (1);
}
// 输出线性表的元素值
void printSeqList(MySeqList &mySeqList)
{
 
 for (int i = 0; i < mySeqList->count; ++i)  // 输出线性表的元素值
 {
   cout<< "学号:" << mySeqList->element[i].id << ",姓名:" << mySeqList->element[i].name << ",性别:" << mySeqList->element[i].sex ;
   cout<< "成绩:" << mySeqList->element[i].gread;
   cout<<endl;
 }
 cout << endl;
}

// 根据学生id,输出线性表的元素值
void printSeqListById(MySeqList &mySeqList,int id)
{
 
 for (int i = 0; i < mySeqList->count; ++i)  // 输出线性表的元素值
 {
   if (id == mySeqList->element[i].id)
   {
     cout<< "学号:" << mySeqList->element[i].id << ",姓名:" << mySeqList->element[i].name << ",性别:" << mySeqList->element[i].sex ;
     cout<< "成绩:" << mySeqList->element[i].gread;
     cout<<endl;
     break;
   }
 }
 
}
int main(int argc, char* argv[])
{

	MySeqList mySeqList = initSeqList(34); // 初始化一个长20的表
	//struct MySeqList mySeqList[20];
	//mySeqList[0] = (struct MySeqList){"peter1",22,"nan",4.2};
	

	L:
	   system("cls");
	   cout<< "                     ""学生成绩管理系统""                   "<<endl;
	   cout<<endl;
	   cout<<"            --------------------------------------- "<<endl;
	   cout<<       "    |   1.          添加学生信息            | "                        <<endl;
	   cout<<       "    |   2.          查找学生信息            | "                        <<endl;
	   cout<<       "    |   3.          删除学生信息            | "                        <<endl;
	   cout<<       "    |   4.          修改学生信息            | "                        <<endl;
	   cout<<       "    |   5.          退出学生系统            | "                        <<endl;
	   cout<<"            --------------------------------------- "<<endl;
	   int i;  
	   cout<<            "请选择一个操作(1-5):";
	   cin>>i;
	   if (i == 1)
	   {   
		 mySeqList->count = 1;
	  int iRc = 0;
	  while(true&&mySeqList->count<34)
	  {   
		   cout<<endl<<"请添加学生信息(输入*退出添加):"<<endl; 
		cout<<"姓名：";   
   
		cin>>mySeqList->element[iRc].name;
			  if (strcmp(mySeqList->element[iRc].name,"*") == 0)
		{ 
		 mySeqList->count--;  
		 goto L;
		}
		cout<<"学号: ";
		cin>>mySeqList->element[iRc].id;
		cout<<"性别: ";
		cin>>mySeqList->element[iRc].sex;
		   cout<<"成绩: ";
		cin>>mySeqList->element[iRc].gread;  
         
		cout << "成功添加学生成绩信息成绩。"<<endl;
			  printSeqList(mySeqList);
			  mySeqList->count++;
			  iRc++;
	  }
        
	   }
	   else if (i == 2)
	   {
	L4:
		   cout<<"请输入要查找的学生学号:"<<endl;
		int  sid;
		cin>>sid;
		if (locateSeqList(mySeqList,sid) != -1)
		{
		 cout<<"成功查询学号为"<<sid<<"的学生成绩。"<<endl;
			   printSeqListById(mySeqList,sid);
		}
		else
		{
		 cout<<"查询学生成绩错误,可能不存在学号为"<<sid<<"的学生."<<endl;
		}
		int iopselect;
		cout<<endl<<"还要继续查询吗？（按0返回主菜单,否则继续此操作。）"<<endl;
		cin>>iopselect;
		if (iopselect == 0)
		 goto L ;
		else
			goto L4;
  
	   }
	   else if (i == 3)
	   {
	L1:
		   cout<<"请输入要删除的学生学号:"<<endl;
		int stu_id;
		cin>>stu_id;
   
		   if (deleteSeqListByValue(mySeqList,stu_id) == 1)
			 cout<<"成功删除学生成绩。"<<endl;
		else
	   cout<<"删除学生成绩出错。"<<endl;
		printSeqList(mySeqList);
		int iop;
		cout<<endl<<"还要继续删除吗？（按0返回主菜单,否则继续此操作。）"<<endl;
		cin>>iop;
		if (iop == 0)
		 goto L ;
		else
			goto L1;
	   }
	   else if (i == 4)
	   {
	L3:
		cout<<"请输入要修改的学生学号:"<<endl;
		   int id;
		cin>>id;
		if(updateSeqList(mySeqList,id) ==1)
			 cout << "成功修改学生成绩信息成绩。"<<endl;
		else
			 cout << "修改学生成绩信息成绩出错。"<<endl;
		   printSeqList(mySeqList);
		int iselect;
		cout<<endl<<"还要继续修改吗？（按0返回主菜单,否则继续此操作。）"<<endl;
		cin>>iselect;
		if (iselect == 0)
		 goto L ;
		else
			goto L3;
	   }
	   else if (i == 5)
	   {  
		system("cls");
		cout<<"您已经出本系统，欢迎下次再使用."<<endl;
	   }
   
	 return 0;
}


*/