# Overview and motivation
Segment trees are structures that devide ranges in halfs until unitary ranges and store important values to each range. The root of this type of tree represent the entire range of your array, so let 

&nbsp;&nbsp;&nbsp; $ mid = (range\_ begin + range\_ end) / 2$ 

The left and right child ranges of every node in your tree (except the leaves $range\_ begin = range\_ end$ obviously) are defined as

&nbsp;&nbsp;&nbsp; $ [ range\_ begin,mid] \ , [mid + 1, range\_ end]$ 

Segtrees are usefull structures when handling range queries. In comparisson to prefix sum they have more balanced complexity times for it's operations

&nbsp;&nbsp;&nbsp; Prefix sum 
- Build: $O(n)$
- Query: $O(1)$
- Update: $O(n)$

&ensp;

&nbsp;&nbsp;&nbsp; Segment Tree 
- Build: $O(n)$
- Query: $O(log \ n)$
- Update: $O(log \ n)$

Thus, in cases you need to do n queries your complexity turns to be $n.log \ n$ instead of
$ n^2 $ 

# Implementation ideas

- Build

    The main idea is to recusively construct your the left and right child nodes of your current node and with the children values produce its own. The most commom implementation is with a array of $2n$ size (since the max number of ), and setting your children $2i + 1$ and $2i + 2$ to every position 

- Query

    The queries are too made with a recursive function that goes down in your tree. This recursive function should know your full range, node position and node range. When you find a node wich its range is complety contained inside your query's range you return its values. If it is complety out of your range you return a dummy value. Else you go down in your tree;


- Update

    To update you just go down in your tree until find the leaf you want and then update its path until the root.

You can se a implementation of a segtree in regular.cpp file.