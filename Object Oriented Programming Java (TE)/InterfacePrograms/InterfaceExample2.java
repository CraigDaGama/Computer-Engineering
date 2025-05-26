package InterfacePrograms;

interface Callback 
{	void callback(int param);	}

class Client implements Callback 
{   public void callback(int p) 
    {	System.out.println("callback called with " + p);}
    void nonIfaceMeth() 
    {	System.out.println("Classes that implement "
                + "interfaces " 
                +"may also define other members, too.");
    }
}
class AnotherClient implements Callback 
{   public void callback(int p) 
    {	System.out.println("Another version of callback"); 
        System.out.println("p squared is " + (p*p));
    }
}
public class InterfaceExample2 
{   public static void main(String args[])
    {   Callback c = new Client(); 
        AnotherClient ob = 
                new AnotherClient();
        c.callback(42); 
        ((Client)c).nonIfaceMeth();
        c = ob; // c now refers to AnotherClient object 
        c.callback(42);
    }
}