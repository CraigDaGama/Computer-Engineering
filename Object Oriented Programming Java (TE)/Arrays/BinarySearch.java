package Arrays;

public class BinarySearch {
    static void searchElement(int a[],int x)
    {   int low=0,high=a.length-1;
        int mid=-1;
        while(low<=high)
        {   mid=(low+high)/2;
            if(x==a[mid]) 
            {   System.out.println("Element "+x
                    +" found at position: "+mid);break;}
            else if(x>a[mid])  { low=mid+1;}
            else
            {   high=mid-1;}
        }  
        if(low>high){System.out.println("element not found");}
    }
    public static void main(String args[])
    {   int arr[]={2,4,5,7};
        searchElement(arr,7);
    }
}
