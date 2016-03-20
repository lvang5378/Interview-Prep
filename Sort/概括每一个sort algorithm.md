###Quick Sort   (Partition-exchange sort)
```c++
    function partition(list, left, right, pivotIndex){}
```
- At the end of the end of the function, **pivotIndex is at the right place**. (all number on its left is smaller then it, all numbers on the right is larger than it)  
- Then do the left part, and right part of the array.

#####Time Complexity
- average case O(n logn)
- worst case O(n^2), 
- best case O(n logn) (simple partition), O(n) three way partition and equal keys   

#####Space complexity 
- O(n) auxiliary (naive)
- O(log n) auxiliary (Sedgewick 1978)

---

