# Flatten binary tree to linked list
## Hard 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a binary tree, flatten it into linked list in-place. Usage of auxiliary data structure is not allowed. After flattening, left of each node should point to NULL and right should contain next node in preorder.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input : </strong>
          1
        /   \
       2     5
      / \     \
     3   4     6</span>
<span style="font-size:18px"><strong>Output :</strong>
1 2 3 4 5 6 
<strong>Explanation: </strong>
After flattening, the tree looks 
like this
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 2 3 4 5 6.</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input :</strong>
        1
       / \
      3   4
         /
        2
         \
          5 
<strong>Output :</strong> 
1 3 4 2 5  
<strong>Explanation : </strong>
After flattening, the tree looks 
like this 
     1
      \
       3
        \
         4
          \
           2
            \ 
             5 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 3 4 2 5.</span></pre>

<div><strong><span style="font-size:18px">Your task:</span></strong></div>

<div><span style="font-size:18px">You don't have to read input or print anything. Your task is to complete the function flatten() which takes the root of the tree and flattens the tree into a linkes list without using any auxiliary space.</span></div>

<div><span style="font-size:18px">Note : The driver code&nbsp;prints the inorder traversal of the flattened binary tree.</span></div>

<div>&nbsp;</div>

<div><span style="font-size:18px"><strong>Expected Time Complexity: </strong>O(n)</span></div>

<div><span style="font-size:18px"><strong>Expected Auxiliary Space:</strong> O(1)</span></div>

<div>&nbsp;</div>

<div><strong><span style="font-size:18px">Constraints :</span></strong></div>

<div><span style="font-size:18px">1&lt;=n&lt;=10^5</span></div>

<div>&nbsp;</div>
 <p></p>
            </div>