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

int BinarySearch(int a[], int key, int low, int high)
{
   int mid;
   if(low > high)
        cout<<""<<key<<" not found"<<endl;
   else
   {
    mid = (low + high)/2;
      if(a[mid]==key)
      {
        cout<<"Element found at index "<<mid;

      }else if(a[mid] > key)
      {
        BinarySearch(a, key, low, mid-1);
      }else
      {
        BinarySearch(a, key, mid+1, high);
      }
    }
}



int main()
{
    int a[100],key,low,high,mid,n,i,found;

    cout<<"Enter size of array"<<endl;
    cin>>n;

    cout<<"Enter the elements"<<endl;
    for (i=0;i<n;i++)
        cin>>a[i];

    Sort(a,n);
    for (i=0;i<n;i++)
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
