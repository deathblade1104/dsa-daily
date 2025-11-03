# Maximum number of overlapping Intervals
##  Hard 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given&nbsp;<strong>N</strong>&nbsp;intervals of the form [<strong>A, B]</strong>. The task is to return the maximum number of overlap among these intervals at any time.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 3
Intervals[] = {{1, 2}, {2, 4}, {3, 6}}
<strong>Output: </strong>
2
<strong>Explanation:</strong> 
The maximum overlapping is 2(between (1 2) and 
(2 4) or between (2 4) and (3 6))</span>&nbsp;
<img alt="" src="https://media.geeksforgeeks.org/img-practice/overlapping-300x189-1648453947.png" style="height:189px; width:300px" class="img-responsive">
<span style="font-size:18px">
</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 4
Intervals[] = {{1, 8}, {2, 5}, {5, 6}, {3, 7}}
<strong>Output: </strong>
4
<strong>Explanation:</strong> 
The maximum overlapping is 4 (between (1, 8), 
(2, 5), (5, 6) and (3, 7))</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>overlap</strong></span><span style="font-size:18px"><strong>()</strong>&nbsp;which takes a list of pairs as input and returns an integer&nbsp;as output.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N * log N)<br>
<strong>Expected Auxiliary Space:</strong> O(N)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
2 &lt;= N&nbsp;&lt;= 2 * 10<sup>4</sup><br>
1&lt;= intervals[i][0] &lt; intervals[i][1] &lt;= 4*10<sup>3</sup></span></p>
 <p></p>
            </div>