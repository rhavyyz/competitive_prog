# Overview and motivation
Now we have other problem. We need to update a range of elements not only a single one. Using the regular approach, it means updating each leaf of an arbitrary range, we acheave the complexity $O(n.log \ n)$. So we need to use other approach, called lazy propagation, to reduce the update time complexity. In advance I can say we still mantain all the operations time complexities in the same way.


&nbsp;&nbsp;&nbsp; Segment Tree (range update) 
- Build: $O(n)$
- Query: $O(log \ n)$
- Update: $O(log \ n)$

# Implementation ideas


To make the lazy propagation work we are going to register this updates to be made later with a second tree that stores this changes in each node. Then, while quering, every time we reach a node we verify if it need some update, and if true we do it. In the update function , it will be done basicly in the same way it was done in the regular approach, but when reached a node with a range contained inside our change range, we update it's own value and save the change value to its children to be made later.

> Ps: Basicly the query function will handle to update values down to a certain node, while the update function only cares until find the first element it can completly cover

You can se a implementation of a segtree with range update in range_update.cpp file.