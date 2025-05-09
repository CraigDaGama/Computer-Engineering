package ExceptionHandling;

public class exceptionDemo2 {
    public static void main(String args[])
    {   try
        {   int a =0;// args.length;
            System.out.println("a = " + a);
            int b = 42 / a;
            int c[] = { 1 };
            c[42] = 99;
        }
        catch(Exception e)
        {   System.out.println(e);}
    }
}
