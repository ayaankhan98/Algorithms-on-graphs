# Algorithms-on-graphs
Self Learning Repository For Graph Algorithms

- will be soon updating the repository it is completely up to date.
- watch the repository for further updates
- documentation is also poor, trying to fix this soon

# Representation Of Graphs In Above Files
In programming assignments, graphs are given as follows. The first line contains non-negative integers n and
m — the number of vertices and the number of edges respectively. The vertices are always numbered from 1
to n. Each of the following m lines defines an edge in the format u v where 1 ≤ u, v ≤ n are endpoints of
the edge. If the problem deals with an undirected graph this defines an undirected edge between u and v. In
case of a directed graph this defines a directed edge from u to v. If the problem deals with a weighted graph
then each edge is given as u v w where u and v are vertices and w is a weight.
It is guaranteed that a given graph is simple. That is, it does not contain self-loops (edges going from a
vertex to itself) and parallel edges.

Examples:
- An undirected graph with four vertices and five edges:
```
4 2
4 1
2 3
5 1
3 4
4 2
```
- A directed graph with five vertices and eight edges.
```
5 8
4 3
1 2
3 1
3 4
2 5
5 1
5 4
5 3
```

- A directed graph with five vertices and one edge.
```
5 1
4 3
```
Note that the vertices 1, 2, and 5 are isolated (have no adjacent edges), but they are still present in
the graph.

- A weighted directed graph with three vertices and three edges.
```
3 3
2 3 9
1 3 5
1 2 -2
```

# Problem : Finding an Exit from a Maze
## Problem Introduction
A maze is a rectangular grid of cells with walls between some of adjacent cells.
You would like to check whether there is a path from a given cell to a given
exit from a maze where an exit is also a cell that lies on the border of the maze
(in the example shown to the right there are two exits: one on the left border
and one on the right border). For this, you represent the maze as an undirected
graph: vertices of the graph are cells of the maze, two vertices are connected by
an undirected edge if they are adjacent and there is no wall between them. Then,
to check whether there is a path between two given cells in the maze, it suffices to
check that there is a path between the corresponding two vertices in the graph.

## Problem Description
### Task
Given an undirected graph and two distinct vertices u and v, check if there is a path between u and v.
### Input Format
An undirected graph with n vertices and m edges. The next line contains two vertices u
and v of the graph.
### Constraints
```
2 ≤ n ≤ 10 3 ; 1 ≤ m ≤ 10 3 ; 1 ≤ u, v ≤ n; u != v.
```
### Output Format
Output 1 if there is a path between u and v and 0 otherwise.
### Time Limits
```
Language    C | C++ | Java | Python  |  C#  |  Haskell | JavaScript |  Ruby |  Scala |
--------------------------------------------------------------------------------------
Time        1 |  1  |  1.5 |    5    |  1.5 |   2      |      5     |    5  |  5     |
```
### Solution
reachability.cpp