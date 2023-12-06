from tree import drawTree

class Node:
    def __init__(self, value, left=None, right=None):
        self.val = value
        self.l = left
        self.r = right

tree = Node(42)

"""
    42
   /  \
  /____\
32     64
"""
tree.l = Node(32)
tree.r = Node(64)

"""
         32
        /  \
       28  36
          /  \
         33   39
"""
tree.l.l = Node(28)
tree.l.r = Node(36)
tree.l.r.l = Node(33)
tree.l.r.r = Node(39)
"""
         64
        /  \
      62    65
        \
         63
"""
tree.r.l = Node(63)
tree.r.l.r = Node(65)
tree.r.r = Node(68)

drawTree(tree)
