package Strings;

public class prog2 {
    public static void main(String args[])
    {  // String h1="DML is :";
        String h2="data,manipulation,language,"
                + "data,markup,language";
        //System.out.println(h1);
        for(String options:h2.split(","))
        {System.out.println("token-->"+options);}
    }
}
