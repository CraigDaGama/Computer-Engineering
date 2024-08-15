#include<iostream>
using namespace std;

int Sort(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (a[j]>a[j+1])
            swap(a[j],a[j+1]);
        }
    }
}

void BinarySearch(int a[], int key, int low, int high)
{
    int mid;
    for(int i=0;low<=high;i++)
    {
        mid=(low+high)/2;
        if (key==a[mid])
            {
                cout<<""<<key<<" found at index "<<mid<<endl;
                break;
            }
        else if (key<mid)
            high=mid-1;
        else if (key>mid)
            low=mid+1;
       else break;

    }
if(a[mid]!=key)
 cout<<""<<key<<" not found"<<endl;
}



int main()
{
    int a[100],key,low,high,mid,n,i;

    cout<<"Enter size of array"<<endl;
    cin>>n;

    cout<<"Enter the elements"<<endl;
    for (i=0;i<n;i++)
        cin>>a[i];

    Sort(a,n);
    for (i=0;i<n;i++)
    cout<<a[i]<<" ";

    cout<<endl;
    cout<<"Enter the element to be found"<<endl;
    cin>>key;
    low=0;
    high=n-1;

    BinarySearch(a, key, low, high);
    return 0;
}
