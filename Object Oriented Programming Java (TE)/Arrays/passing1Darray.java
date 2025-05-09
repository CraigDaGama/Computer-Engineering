package Arrays;

public class passing1Darray {
    static void multiplyScalar(int a[],int x)
    {   for(int i=0;i<a.length;i++)
        {   a[i]*=x;    }
    }
    public static void main(String args[])
    {   int a[]={1,2,3,4};
        System.out.println("initial array\n");
        for(int i=0;i<a.length;i++)
        {   System.out.print(a[i]+"\t");}
        multiplyScalar(a,3);
        System.out.println("\nAfter multiplying Scalar: array\n");
        for(int i=0;i<a.length;i++)
        {   System.out.print(a[i]+"\t");}
    }
}
