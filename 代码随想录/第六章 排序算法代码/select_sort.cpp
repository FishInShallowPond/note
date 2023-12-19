//// 选择排序
//#include<iostream>
//#include<time.h>
//using namespace std;
//
//void select_sort(int* arr, int l, int r)
//{
//	for (int i = l, I = r - 1; i < I; i++)  // i 为待排序区与已排序区的边界
//	{
//		int index = i; //记录待排序区中最小元素的索引
//		for (int j = i + 1; j < r; j++)
//		{
//			if (arr[j] < arr[index]) index = j; //更新最小元素
//			swap(arr[i], arr[j]); //将待排序区中的最小元素移到首位
//		}
//	}
//	return;
//}
//
//
//int main()
//{
//	int* arr = getRandData(Small_Data_N);
//	TEXT(select_sort, arr, Small_Data_N);
//	free(arr);
//	return;
//}