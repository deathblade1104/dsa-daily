# Reach the Target ||
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given four integers <strong>A, B, C, D</strong>. A represents the initial position of the geek on the x-axis. In each step, geek can go to <strong>X+B</strong> or <strong>X-B</strong> if he is standing at <strong>X</strong>. The tasks is to check if it is possible for the geek to reach <strong>C</strong> exactly after <strong>D</strong> steps. If it is possible to reach <strong>C</strong> in exactly <strong>D</strong> steps, then print all <strong>distinct</strong> possible paths in lexicographical order. Otherwise, print <strong>-1</strong></span></p>

<p><span style="font-size:18px"><strong>Input: </strong><br>
1. The first line of the input contains a single integer<em> </em> <strong>T</strong> denoting the number of test cases. The description of&nbsp;<strong>T</strong> test cases follows.<br>
2. The first line of each test case contains four space-separated integers <strong>A, B, C, </strong>and<strong> D.</strong></span><br>
<br>
<span style="font-size:18px"><strong>Output:</strong> For each test case, print all distinct possible paths in lexicographical order if it is possible to reach <strong>C</strong>. Otherwise, print -1.<br>
<br>
<strong>Constraints:</strong><br>
1. 1 &lt;= T &lt;= 5</span><br>
<span style="font-size:18px">2. -10^9 &lt;= A, C &lt;= 10^9<br>
3. 1 &lt;= B &lt;= 10^9<br>
4. 1 &lt;= D &lt;= 12</span><br>
<br>
<span style="font-size:18px"><strong>Example:<br>
Input:</strong></span><br>
<span style="font-size:18px">3</span><br>
<span style="font-size:18px">2 3 8 4<br>
-3 1 0 3</span><br>
<span style="font-size:18px">-3 1 1 3</span></p>

<p><strong><span style="font-size:18px">Output:</span></strong><br>
<span style="font-size:18px">2 -1 2 5 8<br>
2 5 2 5 8<br>
2 5 8 5 8<br>
2 5 8 11 8<br>
-3 -2 -1 0<br>
-1</span><br>
<br>
<span style="font-size:18px"><strong>Explanation:</strong></span><br>
<span style="font-size:18px">Test case 1: All possible paths are {2, -1, 2, 5, 8}, {2, 5, 2, 5, 8}, {2, 5, 8, 5, 8}, {2, 5, 8, 11, 8}</span></p>
 <p></p>
            </div>