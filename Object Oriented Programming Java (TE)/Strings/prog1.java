package Strings;

public class prog1 {
    public static void main(String args[])
     {     String s1="heLLo";
           String s2="hello";
           String s3=new String("heLLo");
           System.out.println("Uppercase:"+s1.toUpperCase());
           System.out.println("lowercase:"+s1.toLowerCase());
           System.out.println("using equals:"+s1.equals(s2));
System.out.println("using equalsIgnoreCase:"+s1.equalsIgnoreCase(s2));
           int k=s1.compareTo(s3);
           if(k>1){    System.out.println("s1>s3");}
           else if(k==0)
           {    System.out.println("s1=s3");}
           else
           {    System.out.println("s1<s3");}
     }
}
