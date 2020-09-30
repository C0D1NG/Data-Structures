import java.util.Arrays; 
  
public class NeilKerman_largestElement { 
    public static void main(String[] args){ 
        int array[] = {15, 20, 10, 64, 256, 100, 2, 0, 8, 15}; //Array from where the largest element will be picked
        int max_element = Arrays.stream(array).max().getAsInt(); //Using Array Streams to find the largest element
        System.out.println("Largest element in the array is " + max_element); //Output
    } 
} 

//Code by NeilKerman