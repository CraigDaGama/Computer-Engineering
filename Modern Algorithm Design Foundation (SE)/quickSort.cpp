#include<iostream>
using namespace std;

int partition(int a[],int lb,int ub)
{
    int pivot=a[lb];
    int start=lb;
    int end=ub;

    while(start<end)
    {
        while(a[start]<=pivot && start<end)
            start++;
        while(a[end]>pivot)
            end--;
        if(start<end)
            swap(a[start],a[end]);
    }
    swap(a[lb],a[end]);
    return end;
}


void QuickSort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        int loc=partition(a,lb,ub);
        QuickSort(a,lb,loc-1);
        QuickSort(a,loc+1,ub);
    }
}

int main()
{
    int n;

    cout<<"Enter the number of elements: ";
    cin>>n;

    int a[n];

    cout<<"Enter elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    QuickSort(a,0,n - 1);

    cout<<"Sorted array:"<<endl;
    for (int i=0;i<n;i++)
        cout<<a[i]<< " ";

    return 0;
}

