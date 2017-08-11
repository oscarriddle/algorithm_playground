/*
The problem is classic and common to see. Because binary tree and the bidirectional linked list 
share the same data structure, they shall be easily converted.
This approach uses recursive method to convert left part and right part of each head.
leftE means the end/last node of left part. leftS means the start node of left part.
rightE means the end/last node of right part. rightS means the start node of right part.
For left and right part, the leftE/rightE.next will be firstly connected to leftS/rightS for quick locate the start node.

*/

public Node {
 public Node left;
 public Node right;
 public int value;
 public Node (int data){
  this.value = data;
 }
}

public Node convert2(Node head) {
  if (head == null){
    return null; 
  }
  
  Node last = process(head);
  head = last.right;
  last.right = null;
  return head;
} 

public Node process(Node head){
 if (head == null) {
  return null; 
 }
 Node leftE = process (head.left);
 Node rightE = process(head.right);
 Node leftS = (leftE != null) ? leftE.right : null;
 Node rightS = (rightE != null) ? rightE.right : null;
 
 if (leftE != null && rightE != null) {
  leftE.right = head;
  head.left = leftE;
  head.right = rightS;
  rightS.left = head;
  rightE.right = leftS;
  return rightE;
 } else if (leftE != null) {
  leftE.right = head;
  head.left = leftE;
  head.right = leftS;
  return head;
 } else if (rightE != null) {
  head.right = rightS;
  rightS.left = head;
  rightE.right = head;
  return rightE;
 } else {
  head.right = head;
  return head;
 }
}
