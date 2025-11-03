# Minimum Steps
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-family:arial,helvetica,sans-serif"><span style="font-size:20px">Anuj has challenged Arun to climb <strong>N</strong> stairs but at only in powers of <strong>P</strong> and <strong>Q</strong>. Now Arun being a lazy guy wants to do this in minimum number of steps possible. So he has asked for your help to calculate the <strong>minimum</strong> number of steps he requires to take for climbing <strong>N</strong> stairs ( 1 step = some power of P or Q stairs (including zeroth power) ).</span></span></p>

<p dir="ltr"><br>
<span style="font-family:arial,helvetica,sans-serif"><span style="font-size:20px"><strong>Example 1:</strong></span></span></p>

<pre><span style="font-family:arial,helvetica,sans-serif"><span style="font-size:20px"><strong>Input: </strong>
N = 15, P = 2, Q = 3
<strong>Output:</strong>
3
<strong>Explanation:</strong>
We can make 15 by (8,4,3)
or (9,3,3) both takes 3 steps.</span></span></pre>

<p dir="ltr">&nbsp;</p>

<p dir="ltr"><span style="font-family:arial,helvetica,sans-serif"><span style="font-size:20px"><strong>Example 2:</strong></span></span></p>

<pre><span style="font-family:arial,helvetica,sans-serif"><span style="font-size:20px"><strong>Input: </strong>
N = 19, P = 4, Q = 3
<strong>Output:</strong>
2
<strong>Explanation:</strong>
In the second case, we can make
19 by (16,3) which is 2 steps.</span></span></pre>

<p>&nbsp;</p>

<p dir="ltr"><span style="font-family:arial,helvetica,sans-serif"><span style="font-size:20px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>moves()</strong>&nbsp;which takes <strong>three </strong>integers<strong> N</strong>,<strong> P </strong>and<strong> Q </strong>as inputs and returns the number of steps that Arun needs to take to climb N stairs in powers of P &amp; Q. If fit is not possible print -1.</span></span><br>
&nbsp;</p>

<p dir="ltr"><span style="font-family:arial,helvetica,sans-serif"><span style="font-size:20px"><strong>Expected Time Complexity:</strong> O(N. log(N))<br>
<strong>Expected Auxiliary Space:</strong> O(N. log(N))</span></span><br>
&nbsp;</p>

<p dir="ltr"><span style="font-family:arial,helvetica,sans-serif"><span style="font-size:20px"><strong>Constraints:</strong><br>
1 ≤ N, P, Q ≤ 10<sup>5</sup></span></span></p>
 <p></p>
            </div>