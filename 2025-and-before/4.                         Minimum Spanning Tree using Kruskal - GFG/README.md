# 4. 
                        Minimum Spanning Tree using Kruskal
##  Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">You are given a graph where each edge has a weight associated with it.&nbsp;&nbsp;Find the minimum spanning tree value.</span></p>

<p><span style="font-size:18px"><strong>Minimum Spanning Tree:</strong>&nbsp;Given a connected and undirected graph, a&nbsp;<em>spanning tree</em>&nbsp;of that graph is a subgraph that is a tree and connects all the vertices together.&nbsp; A single graph can have many different spanning trees.&nbsp; A&nbsp;<em>minimum spanning tree (MST)</em>&nbsp;or minimum weight spanning tree for a weighted, connected and undirected graph is a spanning tree with weight less than or equal to the weight of every other spanning tree. The weight of a spanning tree is the sum of weights given to each edge of the spanning tree.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">N = 5, M = 6 
Edges[] = {(1,2,4),(1,3,3),(2,4,1),
&nbsp;          (2,5,1),(4,5,3),(3,4,2)}
<strong>Output: </strong>7<strong>
Explanation: </strong>The tree&nbsp;will be formed from
these nodes and weights ,{1,3,3}, {2,4,1}
{2,5,1}, {3,4,2}. Total sum of these edges
is 7.</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">N = 4, M = 5
Edges[] = {(1,2,5),(2,3,6),(1,4,7),
&nbsp;          (2,4,8),(3,4,7)}
<strong>Output: </strong>18<strong>
Explanation: </strong>The tree will be formed from
these nodes and weights, {1,2,5}, {2,3,6},
{3,4,7}. Total sum of those edges is 18</span></pre>

<p><span style="font-size:18px"><strong>Your Task: </strong></span></p>

<p><span style="font-size:18px">You will have to complete the function <strong>calcMinimumSpanningValue()</strong>&nbsp;function will return the minimum spanning value.</span></p>

<p><span style="font-size:18px"><strong>Note</strong>:<br>
<strong>Cpp</strong>: The graph is given as array of vector containing pairs i.e. if adj[2] = (3,4) it implies src = 2, des = 3 wt = 4<br>
<strong>Java</strong>: The graph is given as a Arraylist of a class Edge. Edge contains three variables- src, des, wt<br>
<strong>Python</strong>: The graph is given by an array of triplets (src,des,wt)</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N + M).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N + M).</span></p>

<p><span style="font-size:18px"><strong>Constraints:&nbsp;</strong><br>
2 &lt;= N &lt;= 10<sup>5</sup><br>
1 &lt;= M&nbsp;&lt;= 10<sup>5</sup><br>
1 &lt;= node1, node2 &lt;= N<br>
1 &lt;= edge weight &lt;= 10<sup>5</sup><br>
Graph doesn't contains multiple edges or self loops.</span></p>
 <p></p>
            </div>