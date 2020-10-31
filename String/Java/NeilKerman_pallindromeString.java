public class NeilKerman_pallindromeString { 
    static boolean isPalindrome(String str) 
    { 
        int i = 0, j = str.length() - 1; 
  
        while (i < j) { 
            if (str.charAt(i) != str.charAt(j)) 
                return false; 
            i++; 
            j--; 
        } 
        return true; 
    } 
    public static void main(String[] args) 
    { 
        String input_str = "malayalam"; 
  
        if (isPalindrome(input_str)) 
            System.out.print("The string is pallindromic"); 
        else
            System.out.print("The string is not pallindromic"); 
    } 
} 