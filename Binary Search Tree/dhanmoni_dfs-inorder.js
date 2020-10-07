class Node {
  constructor(val, right = null, left = null) {
    this.val = val;
    this.left = left;
    this.right = right;
  }
}

class BST {
  constructor() {
    this.root = null;
  }

  //INSERT USING WHILE LOOP OR ANY OTHER LOOP :--------
  insert(val) {
    let newNode = new Node(val);
    if (!this.root) {
      this.root = newNode;
      return this;
    }
    let current = this.root;
    while (true) {
      if (val === current.val) return undefined;
      if (val < current.val) {
        if (current.left === null) {
          current.left = newNode;
          return this;
        }
        current = current.left;
      } else {
        if (current.right === null) {
          current.right = newNode;
          return this;
        }
        current = current.right;
      }
    }
  }

  DFSInOrder() {
    let data = [];
    function traverse(node) {
      if (node.left) traverse(node.left);
      data.push(node.val);
      if (node.right) traverse(node.right);
    }
    traverse(this.root);
    return data;
  }
}

let tree = new BST();
tree.insertRecursive(10);
tree.insertRecursive(7);
tree.insertRecursive(5);
tree.insertRecursive(6);
tree.insertRecursive(100);
tree.insertRecursive(-1);
tree.insertRecursive(17);
console.log(tree.DFSInOrder());
