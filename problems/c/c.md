# Fair Distribution

https://codeforces.com/gym/105053/problem/F

- time limit per test 0.35 seconds
- memory limit per test 1024 megabytes

An entrepreneur has $N$ blueprints, each describing a type of building. Each blueprint specifies the building's height through two integers $G$ and $R$.

- $G$: Height of the ground floor. It can be zero, indicating that the building has no ground floor.
- $R$: Height of each residential floor. Each building has at least one residential floor.

The entrepreneur wants to distribute all of these blueprints among their two children Alice and Bob. Each child will build exactly one building from each blueprint allocated to them, choosing the number of residential floors for each building.

The entrepreneur wants to avoid showing favoritism towards either child, so they are looking for a fair distribution of the blueprints. They decided that a fair distribution is one in which it is possible to construct the buildings in such a way that the sum of the heights of the buildings constructed by each child is the same. Can you tell whether a fair distribution exists?

Consider the following example for $N=3$ blueprints:

- $G=1$ and $R=1$ (possible heights are 2,3,4,…);
- $G=0$ and $R=3$ (no ground floor, possible heights are 3,6,9,…);
- $G=2$ and $R=1$ (possible heights are 3,4,5,…).

In this case a possible fair distribution is assigning the second blueprint to Alice and the rest to Bob. Even though Alice receives a single blueprint while Bob receives two, they may construct two residential floors on the first building type (height 3), two residential floors on the second (height 6), and one residential floor on the third (height 3). In this way, the sum of the heights of the buildings constructed by each child would be 6.

### Input

The first line contains an integer $N$ $(1\leq N\leq 2\cdot 10^5)$ indicating the number of blueprints.

Each of the next $N$ lines contains two integers $G$ $(0\leq G\leq 2\cdot 10^5)$ and $R$ $(1\leq R\leq 10^9)$ denoting respectively the height of the ground floor and the height of each residential floor specified by the corresponding blueprint. The sum of the heights of the ground floors of all blueprints is at most $2\cdot 10^5$.

### Output

Output a single line with the uppercase letter Y if there exists a fair distribution of the blueprints, and the uppercase letter N otherwise.