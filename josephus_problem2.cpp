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
The idea is to generate a new list after killing every element and iterate the new list, for example, after the first killing:

old: m+1, m+2, m+3, ... , n, 1, 2, 3, ..., m-1
new: 1, 2, 3, ..., n-m, n-m+1, n-m+2, ..., n-1

Above shows the new mapping relation after kill the mth item. Now interpret the mapping function easily as
for ever old, exists old = (new + m) % n, Note that the solution is not unique
So the recursive function is: f(n) = (f(n-1) + m) % n
Appling the master method: a == 1, b == (n-1)/n, f(n) = O(1)
So time complexity is T(n) = 1 * T(n * (n-1) / n) + O(1) = T(n-1)+O(1) <= O(n)
Thus appling the recursive way, the time complexity of josephus kill problem is optimized to O(n)
*/


