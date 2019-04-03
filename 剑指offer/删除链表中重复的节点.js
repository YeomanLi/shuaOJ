function ListNode(x){
    this.val = x;
    this.next = null;
}

function deleteDuplication(pHead)
{
  // write code here
  if (null == pHead)  return null
  if (null != pHead && null == pHead.next)  return pHead
  if (pHead.val == pHead.next.val) {
    let cur = pHead.next.next
    while (null != cur && cur.val == pHead.val)  {
    // while (cur.val == pHead.val)  {
      cur = cur.next
    }
    return deleteDuplication(cur)
  } else {
    let cur = pHead.next
    pHead.next = deleteDuplication(cur)
    return pHead
  }
}

// test
const pHead = new ListNode(1)
const arr = [2, 3, 3, 4, 4, 5]
let p = pHead
arr.forEach(item => {
  p.next = new ListNode(item)
  p = p.next
})
let testHead = deleteDuplication(pHead)

p = testHead
while (p) {
  console.log(p)
  p = p.next
}
p = null
