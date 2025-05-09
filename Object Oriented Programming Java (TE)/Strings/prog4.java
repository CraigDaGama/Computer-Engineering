package Strings;

public class prog4 {
    public static void main(String args[])
    {   String h1="   weather ";
        String h2="reports";
        System.out.println("using functions concat(String)");
        System.out.println(h1.concat(h2));
        System.out.println(h1);
        System.out.println("without using trim() function");
        System.out.println("***"+h1+"***");
        System.out.println("using trim() function");
        System.out.println("***"+h1.trim()+"***");
    }
}
