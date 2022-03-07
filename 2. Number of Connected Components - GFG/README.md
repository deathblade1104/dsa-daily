# 2. Number of Connected Components
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">This problem is to find the number of connected components. There will be 2 incomplete functions namely unionNodes and findNumberOfConnectedNodes. You have to complete these functions.&nbsp;</span></p>

<p><span style="font-size:18px"><strong>unionNodes:</strong> Join two subsets into a single set.<br>
<strong>findNumberOfConnectedNodes:</strong> Determine number of different connected components in a graph.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 5
M = 2
Edges[] = {(1,3),(1,5)}
<strong>Output: </strong>3<strong>
Explanation: </strong>Initially all nodes 1 2 3 4 5
are not connected.&nbsp;
After <strong>1 3</strong>, node 1 and 3 will be connected.
After <strong>1 5</strong>, node 1 and 5&nbsp;will be connected.
Finally we have {1,3,5}, {2}, {4}. So we
have a total of 3 connected components.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 5
M = 4
Edges[] = {(1,4),(2,3),(1,5)}
<strong>Output: </strong>2<strong>
Explanation: </strong>Initially all nodes 1 2 3 4 5
are not connected.
After 1 4, node 1 and 4 will be connected.
After 2 3, node 2 and 3 will be connected.
After 1 5, node 1 and 5 will be connected.
Finally we have {1,4,5}, {2, 3}. So we
have total of 2 connected components</span>
</pre>

<p><span style="font-size:18px"><strong>Your Task: </strong></span></p>

<p><span style="font-size:18px">You have to complete the function <strong>unionNodes() </strong>which merges the node1 and node2. You will also have to complete the function <strong>findNumberOfConnectedNodes()</strong>&nbsp;function will returntotal number of different connected components in a graph.</span></p>

<p><span style="font-size:18px"><strong>Note: </strong>We recommend you to solve this problem first&nbsp;<a href="https://practice.geeksforgeeks.org/problems/union-find/1" target="_blank">https://practice.geeksforgeeks.org/problems/union-find/1</a>. There are ways to solve this problem from BFS and DFS as well. But for this problem stick to filling these functions as in union-find.&nbsp;</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1).</span></p>

<p><span style="font-size:18px"><strong>Constraints:&nbsp;</strong><br>
1 &lt;= N &lt;= 10<sup>5</sup><br>
1 &lt;= M&nbsp;&lt;= 10<sup>5</sup><br>
1 &lt;= node1, node2 &lt;= N</span></p>
 <p></p>
            </div>