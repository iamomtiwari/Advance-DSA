# Construct the following tree:
#       1
#      / \
#     2   3
#    / \
#   4   5

class TreeNode:
    def __init__(self, value=0, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right
def pre_order_traversal(root):
    if root is None:
        return []
    result = []
    result.append(root.value)
    result.extend(pre_order_traversal(root.left))
    result.extend(pre_order_traversal(root.right))
    return result
def in_order_traversal(root):
    if root is None:
        return []
    result = []
    result.extend(in_order_traversal(root.left))
    result.append(root.value)
    result.extend(in_order_traversal(root.right))
    return result
def post_order_traversal(root):
    if root is None:
        return []
    result = []
    result.extend(post_order_traversal(root.left))
    result.extend(post_order_traversal(root.right))
    result.append(root.value)
    return result

root = TreeNode(1)
root.left = TreeNode(2, TreeNode(4), TreeNode(5))
root.right = TreeNode(3)

print("Pre-order Traversal:", pre_order_traversal(root))  # Output: [1, 2, 4, 5, 3]
print("In-order Traversal:", in_order_traversal(root))    # Output: [4, 2, 5, 1, 3]
print("Post-order Traversal:", post_order_traversal(root))# Output: [4, 5, 2, 3, 1]
