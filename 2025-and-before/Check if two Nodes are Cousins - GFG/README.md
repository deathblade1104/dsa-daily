# Check if two Nodes are Cousins
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given the binary Tree of and&nbsp;two-node values. Check&nbsp;whether the two-node values&nbsp;are cousins of each other or not.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
&nbsp;     </strong>1
&nbsp;   /   \
<strong>   </strong>2     3
a = 2, b = 3<strong>
Output: </strong>0<strong>
</strong></span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>&nbsp; &nbsp; &nbsp; &nbsp;1
&nbsp; &nbsp; &nbsp;/&nbsp;  \&nbsp;
&nbsp;  &nbsp;2&nbsp; &nbsp;  3
&nbsp;  /&nbsp; &nbsp; &nbsp;&nbsp;&nbsp;\
<strong>  </strong>5&nbsp; &nbsp; &nbsp; &nbsp;&nbsp;&nbsp;4<strong>&nbsp;
</strong>a = 5, b = 4<strong>
Output: </strong>1<strong>
Explanation: </strong>Here, nodes 5 and 4 are
at the same level and have different
parent nodes. Hence, they both are cousins&nbsp;</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function</span><span style="font-size:18px"><strong> isCousins() </strong>that takes the root node<strong>&nbsp;</strong>of the tree (having all nodes distinct)<strong>, </strong>and two integers 'a' and 'b'&nbsp;as inputs. It returns true if the nodes with given values 'a' and 'b' are Cousins of each other and returns false otherwise.&nbsp;<br>
Two nodes value are cousins of each other if they are at the same level and have different parents. (The driver code will print 1 if the returned values is true,otherwise 0.)</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(Height of the Tree).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;=Number of Nodes&lt;=1000</span></p>

<p><br>
<span style="font-size:14px"><strong>Note:&nbsp;</strong>The <strong>Input/Ouput</strong> format and <strong>Example</strong> given are used for system's internal purpose, and should be used by a user for <strong>Expected Output</strong> only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.</span></p>
 <p></p>
            </div>