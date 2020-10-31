import java.util.Scanner;

class devmohit_Palindrome {
    static boolean checkPalindrome(String s) {
        int low = 0, high = s.length() - 1;
        while (low <= high) {
            if (s.charAt(low) == s.charAt(high)) {
                low++;
                high--;
            } else
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.next();
        if (checkPalindrome(input)) {
            System.out.println(input + " is Palindrome");
        } else {
            System.out.println(input + " is not a Palindrome");
        }
    }
}