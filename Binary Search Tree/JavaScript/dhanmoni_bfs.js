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

  //INSERT USING RECURSIVE FUNCTION: -----
  insertRecursive(val) {
    let newNode = new Node(val);
    if (!this.root) {
      this.root = newNode;
      return this;
    } else {
      const searchTree = (node) => {
        if (val < node.val) {
          if (node.left === null) {
            node.left = newNode;
            return this;
          } else {
            return searchTree(node.left);
          }
        } else if (val > node.val) {
          if (node.right === null) {
            node.right = newNode;
            return this;
          } else {
            return searchTree(node.right);
          }
        } else {
          return null;
        }
      };

      return searchTree(this.root);
    }
  }

  BFS() {
    let node = this.root;
    let queue = [];
    let data = [];

    queue.push(node);
    while (queue.length) {
      node = queue.shift();
      data.push(node.val);
      if (node.left) queue.push(node.left);
      if (node.right) queue.push(node.right);
    }
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
console.log(tree.BFS());
