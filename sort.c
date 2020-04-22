#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int resource[6] = {5,4,3,2,1,10};
int trsource[6] = {0};

/*
name: 打印数组
pArr: 数组指针
arrLen: 数组长度
pTarr: 排序后的数组指针
*/
void printArray(int *pArr,int arrLen)
{
    int k;
    for(k=0;k<arrLen;k++)
    {
        printf("array[%d]=%d\n",k,pArr[k]);
    }
}

/*
name: 冒泡排序
pArr: 数组指针
arrLen: 数组长度
pTarr: 排序后的数组指针
*/
bool bubbleSort(int *pArr,int arrLen,int *pTarr)
{
    int i,j;
    int temp = 0;  
    int *Arr = NULL;

    //检查
    if(pArr == NULL || pTarr == NULL)
    {
        return false;
    }

    Arr = (int *)malloc(arrLen*sizeof(int));
     Arr = pArr;
    for(i=0;i<arrLen-1;i++)
    {
        for(j=0;j<arrLen-1;j++)
        {
            if(Arr[j]>Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp; 
            }
        }
    }
    memcpy(pTarr,Arr,arrLen*sizeof(int));
    Arr = NULL;
    free(Arr);
    return true;
}



int main(void)
{
    //冒泡排序
    bubbleSort(resource,sizeof(resource)/sizeof(resource[0]),trsource);
    //打印数组
    printArray(trsource,sizeof(trsource)/sizeof(trsource[0]));

    return 0;
}