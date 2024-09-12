/*

    Here we describe the algorithm in its simplest form. The minimum spanning tree is built
    gradually by adding edges one at a time. At first the spanning tree consists only of a 
    single vertex (chosen arbitrarily). Then the minimum weight edge outgoing from this vertex 
    is selected and added to the spanning tree. After that the spanning tree already consists 
    of two vertices. Now select and add the edge with the minimum weight that has one end in 
    an already selected vertex (i.e. a vertex that is already part of the spanning tree), and 
    the other end in an unselected vertex. And so on, i.e. every time we select and add the edge 
    with minimal weight that connects one selected vertex with one unselected vertex. The process 
    is repeated until the spanning tree contains all vertices 
    (or equivalently until we have  $n - 1$  edges).


*/