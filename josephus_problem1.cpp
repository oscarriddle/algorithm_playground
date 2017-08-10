//The Josephus Problem is a famous ring-type linked nodes problem
//The problem is named after Flavius Josephus, a Jewish historian living in the 1st century.
//According to Josephus' account of the siege of Yodfat, he and his 40 soldiers were trapped in a cave by Roman soldiers.
//They chose suicide over capture, and settled on a serial method of committing suicide by drawing lots.
//Josephus states that by luck or possibly by the hand of God, he and another man remained until the end and surrendered to the Romans rather than killing themselves.

//This problem can be demonstrated by ring-type linked nodes structure. 
//The input is ring linked node, Output the lucky guy
//Count the ring link, delete the node ever when counting number equals m.

//Assume the node number is n, so every delete a node need to repeat m times, so the upper asymptoticall bound is O(n*m)

public class Node {
    public int value;
    public Node next;
    public Node (int data) {
      this.value = value;
      } 
  }

Public Node josephusKill(Node head, int m){
    if (head == null || head.next == head || m<1) { // If head is exactly the last one, or head is been deleted, return it
        return head;
    } 
  Node last = head; 
  while (last.next != head){ // if head.next != head, (loop back) Keep moving forward
    last = last.next;
  }
  int count = 0;
  while (head != last) { // After moved, if head.next!=head
    if (++count == m){ //Count ++ and if count == m
      last.next = head.next; // connect head.next to last.next
      count=0; // reset counting
    } else {
      last = last.next; // if count ++ and count != m, move forward
    }
    head = last.next; // after moved, if head.next != head, assign last.next to head
  } 
  return head;
} 
