'''
<LeetCode> 
A and B are both sorted array with (m,) and (n,) type respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
If len(A)+len(B) is even, the median is the mean of the 2 values closet to the median point
'''
class Solution(object):
    def findMedianSortedArrays(self, A, B):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        l=len(A)+len(B)
        return self.findKth(A,B,l//2) if l%2==1 else (self.findKth(A,B,l//2-1)+self.findKth(A,B,l//2))/2.0
            
            
    def findKth(self,A,B,k):
        if len(A)>len(B): # Keep the first arg is always smaller than the second arg
            A,B=B,A
        if not A: # if A is empty, then only B counts, so return the value B[k]
            return B[k]
        if k==len(A)+len(B)-1:  # if k actually equals to the sum up length of A B, return which one is the max one
            return max(A[-1],B[-1]) 
        i=len(A)//2  # index pointer i equal to the cut half of A
        j=k-i  # j pointer is the num of rest of k-i
        if A[i]>B[j]: 
            #Here I assume it is O(1) to get A[:i] and B[j:]. In python, it's not but in cpp it is.
            return self.findKth(A[:i],B[j:],i)
        else:
            return self.findKth(A[i:],B[:j],j)        
