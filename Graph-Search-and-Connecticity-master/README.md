# Graph Search and Connectivity


##OVERVIEW

###A Few Motivations:
1. check if a network is connected ( can get to anywhere from anywhere else) 
2. driving direction
3. formulate a plan [e.g. how to fill in a Sudoku puzzle - nodes = a partially completed puzzle
                                                         - arcs = filling in one new square]
4. compute the "pieces" (or "components") of a graph
               -clustering, structure of the web graph etc.

###Generic Graph Search 
####Goals: 
1. find everything findable from a given start vertex
2. don't explore anything twice ************ [Goal O(m+n) time]

####Generic Algorithm (given graph G, vertex s)
- initially s explored, all other verices un-explored
- while possible: 
  - choose an edge (u, v) with u explred and v un-explored  ( if none, halt)
  - mark v explored

######Claim: at end of the algorithm, v explresd <=> G has a path from s to v
######Proof: 
      - [=>] easy induction on number of iterations    
      - [<=] By contradiction, suppose G has a path p from s to v:      
            but v unexplored at end of the algorithm, Then exist an edge [u, w} belongs to p 
            with u explored and w un-explored     
            But the algorithm wouldn't have terminated. COntrdiction     
            
            
###BFS vs DFS
NOTE: how to choose among the possibly many "frontier" edges?   
#####1.   BFS           O(m+n) time using a queue (FIFO)  
    - explore nodes in "layers"   
    - can compute shortest paths   
    - can compute connected components of an undirected graph   
#####2.   DFS           O(m+n) time using a stack (LIFO) or via recursion   
    - explire aggressively like a maze, backtrack only when necessary  
    - compute topological ordering of directed acyclic graph   
    - compute connected components in directed graphs   


