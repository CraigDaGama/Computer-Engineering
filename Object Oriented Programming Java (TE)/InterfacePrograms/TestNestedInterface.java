package InterfacePrograms;

class A3
{   interface Message
    {  void msg();  }  
}  
  
class TestNestedInterface2 implements A3.Message
{  public void msg()
   {System.out.println("nested interface");}  
  
   public static void main(String args[]) 
   {  A3.Message message=new TestNestedInterface2();//upcasting here  
      message.msg();  
   }  
}
