# Largest subtree sum in a tree
## Hard 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a binary tree. The task is to find subtree with maximum sum in the tree and return its sum.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
              1
            /   \
           2      3
          / \    / \
         4   5  6   7</span><span style="font-size:18px">
<strong>Output: </strong>28
<strong>Explanation:</strong> 
As all the tree elements are positive,
the largest subtree sum is equal to
sum of all tree elements.</span></pre>

<pre><span style="font-size:18px">
</span><span style="font-size:18px"><strong>Example 2:</strong></span>
<span style="font-size:18px"><strong>Input:</strong>
               1
            /    \
          -2      3
          / \    /  \
         4   5  -6   2</span><span style="font-size:18px">
<strong>Output: </strong>7
<strong>Explanation: </strong>
Subtree with largest sum is : 
  -2
 /  \ 
4    5
Also, entire tree sum is also 7.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>findLargestSubtreeSum</strong><strong>()</strong>&nbsp;which takes the root of a binary tree and returns an integer.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N)<br>
<strong>Expected Auxiliary Space:</strong> O(N)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 10<sup>5</sup><br>
-10<sup>3</sup>&nbsp;&lt;= tree.val&nbsp;&lt;= 10<sup>3</sup></span></p>
 <p></p>
            </div>