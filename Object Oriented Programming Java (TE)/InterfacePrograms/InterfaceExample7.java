package InterfacePrograms;

interface X1
{   int x=4;
    void disp();
}
interface Y1 extends X1
{ int y=5;
    void disp();
}
public class InterfaceExample7 
implements Y1,X1
{    public void disp()
    { System.out.println("fgf");}
    public static void main(String args[])
    {   Y1 yobj=new InterfaceExample7();
        yobj.disp();
    }
}
