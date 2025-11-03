# Sum of leaf nodes in BST
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a Binary Search Tree, find the sum of all leaf nodes. BST has the following property&nbsp;(duplicate nodes are possible):</span></p>

<ul>
	<li><span style="font-size:18px">The<strong> left subtree </strong>of a node contains only nodes with <strong>keys less </strong>than the node’s key.</span></li>
	<li><span style="font-size:18px">The<strong> right subtree </strong>of a node contains only nodes with<strong> keys greater</strong> <strong>than </strong>or <strong>equal </strong>to the node’s key.</span></li>
</ul>

<p><span style="font-size:18px"><strong>Input:</strong><br>
The first line of input contains a single integer <strong>T</strong> denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case consists of integer <strong>N</strong>, denoting the number of elements in the BST. The second line of each test case consists of N space-separated integers denoting the elements in the BST.</span></p>

<p><span style="font-size:18px"><strong>Output:</strong><br>
For each testcase, in a new line, print the sum of leaf nodes.</span></p>

<p><strong><span style="font-size:18px">Your Task:</span></strong><br>
<span style="font-size:18px">This is a function problem. You don't have to take any input. You are required to complete the function&nbsp;<strong>sumOfLeafNodes </strong>that takes <strong>root </strong>as <strong>parameter </strong>and returns the sum of leaf nodes.&nbsp;</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= T &lt;= 10<sup>3</sup> &nbsp; &nbsp;&nbsp;<br>
1 &lt;= N &lt;= 10<sup>5</sup></span></p>

<p><span style="font-size:18px"><strong>Example:</strong><br>
<strong>Input:</strong><br>
2<br>
6<br>
67 34 82 12 45 78<br>
1<br>
45</span><br>
<span style="font-size:18px"><strong>Output:</strong><br>
135<br>
45</span></p>

<p><span style="font-size:18px"><strong>Explanation:</strong><br>
In first test case, the BST for the given input will be-</span></p>

<p><span style="font-size:18px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;67</span></p>

<p><span style="font-size:18px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; /&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;\</span></p>

<p><span style="font-size:18px">&nbsp;&nbsp;&nbsp;34&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;82</span></p>

<p><span style="font-size:18px">&nbsp; /&nbsp;&nbsp;&nbsp; \&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; /</span></p>

<p><span style="font-size:18px">12&nbsp;&nbsp; 45&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;78</span></p>

<p><strong><span style="font-size:18px">Hence, the required sum= 12 + 45 + 78 = 135</span></strong></p>
 <p></p>
            </div>