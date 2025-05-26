package InterfacePrograms;
interface A
{ int a=3;
  void dispA();
}
class InterfaceExample1 implements A
{   public void dispA() 
    {   System.out.println("Interface A:"
            +a);
    }
    public static void main(String args[])
    {   InterfaceExample1 obj=
            new InterfaceExample1();
        obj.dispA();
    }
}

