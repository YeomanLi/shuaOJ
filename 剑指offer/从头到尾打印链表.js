/*function ListNode(x){
    this.val = x;
    this.next = null;
}*/
function printListFromTailToHead(head)
{
    // write code here
    if (!head) return []
    const temp = []
    while(head.next) {
      temp.unshift(head.val)
      head = head.next
    }
    temp.unshift(head.val)
    return temp
}