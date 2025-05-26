package InterfacePrograms;

interface Showable
{   void show();  
    interface Message
    {  void msg();  }  
}  
  
class TestNestedInterface1 implements Showable.Message
{   public void msg()
    {System.out.println("nested interface");}  
    public static void main(String args[])
    {   Showable.Message message=new TestNestedInterface1();//upcasting here  
        message.msg();  
    }  
}  

