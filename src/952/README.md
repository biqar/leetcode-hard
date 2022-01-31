# [952. Largest Component Size by Common Factor](https://leetcode.com/problems/largest-component-size-by-common-factor/)

## Problem Statement
You are given an integer array of unique positive integers nums. Consider the following graph:

* There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
* There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.

Return the size of the largest connected component in the graph.

Example 1:

<img align="middle" src="https://assets.leetcode.com/uploads/2018/12/01/ex1.png" alt="example_1"/>

```
Input: nums = [4,6,15,35]
Output: 4
```

Example 2:

<img align="middle" src="https://assets.leetcode.com/uploads/2018/12/01/ex2.png" alt="example_2"/>

```
Input: nums = [20,50,9,63]
Output: 2
```

Example 3:

<img align="middle" src="https://assets.leetcode.com/uploads/2018/12/01/ex3.png" alt="example_3"/>

```
Input: nums = [2,3,6,7,4,12,21,39]
Output: 8
```

Constraints:
* 1 <= nums.length <= 2 * 10^4
* 1 <= nums[i] <= 10^5
* All the values of nums are unique.

## Solution Idea

