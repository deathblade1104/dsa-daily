# Maximum Sum Bitonic Subsequence
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:20px"><span style="font-family:arial,helvetica,sans-serif">Given an array arr[]&nbsp;of N integers. A <a href="http://en.wikipedia.org/wiki/Subsequence" target="_blank">subsequence&nbsp;</a>of arr[]&nbsp;is called Bitonic if it is first increasing then decreasing. Print the max sum bitonic subsequence.<br>
<br>
<strong>Example 1:</strong></span></span></p>

<pre><span style="font-size:20px"><span style="font-family:arial,helvetica,sans-serif"><strong>Input :</strong>
N = 9
arr[] = {1, 15, 51, 45, 33,
                   100, 12, 18, 9}
<strong>Output : </strong>194
<strong>Explanation :</strong>
Bi-tonic Sub-sequence are :
{1, 51, 9} or {1, 50, 100, 18, 9} or
{1, 15, 51, 100, 18, 9}  or
{1, 15, 45, 100, 12, 9}  or
{1, 15, 45, 100, 18, 9} .. so on           
Maximum sum Bi-tonic sub-sequence is 1 +
15 + 51 + 100 + 18 + 9 = 194</span></span></pre>

<p><br>
<span style="font-size:20px"><span style="font-family:arial,helvetica,sans-serif"><strong>Example 2:</strong></span></span></p>

<pre><span style="font-size:20px"><span style="font-family:arial,helvetica,sans-serif"><strong>Input :</strong>
N = 6
arr[] = {80, 60, 30, 40, 20, 10}
<strong>Output :</strong>
210
<strong>Explanation :</strong>
Here the sequence is strinctly decreasing.
</span></span></pre>

<p>&nbsp;</p>

<p><span style="font-size:20px"><span style="font-family:arial,helvetica,sans-serif"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>leftIndex()</strong>&nbsp;which takes the array <strong>arr[]</strong> and its size <strong>N </strong>as inputs and returns the maximum Bitonic sequence sum.<br>
<br>
<strong>Expected Time Complexity:</strong> O(N<sup>2</sup>)<br>
<strong>Expected Auxiliary Space:</strong> O(N)<br>
<br>
<strong>Constraints:</strong><br>
1&lt;=N&lt;=10<sup>3</sup><br>
1&lt;=arr[]&lt;=10<sup>5</sup></span></span></p>
 <p></p>
            </div>