// 构造栈
function Stack () {
  this.items = []
}

Stack.prototype = {
  constructor: Stack,
  push: function(item) {
    this.items.push(item)
    return this.items
  },
  pop: function() {
    return this.items.pop()
  },
  length: function() {
    return this.items.length
  },
  print: function () {
    console.log(this.items)
  },
  isEmpty: function () {
    return this.items.length == 0
  }
}

const inStack = new Stack()
const outStack = new Stack()

function push(node)
{
  // write code here
  inStack.push(node)
}
function pop()
{
  // write code here
  if (outStack.isEmpty()) {
    while (!inStack.isEmpty()) {
      outStack.push(inStack.pop())
    }
  }
  return outStack.pop()
}
