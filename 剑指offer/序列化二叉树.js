/* function TreeNode(x) {
    this.val = x;
    this.left = null;
    this.right = null;
} */

const res = []
function Serialize(pRoot)
{
  // write code here
  if (!pRoot) res.push('#')
  else {
    res.push(pRoot.val)
    Serialize(pRoot.left)
    Serialize(pRoot.right)
  }
  return res
}

function Deserialize(s)
{
  // write code here
  let node = null
  if (!s.length)  return null
  const number = s.shift()
  if ('number' === typeof number) {
    node = new TreeNode(number)
    node.left = Deserialize(s)
    node.right = Deserialize(s)
  }
  return node
}