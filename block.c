//分块查找
//索引表
#define BLOCK_NUM 3

typedef struct
{
    int key;
    int link;
}INDEXTable;

// indexTable为索引表,x为原数组,N为数组大小，m为块大小
int blocksearch(INDEXTable *indexTable, int *x, int N, int m, int keyword)
{
    int L = N/m;    //块的数量
    int i = 0;
    int j = 0;

    while(i < L && indexTable[i].key < keyword) //顺序查找，寻找对应块的位置
        i++;
    if(i == L)
        return -1;
    else                                        //顺序查找，寻找数据在块中位置
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

    printf("\n\n\t数据38在10号位置%d\n\n",t+1);

}
