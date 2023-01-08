# [149. Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/description/)

## Problem Statement
Given an array of `points` where `points[i] = [xi, yi]` represents a point on the X-Y plane, return the *maximum number of points that lie on the same straight line*.

Example 1:

<img align="middle" src="https://assets.leetcode.com/uploads/2021/02/25/plane1.jpg" alt="example_1"/>

```
Input: points = [[1,1],[2,2],[3,3]]
Output: 3
```
Example 2:

<img align="middle" src="https://assets.leetcode.com/uploads/2021/02/25/plane2.jpg" alt="example_2"/>

```
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
```

Constraints:
* 1 <= points.length <= 300
* points[i].length == 2
* -10^4 <= xi, yi <= 10^4
* s and wordDict[i] consist of only lowercase English letters.
* All the `points` are **unique**.

## Solution Idea

