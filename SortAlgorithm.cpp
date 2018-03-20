#include <iostream>  
#include <vector>  
using namespace std;  
*********************************************************************************************************
//QuickSort  
//from low to high  
//一趟QuickSort  
int Partition(vector<int> &L, int low, int high)  
{  
    int pivotkey = L[low];  
    while (low < high)//以前后指针相遇作为一次QuickSort结束的标志  
    {  
        while (low < high && pivotkey <= L[high])//由后到前搜索  
            --high;  
        L[low] = L[high];  
        while (low < high && pivotkey >= L[low])//由前到后搜索  
            ++low;  
        L[high] = L[low];  
    }  
    L[low] = pivotkey;  
    return low;  
}  
//递归式实现  
void QSort(vector<int> &L, int low, int high)  
{  
    if (low < high)  
    {  
        int pivotloc = Partition(L, low, high);  
        QSort(L, low, pivotloc - 1);  
        QSort(L, pivotloc + 1, high);  
    }  
}  
void QuickSort(vector<int> &L)  
{  
    QSort(L, 0, L.size()-1);//数据从L[0]开始，L[L.size()-1]结束  
}  
*********************************************************************************************************  
//BubbleSort  
//from low to high  
void BubbleSort(vector<int> &L)  
{  
    for (int i = 0; i < L.size(); ++i)  
    {  
        for (size_t j = 0; j < L.size()-1-i; ++j)  
        {  
            if (L[j] > L[j+1])  
            {  
                int tem = L[j];  
                L[j] = L[j+1];  
                L[j+1] = tem;  
            }  
        }  
    }  
}  
*********************************************************************************************************
//SelectSort  
//from low to high  
void SelectSort(vector<int> &L)  
{  
    for (size_t i = 0; i < L.size(); i++)  
    {  
        int min = i;  
        for (size_t j = i+1; j < L.size(); j++)  
        {  
            if (L[min] >L[j])  
            {  
                min = j;  
            }  
        }  
        int tem = L[i];  
        L[i] = L[min];  
        L[min] = tem;  
    }  
}  
*********************************************************************************************************
//HeapSort  
//from high to low  
void HeapAdjust(vector<int>&L, int s, int m)
{
	int rc = L[s-1];//rc:非终端节点
	for (size_t i = 2*s; i <= m; i *= 2)
	{
		if (i < m && L[i-1] > L[i]) ++i;
		if (rc < L[i-1]) break;
		L[s-1] = L[i-1];
		s = i;
	}
	L[s-1] = rc;
}
void HeapSort(vector<int>&L)
{
	//从最后一个非终端节点开始构建最小堆
	for (size_t i =	L.size()/2; i > 0; --i)
		HeapAdjust(L, i, L.size());
	//依次调整剩余元素成为一个新的堆;同时元素从大到小排列
	for (size_t i = L.size(); i > 1; --i)
	{
		int tmp = L[0];
		L[0] = L[i-1];
		L[i - 1] = tmp;
		HeapAdjust(L, 1, i - 1);
	}
}
*********************************************************************************************************
//HeapSort<template版>  
//from low to high  
template <typename T>
void HeapAdjust(vector<T>&L, size_t s, size_t m)
{
	T rc = L[s - 1];
	for (size_t i = 2*s; i <= m; i *= 2)
	{
		if (i < m && L[i - 1] < L[i]) ++i;
		if (L[i-1] < rc) break;
		L[s - 1] = L[i-1];
		s = i;
	}
	L[s-1] = rc;
}
template <typename T>
void HeapSort(vector<T>&L)
{
	for (size_t i = L.size() / 2; i > 0; --i)
		HeapAdjust(L, i, L.size());
	for (size_t i = L.size(); i > 1; --i)
	{
		T tmp = L[0];
		L[0] = L[i - 1];
		L[i - 1] = tmp;
		HeapAdjust(L, 1, i - 1);
	}
}
