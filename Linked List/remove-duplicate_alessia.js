let deleteDuplicates = function(head) {
    let pointer = head;

    while(pointer && pointer.next){
        if(pointer.val == pointer.next.val){
            pointer.next = pointer.next.next;
        } else {
            pointer = pointer.next
        }
    }

    return head;
};