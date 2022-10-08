const readline = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

class MyCircularQueue {
  k;
  queue;
  front;
  rear;

  constructor(k) {
    this.k = k;
    this.queue = new Array(k).fill(null);
    this.front = this.rear = -1;
  }

  enQueue(value) {
    if ((this.rear + 1) % this.k === this.front) {
      console.log("Failed to add to the queue: Queue length exceeded");
      return false;
    } else if (this.front === -1) {
      this.front = this.rear = 0;
      this.queue[this.rear] = value;
    } else {
      this.rear = (this.rear + 1) % this.k;
      this.queue[this.rear] = value;
    }
    console.log("Successfully Added data to the queue " + this.queue);
    return true;
  }

  deQueue() {
    if (this.front === -1) {
      console.log("Failed to remove an element from the queue");
      return false;
    }
    if (this.front === this.rear) {
      this.front = this.rear = -1;
    } else {
      this.front = (this.front + 1) % this.k;
    }
    console.log("Successfully Removed an element from the queue");
    return true;
  }

  getFront() {
    if (this.isEmpty()) return "Queue is Empty";
    console.log("Data from the fron of the queue is " + this.queue[this.front]);
    return this.queue[this.front];
  }

  getRear() {
    if (this.isEmpty()) return "Queue is Empty";
    console.log(
      "Data from the rear end of the queue is " + this.queue[this.rear]
    );
    return this.queue[this.rear];
  }

  isEmpty() {
    console.log(this.rear === -1 ? "Queue is Empty" : "Queue is not Empty");
    return this.rear === -1;
  }

  isFull() {
    console.log(
      !this.isEmpty() && (this.rear + 1) % this.k === this.front
        ? "Queue is Full"
        : "Queue is not Full"
    );
    return !this.isEmpty() && (this.rear + 1) % this.k === this.front;
  }
}

readline.question("Enter the length of a queue\n", (k) => {
  obj = new MyCircularQueue(k);
  readline.question(
    "Enter the list of values separated by space to add to the queue\n",
    (array) => {
      let data = array.split(" ");
      for (let i = 0; i < data.length; i++) {
        obj.enQueue(data[i]);
      }
      obj.isFull();
      obj.getFront();
      obj.getRear();
      obj.isEmpty();
      for (let j = 0; j < data.length; j++) {
        obj.deQueue();
      }
      obj.getFront();
      obj.getRear();
      obj.isFull();
      obj.isEmpty();
      readline.close();
    }
  );
});
