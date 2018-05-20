//�ֿ����
//������
#define BLOCK_NUM 3

typedef struct
{
    int key;
    int link;
}INDEXTable;

// indexTableΪ������,xΪԭ����,NΪ�����С��mΪ���С
int blocksearch(INDEXTable *indexTable, int *x, int N, int m, int keyword)
{
    int L = N/m;    //�������
    int i = 0;
    int j = 0;

    while(i < L && indexTable[i].key < keyword) //˳����ң�Ѱ�Ҷ�Ӧ���λ��
        i++;
    if(i == L)
        return -1;
    else                                        //˳����ң�Ѱ�������ڿ���λ��
    {
        j = indexTable[i].link;
        for(j; j<indexTable[i].link + m;j++)
            if(x[j] == keyword)
                return j;
    }
    return -1;
}

void main()
{
    INDEXTable indexTable[3];
    int t;

    indexTable[0].key = 22;
    indexTable[1].key = 48;
    indexTable[2].key = 86;

    indexTable[0].link = 1-1;
    indexTable[1].link = 7-1;
    indexTable[2].link = 13-1;

    int x[]={22,12,13,8,9,20,
             33,42,44,38,24,48,
             60,58,74,49,86,53};

    t = blocksearch(indexTable,x,18,6,38);

    printf("\n\n\t����38��10��λ��%d\n\n",t+1);

}
