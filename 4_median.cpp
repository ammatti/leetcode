/**
*
先給了O(N) 解法, 用兩個pointer 指向 A[0] and B[0],然後移動小的pointer, 等到過了(A.length+B.length)/2 就可以算中位數.
只是解釋作法,沒直接實作.

再提出O(LogN)解法, 取A[mid] 用binary search 找B array的位置, 如果mid_a + mid_b == (A.length+B.length)/2, 就可以算中位數.
**/

//https://leetcode.com/problems/median-of-two-sorted-arrays/description/
//http://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-4-median-of-two-sorted-arrays/


