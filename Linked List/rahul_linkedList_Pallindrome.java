public class Solution {
    ListNode left;
 
    public boolean isPalindrome(ListNode head) {
        left = head;
 
        boolean result = helper(head);
        return result;
    }
 
    public boolean helper(ListNode right){
 
        //stop recursion
        if (right == null)
            return true;
 
        //if sub-list is not palindrome,  return false
        boolean x = helper(right.next);
        if (!x)
            return false;
 
        //current left and right
        boolean y = (left.val == right.val);
 
        //move left to next
        left = left.next;
 
        return y;
    }
}