# Minimum Points To Reach Destination
## Hard 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a grid of size <strong>M*N</strong> with each cell consisting of an integer which represents points. We can move across a cell only if we have positive points. Whenever we pass through a cell, points in that cell are added to our overall points, the task is to find minimum initial points to reach cell (m-1, n-1) from (0, 0) by following these certain set of rules :<br>
&nbsp;<br>
1. From a cell (i, j) we can move to (i + 1, j) or (i, j + 1).<br>
2. We cannot move from (i, j) if your overall points at (i, j) are &lt;= 0.<br>
3. We have to reach at (n-1, m-1) with minimum positive points i.e., &gt; 0.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>: M = 3, N = 3 
       arr[][] = <code>{{-2,-3,3}, 
                  </code><code>{-5,-10,1}, </code>
<code>                  </code><code>{10,30,-5}</code><code>}; </code></span>

<span style="font-size:18px"><strong>Output:</strong> 7
<strong>Explanation</strong>: 7 is the minimum value to
reach the destination with positive
throughout the path. Below is the path.
(0,0) -&gt; (0,1) -&gt; (0,2) -&gt; (1, 2) -&gt; (2, 2)
We start from (0, 0) with 7, we reach
(0, 1) with 5, (0, 2) with 2, (1, 2)
with 5, (2, 2) with and finally we have
1 point (we needed greater than 0 points
at the end).</span></pre>

<div><span style="font-size:18px"><strong>Example 2:</strong></span></div>

<pre><span style="font-size:18px"><strong>Input: </strong>M = 3, N = 2
       arr[][] = <code>{{2,3}, </code>
<code>                  {5,10}, </code>
<code>                  {10,30}</code><code>}; </code>
<strong>Output: </strong>1
<strong>Explanation</strong>: Take any path, all of them 
are positive. So, required one point 
at the start</span>
</pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Complete the function <strong><code>minPoints</code>()&nbsp;</strong>which takes <strong>N, M</strong> and 2-d<strong> vector </strong>as input parameters and returns the integer value<br>
<br>
<strong>Expected Time Complexity:</strong> O(<strong>N*M</strong>)<br>
<strong>Expected Auxiliary Space:</strong> O(<strong>N*M</strong>)<br>
<br>
<strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>3</sup></span></p>
 <p></p>
            </div>