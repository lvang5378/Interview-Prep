1. quick sort
2. heap sort
3. 

###1. Quick Sort   (Partition-exchange sort)
Quick sort is a Divide and conqure algorithm.   https://en.wikipedia.org/wiki/Quicksort#Algorithm

```c++
    function partition(list, left, right, pivotIndex){}
```
- At the end of the end of the function, **pivotIndex is at the right place**. (all number on its left is smaller then it, all numbers on the right is larger than it)  
- Then do the left part, and right part of the array.

![alt text](https://upload.wikimedia.org/wikipedia/commons/thumb/a/af/Quicksort-diagram.svg/200px-Quicksort-diagram.svg.png)

#####Time Complexity
- average case O(n logn)
- worst case O(n^2), 
- best case O(n logn) (simple partition), O(n) three way partition and equal keys   

#####Space complexity 
- O(n) auxiliary (naive)
- O(log n) auxiliary (Sedgewick 1978)
    - in-place version, in-placement partitioning is used, this unstable partition requires O(1) space
    - after partitioning, the partition with the fewest elements is (revursively) sorted first, requiring at most O(logn) space. Then the other partition is sorted using tail recursion or iteration, which doesn't add to the call stack. This idea, as discussed above, was described by R. Sedgewick, and keeps the stack depth bounded by O(log n)

---
###Heap sort
https://en.wikipedia.org/wiki/Heapsort
####The heapsort algorithm can be divided into two parts.    
1. In the first step, a heap is built out of the data. 
2. In the second step, a sorted array is created by repeatedly removing the largest element from the heap (the root of the heap), and inserting it into the array. The heap is updated after each removal to maintain the heap. Once all objects have been removed from the heap, the result is a sorted array.  


####Algorithm
The heapsort algorithm involves preparing the list by first turning it into a max heap. The algorithm then repeatedly swaps the first value of the list with the last value, decreasing the range of values considered in the heap operation by one, and sifting the new first value into its position in the heap. This repeats until the range of considered values is one value in length.

The steps are:

1. Call the buildMaxHeap() function on the list. Also referred to as heapify(), this builds a heap from a list in O(n) operations.
2. Swap the first element of the list with the final element. Decrease the considered range of the list by one.
3. Call the shiftDown() function on the list to shift the new first element to its appropriate index in the heap.
4. Go to step (2) unless the considered range of the list is one element.  

The buildMaxHeap() operation is run once, and is O(n) in performance. The siftDown() function is O(log(n)), and is called n times. Therefore, the performance of this algorithm is O(n + n * log(n)) which evaluates to O(n log n).

####Complexity
- Worst case performance	O(n log n)
- Best case performance	\Omega(n), O(n log n)
- Average case performance	O(n log n)
- Worst case space complexity	O(1) auxiliary
