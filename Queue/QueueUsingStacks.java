import java.util.*;
class QueueUsingStacks
{
    static Stack<Integer> st1=new Stack<>();
    static Stack<Integer> st2=new Stack<>();
    static void enQueue(int x)
    {
        while(!st1.isEmpty())
        {
            st2.push(st1.pop());
        }
        st1.push(x);
        
        while(!st2.isEmpty())
        {
            st1.push(st2.pop());
        }
    }
    static int deQueue()
    {
        if(st1.isEmpty())
        {
            System.out.println("Queue is Empty");
            //return 0;
            System.exit(0);
        }
        
        int x=st1.peek();
        st1.pop();
        return x;
        
        
    }
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        for(int i=0;i<n;i++)
        {
            int a=sc.nextInt();
            enQueue(a);
            System.out.print(deQueue()+" ");
        }
    }
    
    
}

