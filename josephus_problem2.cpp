//This is a better approach of josephus problem with better asymptoticall upper boundary
//Instead of looping the queue, we choose to use the recursive way to calculate the final survived element.

public class Node {
  public int value;
  public Node next;
  public Node(int data) {
    this.value = value;
  }
} 

public Node josephusKill2(Node head, int m){
  if (head == null || head.next == head || m<1){
    return head;
  }

  Node cur = head.next;
  int tmp = 1;
  while (cur != had){
    tmp++;
    cur = cur.next;
  }
  tmp = getLive(temp,m);
  while (--tmp!=0) {
    head = head.next;
  }
  head.next = head;
  return head;
}

public int getLive(int i, int m){
  if(i == 1){
    return 1;
  }
  return (getLive(i-1), m) + m - 1) % i + 1;
}

/*
Now analyze the time complexity

*/


