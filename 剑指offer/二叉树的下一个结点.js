/**
 * 拥有右子树，那么找到右子树的最左节点
 * 是父节点的左子树，那么下一个就是父节点
 * 是父节点右子树，那么退到父节点回溯重复判断
 * @param {*} pNode 
 */
/*function TreeLinkNode(x){
    this.val = x;
    this.left = null;
    this.right = null;
    this.next = null;
}*/
function GetNext(pNode)
{
    // write code here
    if (pNode == null) return null
    if (pNode.right) {
      pNode = pNode.right
      while(pNode.left) pNode = pNode.left
      return pNode
    }
    while (pNode.next) {
      if (pNode.next.left == pNode) return pNode.next
      pNode = pNode.next
    }
    return null
}