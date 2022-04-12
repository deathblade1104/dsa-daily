# 7. K Most occurring elements
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given an array <strong>arr</strong>[] of <strong>N </strong>integers in which elements may be repeating several times. Also, a positive number <strong>K</strong> is given and the task is to find sum of total frequencies of K most occurring elements</span></p>

<p><strong><span style="font-size:18px">Note: </span></strong><span style="font-size:18px">The value of K is guaranteed to be less than or equal to the number of distinct elements in arr.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">N = 8
arr[] = {3,1,4,4,5,2,6,1}
K = 2
<strong>Output: </strong>4<strong>
Explanation: </strong>Since, 4 and 1 are 2 most
occurring elements in the array with
their frequencies as 2, 2. So total
frequency is 2 + 2 = 4.</span>
</pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">N = 8
arr[] = {3,3,3,4,1,1,6,1}
K = 2
<strong>Output: </strong>6<strong>
Explanation: </strong>Since, 3 and 1 are most
occurring elements in the array with
frequencies 3, 3 respectively. So,
total frequency is 6.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
Complete the function <strong>kMostFrequent()&nbsp;</strong>whic returns the frequencies of K most occuring elements.</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 10<sup>6</sup><br>
1 &lt;= K &lt;= N<br>
1 &lt;= arr[i] &lt;= 10<sup>6</sup></span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity </strong>: O(N log N)<br>
<strong>Expected Auxilliary Space:&nbsp;</strong>O(N)</span></p>
 <p></p>
            </div>