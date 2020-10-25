import java.util.Scanner;

public interface Stack {
    String pop();
    void push(String e);
    String pick();
    int size();
    void display();
    boolean isEmpty();
}

class ArrayStack implements Stack {
	
	private final String[] arr;
	private int top;
	
	public ArrayStack() {
		arr = new String[100];
		top = -1;
	}
	
	public ArrayStack(int capacity) {
		arr = new String[capacity];
		top = -1;
	}
	
	
	@Override
	public String pop() {
		String temp = arr[top];
		arr[top] = null;
		top --;
		return temp;
	}

	@Override
	public void push(String e) {
		top ++;
		arr[top]=e;
		
	}

	@Override
	public String pick() {
		return arr[top];
	}

	@Override
	public int size() {
	
		return top+1;
	}

	@Override
	public void display() {
		for(int i=0;i<=arr.length-1;i++) {
			System.out.print(arr[i]+",");
		}
		
	}

	@Override
	public boolean isEmpty() {
		return top == -1;
	}
   
	
}
class ArrayStackDemo {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter elements in the stack:");
		int elementsNo = sc.nextInt();


		ArrayStack st1 = new ArrayStack(elementsNo);
		System.out.println("Enter names in the stack:");
		
			for(int i=0;i<=elementsNo-1;i++) {
			st1.push(sc.next());
			}

		System.out.println(st1.size());
		System.out.println(st1.pick());
		System.out.println(st1.isEmpty());
		st1.pop();
		st1.display();


	}

}
