/*
2.1、初始化数组，创建大顶堆。
	1. 大顶堆的创建从下往上比较，不能直接用无序数组从根节点比较，否则有的不符合大顶堆的定义。
2.2、交换根节点和倒数第一个数据，现在倒数第一个数据就是最大的。
2.3、重新建立大顶堆。
	1. 因为只有 array[0]改变，其它都符合大顶堆的定义，所以可以根节点 array[0]重新建立。
2.4、重复2.2,2.3的步骤，直到只剩根节点
*/
#include<iostream>
#include<vector>
using namespace std;
 
// 递归方式构建大根堆(len是arr的长度，index是第一个非叶子节点的下标)
void adjust(vector<int> &arr, int len, int index)
{
    int left = 2 * index + 1; // index的左子节点
    int right = 2 * index + 2;// index的右子节点
 
    int maxIdx = index;
    if(left < len && arr[left] > arr[maxIdx]) maxIdx = left;
    if(right < len && arr[right] > arr[maxIdx]) maxIdx = right;
 
    if(maxIdx != index)
    {
        swap(arr[maxIdx], arr[index]);
        adjust(arr, len, maxIdx);
    }
 
}
 
// 堆排序
void heapSort(vector<int> &arr, int size)
{
    // 构建大根堆（从最后一个非叶子节点向上）
    for(int i = size/2 - 1; i >= 0; i--)
    {
        adjust(arr, size, i);
    }
 
    // 调整大根堆
    for(int i = size - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);           // 将当前最大的放置到数组末尾
        adjust(arr, i, 0);              // 将未完成排序的部分继续进行堆排序
    }
}
 
int main()
{
    vector<int> arr = {8, 1, 14, 3, 21, 5, 7, 10};
    heapSort(arr, arr.size());
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
