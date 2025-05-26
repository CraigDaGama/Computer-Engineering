package InterfacePrograms;

interface Z
{ void disp();
}
class K1 implements Z
{   public void disp()
    { System.out.println("helloworld");
    }
}
class J1 extends K1 implements Z
{   public void disp()
    { System.out.println("hellofffworld");
    }
}
public class InterfaceExample8 
{   public static void main(String args[])
    { J1 j=new J1();
        j.disp();
    }
}