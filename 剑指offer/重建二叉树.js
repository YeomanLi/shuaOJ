/**
 * 题目描述
 * 输入某二叉树的前序遍历和中序遍历的结果，
 * 请重建出该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和
 * 中序遍历序列{4,7,2,1,5,3,8,6}，
 * 则重建二叉树并返回。
 * @param {*} pre 
 * @param {*} vin 
 */

/* function TreeNode(x) {
    this.val = x;
    this.left = null;
    this.right = null;
} */
function reConstructBinaryTree(pre, vin)
{
    // write code here
    //  先序遍历第一个就是根
    if (!pre || 0 == pre.length)  return null
    const rootVal = pre[0]
    let treeNode = {
      val: rootVal
    }
    //  在中序遍历中找到根节点的位置，来确定分片的index
    for (let i = 0; i < vin.length; ++i) {
      if (rootVal == vin[i]) {
        //  左子树
        treeNode.left = reConstructBinaryTree(pre.slice(1, i + 1), vin.slice(0, i))
        //  右子树
        treeNode.right = reConstructBinaryTree(pre.slice(i + 1), vin.slice(i + 1))
        break
      }
    }
    return treeNode
}