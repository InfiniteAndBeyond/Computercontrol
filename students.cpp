
/*

#include <iostream>  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
using namespace std;  
struct student  
{   
  int id;  // ѧ��  
  char name[30]; // ����  
  char sex[2];  // �Ա�   
  float gread; // �ɼ�  
};  
typedef struct student DataType; //  ָ��struct studentΪDataType  
struct SeqList  
{  
 int MAX;     // ˳��������Ԫ�صĸ���  
 int count;         // ������Ա���Ԫ�صĸ���count <= MAXLENGTH  
 DataType* element;  // element[0], element[1], ..., element[n - 1]������Ա��е�Ԫ��  
};  
typedef struct SeqList *MySeqList;   
// ��ʼ����������˳���  
MySeqList initSeqList(int m);  
// �ж����Ա��Ƿ�Ϊ��  
int isEmptySeqList(MySeqList mySeqList);  
// ��˳�������ĳԪ�ص��±�  
int locateSeqList(MySeqList mySeqList, int id);  
// ��˳������޸�ֵ  
int updateSeqList(MySeqList mySeqList, int id);  
// ˳���Ĳ���(Ԫ��p֮ǰ����)  
int insertPreSeqList(MySeqList mySeqList, int p, DataType x);  
// ˳���Ĳ���(Ԫ��p֮�����)  
int insertNextSeqList(MySeqList mySeqList, int p, DataType x);  
// ˳����ɾ��(�����±�ɾ��)  
int deleteSeqList(MySeqList mySeqList, int p);  
// ˳����ɾ��(����Ԫ��ֵɾ��)  
int deleteSeqListByValue(MySeqList mySeqList, int id);  
// ��˳����ʾ�����Ա�����  
int reverseSeqList(MySeqList mySeqList);  
  
int deleteAllVSeqList(MySeqList mySeqList, DataType x);  
// ����±�Ϊi��Ԫ�ص�ǰ���ͺ��  
int findPrePostSeqList(MySeqList mySeqList, int i, DataType &m, DataType &n);  
// ˳���ʵ�ֲ��֣��ҳ�ֵΪx��Ԫ�ص�ǰ���ͺ�̵Ĵ洢λ��(���±�)  
int locatePrePostSeqList(MySeqList mySeqList, DataType x, int &i, int &j);  
// ������Ա��Ԫ��ֵ  
void printSeqList(MySeqList &mySeqList);  
// ����ѧ��id,������Ա��Ԫ��ֵ  
void printSeqListById(MySeqList &mySeqList,int id);  
// ��˳������޸�ֵ  
int updateSeqList(MySeqList mySeqList, int id)   //ѧ����Ϣ����  
{  
 int iRc = locateSeqList(mySeqList, id);  
 if (iRc == -1)  
 {  
  printf("������ָ���±�!\n");  
  return (0);  
 }  
   
 cout<<"ѧ��   ����   �Ա�    �ɼ� "<<endl;  
 cin>>mySeqList->element[iRc].id>>mySeqList->element[iRc].name>>mySeqList->element[iRc].sex>>mySeqList->element[iRc].gread;  
  return 1;  
}  

// ����: ������˳���
MySeqList initSeqList(int m)
{
 MySeqList mySeqList = (MySeqList)malloc(sizeof(struct SeqList)); // �����ڴ�ռ�
 if (mySeqList != NULL)
 {
  mySeqList->element = (DataType*)malloc(sizeof(DataType) * m);   // Ϊ�����Ԫ�ط���m��DataType��С���ڴ�ռ�,�൱�ڳ�ʼ����һ������Ϊm������
  if (mySeqList->element)
  {
   mySeqList->MAX = m;  // ���������Ԫ�أ�MAXLENGTHΪ���Ԫ�صĸ���
   mySeqList->count = 0;  // �ձ���Ϊ0
   return (mySeqList);
  }
  else
   free(mySeqList);        // �ǵ�Ҫ�ֶ��ͷſռ䣬��������ײ����ڴ�й©
 }
 printf("�ڴ�ռ䲻�㣬��ر�һЩ����Ȼ������!\n"); // �洢����ʧ�ܣ���ʾ�ռ䲻��
 return NULL;
}
// ����: �ж����Ա��Ƿ�Ϊ��
int isEmptySeqList(MySeqList mySeqList)
{
 return (mySeqList->count ==0);
}
// ����:��˳�������ĳԪ�ص��±�,û�в��ҵ����򷵻�-1
int locateSeqList(MySeqList mySeqList, int id)
{
 for (int i = 0; i < mySeqList->count; ++i)
  if (mySeqList->element[i].id == id)             // ����һ��Ԫ��x,���ҵ��󷵻��±�i
   return (i);
 return (-1);
}
// ����:˳����pos�±�ǰ�����,����ɹ�����1,ʧ�ܷ���0
int insertPreSeqList(MySeqList mySeqList, int pos, DataType x)
{
 ++mySeqList->count;
 if (mySeqList->count > mySeqList->MAX)      // ���
 {
  --mySeqList->count;    
  printf("����������!\n");
  return (0);
 }
 if (pos < 0 || pos >= mySeqList->count)         // �������±�Ϊpos��Ԫ��
 {
  --mySeqList->count;
  printf("������ָ���±�!\n");
  return (0);
 }
 for (int i = mySeqList->count - 1; i != pos; --i)
  {mySeqList->element[i] = mySeqList->element[i - 1]; // ����λ�ü�֮���Ԫ�ؾ�����һ��λ��
 mySeqList->element[i] = x;                          // ����Ԫ��x
 return (1);
 }
}
// ����:˳����pos�±�������,����ɹ�����1,ʧ�ܷ���0
int insertNextSeqList(MySeqList mySeqList, int pos, DataType x)
{
 if (pos < 0 || pos >= mySeqList->count)
 {
  printf("������ָ���±�!\n");
  return (0);
 }
 ++mySeqList->count;
 if (mySeqList->count >= mySeqList->MAX)
 {
  --mySeqList->count;
  printf("����������!\n");
  return (0);
 }
 
 for (int i = mySeqList->count - 1; i != pos + 1; --i)
  {mySeqList->element[i] = mySeqList->element[i - 1];  // ͬ���أ���pos+1����λ�ü�֮���Ԫ�ؾ�����һ��λ��
 mySeqList->element[i] = x;                           // ����Ԫ��x
 return (1);
 }
}

// ����:˳����ɾ��(�����±�ɾ��)
int deleteSeqList(MySeqList  mySeqList, int pos)
{
 if (pos < 0 || pos >= mySeqList->count)      // �������±�Ϊpos��Ԫ��,ע���±귶Χ�Ǵ�0��count-1
 {
  printf("������ָ���±�!\n");
  return (0);
 }
 
 for (int i = pos; i < mySeqList->count - 1; ++i)
  mySeqList->element[i] = mySeqList->element[i + 1];   // ��ɾ��Ԫ��֮���Ԫ�ؾ�ǰ��һ��λ��
 --mySeqList->count;                                  // Ԫ�ظ�����1
 return (1);
}
// ����:����Ԫ��ֵɾ����ʵ��˳����ɾ��
int deleteSeqListByValue(MySeqList mySeqList, int id)
{
 int pos = locateSeqList(mySeqList, id);
 if (pos == -1)
 {
  printf("������ָ���±�!\n");
  return (0);
 }
 deleteSeqList(mySeqList, pos);
 return (1);
}
 

int deleteAllSeqListByValue(MySeqList mySeqList, int x)
{
 if (mySeqList->count == 0)
 {
  printf("�ñ�Ϊ��!\n");
  return (0);
 }
 for (int i = 0; i != mySeqList->count; ++i)
 {
 
  if (mySeqList->element[i].id == x )
  {  
      deleteSeqListByValue(mySeqList,x);             // ɾ��x,ɾ����Ҫ���±����1
      i--;
  }
 }
 return (1);
}

int deleteAllVSeqList(MySeqList mySeqList, int x)
{
 if (mySeqList->count == 0)
 {
  printf("�ñ�Ϊ��!\n");
  return (0);
 }
 int p = 0, q = 0;
 while (mySeqList->element[p].id != x && p != mySeqList->count - 1)  // ������ʼ����x��Ԫ��
 {
  ++p;
  ++q;
 }
 for (; p != mySeqList->count - 1; ++p)                            // ����Ԫ�أ����������һ��Ԫ��(Ϊ�˷�ֹԽ��)
 {
  while (mySeqList->element[p].id == x && p != mySeqList->count - 1) // ���Ԫ����x�����α�p����(��while������x���������)
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
 
// ���ܣ��ҳ�ֵΪx��Ԫ�ص�ǰ���ͺ�̵Ĵ洢λ��(���±�)
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
// ������Ա��Ԫ��ֵ
void printSeqList(MySeqList &mySeqList)
{
 
 for (int i = 0; i < mySeqList->count; ++i)  // ������Ա��Ԫ��ֵ
 {
   cout<< "ѧ��:" << mySeqList->element[i].id << ",����:" << mySeqList->element[i].name << ",�Ա�:" << mySeqList->element[i].sex ;
   cout<< "�ɼ�:" << mySeqList->element[i].gread;
   cout<<endl;
 }
 cout << endl;
}

// ����ѧ��id,������Ա��Ԫ��ֵ
void printSeqListById(MySeqList &mySeqList,int id)
{
 
 for (int i = 0; i < mySeqList->count; ++i)  // ������Ա��Ԫ��ֵ
 {
   if (id == mySeqList->element[i].id)
   {
     cout<< "ѧ��:" << mySeqList->element[i].id << ",����:" << mySeqList->element[i].name << ",�Ա�:" << mySeqList->element[i].sex ;
     cout<< "�ɼ�:" << mySeqList->element[i].gread;
     cout<<endl;
     break;
   }
 }
 
}
int main(int argc, char* argv[])
{

	MySeqList mySeqList = initSeqList(34); // ��ʼ��һ����20�ı�
	//struct MySeqList mySeqList[20];
	//mySeqList[0] = (struct MySeqList){"peter1",22,"nan",4.2};
	

	L:
	   system("cls");
	   cout<< "                     ""ѧ���ɼ�����ϵͳ""                   "<<endl;
	   cout<<endl;
	   cout<<"            --------------------------------------- "<<endl;
	   cout<<       "    |   1.          ���ѧ����Ϣ            | "                        <<endl;
	   cout<<       "    |   2.          ����ѧ����Ϣ            | "                        <<endl;
	   cout<<       "    |   3.          ɾ��ѧ����Ϣ            | "                        <<endl;
	   cout<<       "    |   4.          �޸�ѧ����Ϣ            | "                        <<endl;
	   cout<<       "    |   5.          �˳�ѧ��ϵͳ            | "                        <<endl;
	   cout<<"            --------------------------------------- "<<endl;
	   int i;  
	   cout<<            "��ѡ��һ������(1-5):";
	   cin>>i;
	   if (i == 1)
	   {   
		 mySeqList->count = 1;
	  int iRc = 0;
	  while(true&&mySeqList->count<34)
	  {   
		   cout<<endl<<"�����ѧ����Ϣ(����*�˳����):"<<endl; 
		cout<<"������";   
   
		cin>>mySeqList->element[iRc].name;
			  if (strcmp(mySeqList->element[iRc].name,"*") == 0)
		{ 
		 mySeqList->count--;  
		 goto L;
		}
		cout<<"ѧ��: ";
		cin>>mySeqList->element[iRc].id;
		cout<<"�Ա�: ";
		cin>>mySeqList->element[iRc].sex;
		   cout<<"�ɼ�: ";
		cin>>mySeqList->element[iRc].gread;  
         
		cout << "�ɹ����ѧ���ɼ���Ϣ�ɼ���"<<endl;
			  printSeqList(mySeqList);
			  mySeqList->count++;
			  iRc++;
	  }
        
	   }
	   else if (i == 2)
	   {
	L4:
		   cout<<"������Ҫ���ҵ�ѧ��ѧ��:"<<endl;
		int  sid;
		cin>>sid;
		if (locateSeqList(mySeqList,sid) != -1)
		{
		 cout<<"�ɹ���ѯѧ��Ϊ"<<sid<<"��ѧ���ɼ���"<<endl;
			   printSeqListById(mySeqList,sid);
		}
		else
		{
		 cout<<"��ѯѧ���ɼ�����,���ܲ�����ѧ��Ϊ"<<sid<<"��ѧ��."<<endl;
		}
		int iopselect;
		cout<<endl<<"��Ҫ������ѯ�𣿣���0�������˵�,��������˲�������"<<endl;
		cin>>iopselect;
		if (iopselect == 0)
		 goto L ;
		else
			goto L4;
  
	   }
	   else if (i == 3)
	   {
	L1:
		   cout<<"������Ҫɾ����ѧ��ѧ��:"<<endl;
		int stu_id;
		cin>>stu_id;
   
		   if (deleteSeqListByValue(mySeqList,stu_id) == 1)
			 cout<<"�ɹ�ɾ��ѧ���ɼ���"<<endl;
		else
	   cout<<"ɾ��ѧ���ɼ�����"<<endl;
		printSeqList(mySeqList);
		int iop;
		cout<<endl<<"��Ҫ����ɾ���𣿣���0�������˵�,��������˲�������"<<endl;
		cin>>iop;
		if (iop == 0)
		 goto L ;
		else
			goto L1;
	   }
	   else if (i == 4)
	   {
	L3:
		cout<<"������Ҫ�޸ĵ�ѧ��ѧ��:"<<endl;
		   int id;
		cin>>id;
		if(updateSeqList(mySeqList,id) ==1)
			 cout << "�ɹ��޸�ѧ���ɼ���Ϣ�ɼ���"<<endl;
		else
			 cout << "�޸�ѧ���ɼ���Ϣ�ɼ�����"<<endl;
		   printSeqList(mySeqList);
		int iselect;
		cout<<endl<<"��Ҫ�����޸��𣿣���0�������˵�,��������˲�������"<<endl;
		cin>>iselect;
		if (iselect == 0)
		 goto L ;
		else
			goto L3;
	   }
	   else if (i == 5)
	   {  
		system("cls");
		cout<<"���Ѿ�����ϵͳ����ӭ�´���ʹ��."<<endl;
	   }
   
	 return 0;
}


*/