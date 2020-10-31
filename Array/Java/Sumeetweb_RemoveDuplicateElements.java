import java.util.Scanner;

class RemoveDuplicate {
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		int size;
		System.out.print("Enter size of array : ");
		size = in.nextInt();
		
		int[] arr = new int[size];
		System.out.println("Enter array values : ");
		
		int i;
		for(i = 0; i < size; i++)
		{
			arr[i] = in.nextInt();
		}
		
		int[] temp = new int[size];
		int top = -1;
		
		for(i = 0; i < size; i++)
		{
			if(top == -1)
			{
				top++;
				temp[top] = arr[i];
			}
			else
			{
				int j;
				for(j = 0; j <= top; j++)
				{
					if(arr[i] == temp[j])
					{
						break;
					}
				}
				
				if(j == top + 1)
				{
					top++;
					temp[top] = arr[i];
				}
			}
		}
		
		System.out.println("After removing duplicates, array is ");
		for(i = 0; i <= top; i++)
		{
			System.out.print(temp[i] + " ");
		}
		in.close();
	}
}
