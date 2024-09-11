# Matching Reduction

https://codeforces.com/contest/1721/problem/F

- time limit per test: 8 seconds
- memory limit per test: 512 megabytes

You are given a bipartite graph with $n_1$
vertices in the first part, $n_2$
vertices in the second part, and $m$
edges. The maximum matching in this graph is the maximum possible (by size) subset of edges of this graph such that no vertex is incident to more than one chosen edge.

You have to process two types of queries to this graph:

- 1 — remove the minimum possible number of vertices from this graph so that the size of the maximum matching gets reduced exactly by 1
  , and print the vertices that you have removed. Then, find any maximum matching in this graph and print the sum of indices of edges belonging to this matching;
- 2 — query of this type will be asked only after a query of type 1
  . As the answer to this query, you have to print the edges forming the maximum matching you have chosen in the previous query.
  Note that you should solve the problem in online mode. It means that you can't read the whole input at once. You can read each query only after writing the answer for the last query. Use functions fflush in C++ and BufferedWriter.flush in Java languages after each writing in your program.

### Input

The first line contains four integers $n_1$, $n_2$, $m$ and $q$ $(1 \leq n_1,n_2 \leq 2\cdot 10^5; 1\leq m\leq\text{min}(n_1\cdot n_2,2\cdot 10^5); 1\leq q \leq 2\cdot 10^5)$.

Then $m$ lines follow. The $i$-th of them contains two integers $x_i$ and $y_i$ $(1\leq x_i \leq n_1; 1\leq y_i\leq n_2)$ meaning that the $i$-th edge connects the vertex $x_i$ in the first part and the vertex $y_i$ in the second part. There are no pairs of vertices that are connected by more than one edge.

Then $q$ lines follow. The i-th of them contains one integer, 1 or 2, denoting the i-th query. Additional constraints on queries:

- the number of queries of type 1
  won't exceed the size of the maximum matching in the initial graph;
- the number of queries of type 2 won't exceed 3;
- each query of type 2 is preceded by a query of type 1;
- your solution is allowed to read the i-th query only after printing the answer for the $(i−1)$-th query and flushing the output.

### Output

For a query of type 1, print the answer in three lines as follows:

- the first line should contain the number of vertices you remove;
- the second line should contain the indices of vertices you remove, as follows: if you remove the vertex $x$ from the left part, print $x$; if you remove the vertex y from the right part, print $−y$ (negative index);
- the third line should contain the sum of indices of edges in some maximum matching in the resulting graph. The edges are numbered from 1 to $m$.

For a query of type 2, print the answer in two lines as follows:

- the first line should contain the size of the maximum matching;
- the second line should contain the indices of the edges belonging to the maximum matching. Note that the sum of these indices should be equal to the number you printed at the end of the previous query of type 1;

After printing the answer to a query, don't forget to flush the output.
