<h2><a href="https://www.geeksforgeeks.org/problems/find-all-distinct-subset-or-subsequence-sums4424/1?utm_source=chatgpt.com">All Distinct Subset (or Subsequence) Sums</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given an array <strong>arr[]</strong> of integers, generate all possible subset<strong> sums </strong>and return the <strong>distinct </strong>sums in <strong>sorted </strong>order. </span></p>
<p><span style="font-size: 18px;">A subset may contain any number of elements, including the empty subset.</span></p>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [1, 2]
<strong>Output: </strong>[0, 1, 2, 3]
<strong>Explanation: </strong>Four distinct sums can be calculated which are 0, 1, 2 and 3. <br>0 if we do not choose any number.
1 if we choose only 1.
2 if we choose only 2.
3 if we choose 1 and 2.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [1,2,3]
<strong>Output: </strong>[0, 1, 2, 3, 4, 5, 6]
<strong>Explanation: </strong>Seven distinct sum can be calculated which are 0, 1, 2, 3, 4, 5 and 6.
0 if we do not choose any number.
1 if we choose only 1.
2 if we choose only 2.
3 if we choose only 3.
4 if we choose 1 and 3.
5 if we choose 2 and 3.
6 if we choose 1, 2 and 3.</span>&nbsp;&nbsp;</pre>
<p><span style="font-size: 18px;"><strong>Constraints:<br></strong></span><span style="font-size: 18px;">1 ≤ n, arr[i]≤ 500<br>1 ≤ arr[i]≤ 10<sup>3</sup>&nbsp; <br></span><span style="font-size: 18px;">total sum of elements of arr[] is&nbsp;</span><span style="font-size: 18px;">≤ </span><span style="font-size: 18px;">2.5 x 10</span><sup>4</sup><span style="font-size: 18px;">&nbsp;</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;