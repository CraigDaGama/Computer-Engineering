package Strings;

public class prog3 {
    public static void main(String args[])
    {   String h1="The weather is awful."
            + "The weather reports were recorded and mailed";
System.out.println("using function replaceAll(String,String)");
        System.out.println(h1.replaceAll("weather","climate"));
System.out.println("using function replaceFirst(String,String)");
        System.out.println(h1.replaceFirst("weather","climate"));
        String h2="23,24,35,67,67,34,78";
        
System.out.println("using function replace(char,char)");
        System.out.println(h2.replace(',',' '));
    }
}
