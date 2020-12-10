from typing import List


# LC：面试题4
# NC：JZ1
class Solution1:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False
        for row in matrix:
            if target > row[-1]:
                continue
            if target < row[0]:
                continue
            for i in row:
                if i == target:
                    return True
        return False


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x, _next=None):
        self.val = x
        self.next = _next


# LC：剑指 Offer 06
# NC：JZ3
class Solution2:
    # 非递归
    def reverse(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        cur = head
        while cur.next:
            old_head = head  # cache old head
            head = cur.next  # update new head
            cur.next = cur.next.next
            head.next = old_head
        return head
        # if not head or not head.next:
        #     return head
        # lst = []
        # while head:
        #     lst.append(head)
        #     head = head.next
        # lst[0].next = None
        # for i in range(1, len(lst)):
        #     lst[i].next = lst[i - 1]
        # return lst[-1]

    def reverse1(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        old_head = head
        while head.next:
            old_next = head.next
            head.next = head.next.next
            old_next.next = old_head
            old_head = old_next
        return old_head

    def reversePrint(self, head: ListNode) -> List[int]:
        if not head:
            return []
        if not head.next:
            return [head.val]
        lst = []
        cur = self.reverse(head)
        while cur:
            lst.append(cur.val)
            cur = cur.next
        return lst

    # 递归
    def reverse2(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        res = self.reverse2(head.next)
        head.next.next = head
        head.next = None
        return res


# LC：剑指 Offer 22
# NC：JZ14
class Solution3:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        # r_head = Solution2().reverse(head)
        # count = 0
        # cur = ListNode(-1, r_head)
        # while cur.next:
        #     cur = cur.next
        #     count += 1
        #     if count == k:
        #         cur.next = None
        #         break
        # return Solution2().reverse(r_head)
        if not head or not head.next:
            return head
        lst = []
        while head:
            lst.append(head)
            head = head.next
        if k > len(lst) or k < 1:
            return None
        k_head = lst[len(lst) - k]
        return k_head


# LC：剑指 Offer 25
# NC：JZ16
class Solution4:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        if not l2:
            return l1
        if l1.val > l2.val:
            l_small = l2
            l_large = l1
        else:
            l_small = l1
            l_large = l2
        merge_head = l_small
        while l_small:
            if l_large and l_small.val <= l_large.val:
                if l_small.next and l_large.val <= l_small.next.val or not l_small.next:
                    old_large_next = l_large.next
                    l_large.next = l_small.next
                    l_small.next = l_large
                    l_large = old_large_next
            l_small = l_small.next
        return merge_head


# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


# LC：剑指 Offer 35
# NC：JZ25
class Solution5:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return None
        old_lst = []
        while head:
            old_lst.append(head)
            head = head.next
        rand_indexes = []
        new_lst = []
        for n in old_lst:
            if not n.random:
                rand_indexes.append(None)
            else:
                rand_indexes.append(old_lst.index(n.random))
            new_n = Node(n.val)
            new_lst.append(new_n)
        for i in range(len(new_lst) - 1):
            n = new_lst[i]
            n.next = new_lst[i + 1]
            if rand_indexes[i]:
                n.random = new_lst[rand_indexes[i]]
        last_n = new_lst[-1]
        if rand_indexes[-1]:
            last_n.random = new_lst[rand_indexes[-1]]
        return new_lst[0]


# LC：剑指 Offer 52
# NC：JZ36
class Solution6:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None
        a_lst = []
        head1 = headA
        while head1:
            a_lst.append(head1)
            head1 = head1.next
        b_lst = []
        head2 = headB
        while head2:
            b_lst.append(head2)
            head2 = head2.next
        a_len = len(a_lst)
        b_len = len(b_lst)
        ox_i = None
        for i in range(min(a_len, b_len)):
            if a_lst[a_len - i - 1] == b_lst[b_len - i - 1]:
                ox = True
                ox_i = a_len - i - 1
            else:
                ox = False
            if ox is False:
                break
        if not ox_i:
            return None
        return a_lst[ox_i]

    # 入度
    def getIntersectionNode2(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None
        in_counts = {}
        head1 = headA
        while head1:
            in_counts[head1] = 1
            head1 = head1.next
        head2 = headB
        while head2:
            if head2 in in_counts:
                break
            head2 = head2.next
        return head2


# NC：JZ56
class Solution7:
    def deleteDuplication(self, pHead: ListNode):
        if not pHead or not pHead.next:
            return pHead
        dup_map = {}
        cur = pHead
        while cur:
            if cur.val not in dup_map:
                dup_map[cur.val] = False
            else:
                dup_map[cur.val] = True
            cur = cur.next
        pPre = ListNode(-1)
        pPre.next = pHead
        new_head = None
        while pHead:
            if dup_map[pHead.val] is True:
                pPre.next = pHead.next
                pHead.next = None
                pHead = pPre.next
            else:
                if not new_head:
                    # cache first not dup node as new head
                    new_head = pHead
                pPre = pHead
                pHead = pHead.next
        return new_head


# LC：剑指 Offer 18
class Solution8:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        if not head:
            return head
        if not head.next:
            return None if head.val == val else head
        pre = ListNode(-1)
        pre.next = head
        new_head = None
        while head:
            if head.val == val:
                pre.next = head.next
                head.next = None
                head = pre.next
            else:
                if not new_head:
                    new_head = head
                pre = head
                head = head.next
        return new_head


class TreeNode:
    def __init__(self, x, _left=None, _right=None):
        self.val = x
        self.left: TreeNode = _left
        self.right: TreeNode = _right


# LC：剑指 Offer 07
# NC：JZ4
class Solution9:
    # 返回构造的TreeNode根节点
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder or len(preorder) == 0:
            return None
        n = TreeNode(preorder[0])
        if len(preorder) == 1:
            return n
        root_idx = inorder.index(n.val)  # root节点在中序里的index
        left_size = root_idx  # 也即是左子树size
        n.left = self.buildTree(preorder[1: 1 + left_size], inorder[:root_idx])
        n.right = self.buildTree(preorder[1 + left_size:], inorder[root_idx + 1:])
        return n

    def bfs_print(self, node: TreeNode):
        if not node:
            return
        queue = [node]
        while queue:
            q_size = len(queue)
            print(f"q_size {q_size}")
            for i in range(q_size):
                n = queue.pop(0)
                print(n.val)
                if n.left:
                    queue.append(n.left)
                if n.right:
                    queue.append(n.right)


# LC：剑指 Offer 26
# NC：JZ17
class Solution10:
    def is_sub(self, sub_A: TreeNode, B: TreeNode) -> bool:
        queue_b = [B]
        queue_a = [sub_A]
        while queue_b:
            q_size = len(queue_b)
            for i in range(q_size):
                b = queue_b.pop(0)
                a = queue_a.pop(0)
                if (b.val is not a.val) \
                        or (b.left and (not a.left)) \
                        or (b.right and (not a.right)):
                    return False
                if b.left:
                    queue_b.append(b.left)
                    queue_a.append(a.left)
                if b.right:
                    queue_b.append(b.right)
                    queue_a.append(a.right)
        return True

    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        if not A or not B:
            return False
        queue = [A]
        sub_As = []
        while queue:
            q_size = len(queue)
            for i in range(q_size):
                a = queue.pop(0)
                if a.val == B.val:
                    sub_As.append(a)
                if a.left:
                    queue.append(a.left)
                if a.right:
                    queue.append(a.right)
        if len(sub_As) == 0:
            return False
        for sub_A in sub_As:
            if self.is_sub(sub_A, B):
                return True
        return False


# LC：剑指 Offer 27
# NC：JZ18
class Solution11:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        root.left, root.right = self.mirrorTree(root.right), self.mirrorTree(root.left)
        return root


# LC：剑指 Offer 32 - I
# NC：JZ22
class Solution12:
    # BFS
    def levelOrder(self, root: TreeNode) -> List[int]:
        tree_arr = []
        if not root:
            return tree_arr
        queue = [root]
        while queue:
            q_size = len(queue)
            for i in range(q_size):
                n = queue.pop(0)
                tree_arr.append(n.val)
                if n.left:
                    queue.append(n.left)
                if n.right:
                    queue.append(n.right)
        return tree_arr


# LC：剑指 Offer 33
# NC：JZ23
class Solution13:
    def post_order(self, postorder: List[int], root: TreeNode):
        if not root:
            return
        self.post_order(postorder, root.left)
        self.post_order(postorder, root.right)
        postorder.append(root.val)

    def verifyPostorder(self, postorder: List[int]) -> bool:
        if not postorder or len(postorder) <= 1:
            return True
        # 后序遍历的话，根节点肯定是最后一个元素，先构建二叉搜索树
        root = TreeNode(postorder[-1])
        for i in range(len(postorder) - 2, -1, -1):
            v = postorder[i]
            cur = root
            while True:
                parent = cur
                if v < cur.val:
                    cur = cur.left
                    if not parent.left:
                        parent.left = TreeNode(v)
                        break
                else:
                    cur = cur.right
                    if not parent.right:
                        parent.right = TreeNode(v)
                        break
        new_list = []
        self.post_order(new_list, root)
        # print(new_list)
        return new_list == postorder


# LC：剑指 Offer 34
# NC：JZ24
class Solution14:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        paths, path = [], []

        def visit(root: TreeNode, tar: int):
            if not root:
                return
            path.append(root.val)
            tar -= root.val
            if tar == 0 and not root.left and not root.right:
                paths.append(list(path))
            visit(root.left, tar)
            visit(root.right, tar)
            path.pop()

        visit(root, sum)
        return paths


class Solution15:
    # LC：剑指 Offer 36（双向循环链表）
    def treeToDoublyList(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        pre_head = self.treeToDoublyList(root.left)
        nxt_head = self.treeToDoublyList(root.right)

        if pre_head:
            pre_tail = pre_head.left
            pre_tail.right = root
            root.left = pre_tail
        else:
            pre_head = root

        if nxt_head:
            nxt_tail = nxt_head.left
            nxt_head.left = root
            root.right = nxt_head
        else:
            nxt_tail = root

        pre_head.left = nxt_tail
        nxt_tail.right = pre_head
        return pre_head

    def __init__(self):
        self.pre_head = None
        self.pre_tail = None

    # NC：JZ26（双向链表，无循环，首尾不相连）
    def Convert(self, root):
        if not root:
            return None
        self.Convert(root.left)
        if self.pre_head:
            self.pre_tail.right = root
            root.left = self.pre_tail
        else:
            self.pre_head = root
        self.pre_tail = root
        self.Convert(root.right)
        return self.pre_head


# LC：剑指 Offer 55 - I
# NC：JZ38
class Solution16:
    def maxDepth(self, root: TreeNode) -> int:
        return 0 if not root else 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))


# LC：剑指 Offer 55 - II
# NC：JZ39
class Solution17:
    def maxDepth(self, root: TreeNode) -> int:
        return 0 if not root else 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

    def isBalanced(self, root: TreeNode) -> bool:
        if not root:
            return True
        return \
            abs(self.maxDepth(root.left) - self.maxDepth(root.right)) <= 1 \
            and self.isBalanced(root.left) \
            and self.isBalanced(root.right)


class TreeLinkNode:
    def __init__(self, x):
        self.val = x
        self.left: TreeLinkNode = None
        self.right: TreeLinkNode = None
        self.next: TreeLinkNode = None


# NC：JZ57
class Solution18:
    def GetNext(self, pNode: TreeLinkNode) -> TreeLinkNode:
        if not pNode:
            return None
        root = pNode
        while root.next:
            root = root.next
        Solution15().Convert(root)
        return pNode.right


# LC：剑指 Offer 28
# NC：JZ58
class Solution19:
    def check_symmetric(self, lst) -> int:
        lst_len = len(lst)
        null_count = 0
        for i in range(lst_len // 2):
            left = lst[i]
            right = lst[lst_len - 1 - i]
            if not left:
                null_count += 1
            if not right:
                null_count += 1
            if (not left or not right or left.val != right.val) and (left or right):
                return 0
        return 2 if null_count == lst_len else 1

    # Time Limit Exceeded
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        queue = [root]
        dep = 1
        while queue:
            q_size = pow(2, dep - 1)
            dep += 1
            for i in range(q_size):
                n = queue.pop(0)
                if not n:
                    queue.append(None)
                    queue.append(None)
                else:
                    queue.append(n.left)
                    queue.append(n.right)
            chk = self.check_symmetric(queue)
            if chk == 0:
                return False
            if chk == 2:
                break
        return True

    def isSymmetric2(self, root: TreeNode) -> bool:
        if not root:
            return True

        def symmetric(left: TreeNode, right: TreeNode) -> bool:
            if not left and not right:
                return True
            if not left or not right or left.val != right.val:
                return False
            return symmetric(left.left, right.right) and symmetric(left.right, right.left)

        return symmetric(root.left, root.right)


# LC：剑指 Offer 32 - III
# NC：JZ59
class Solution20:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        if not root:
            return res
        queue = [root]
        ltr = True
        while queue:
            q_size = len(queue)
            line = []
            for i in range(q_size):
                n = queue.pop(0)
                if not n:
                    continue
                line.append(n.val)
                if n.left:
                    queue.append(n.left)
                if n.right:
                    queue.append(n.right)
            if line:
                if not ltr:
                    line.reverse()
                res.append(line)
                ltr = not ltr
        return res


# LC：剑指 Offer 32 - II
# NC：JZ60
class Solution21:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        if not root:
            return res
        queue = [root]
        while queue:
            q_size = len(queue)
            line = []
            for i in range(q_size):
                n = queue.pop(0)
                if not n:
                    continue
                line.append(n.val)
                if n.left:
                    queue.append(n.left)
                if n.right:
                    queue.append(n.right)
            if line:
                res.append(line)
        return res


class Solution22:
    def __init__(self):
        self.k_count = 0

    # LC：剑指 Offer 54
    # k大（1<=k<=节点数）
    def kthLargest(self, root: TreeNode, k: int) -> int:
        fixed_queue = []

        def find_large(node: TreeNode):
            if not node:
                return
            find_large(node.right)
            if self.k_count < k:
                fixed_queue.append(node.val)
                self.k_count += 1
            find_large(node.left)

        find_large(root)
        return fixed_queue[-1]

    # NC：JZ62
    # k小（注意：k>0，可能超过节点数）
    def KthNode(self, pRoot, k):
        fixed_queue = []

        def find_small(node):
            if not node:
                return
            find_small(node.left)
            if self.k_count < k:
                fixed_queue.append(node)
                self.k_count += 1
            find_small(node.right)

        find_small(pRoot)
        if k == 0 or k > len(fixed_queue):
            return None
        else:
            return fixed_queue[-1]


# LC：剑指 Offer 37
class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if not root or root.val is None:
            return "[]"
        ret_str = '[' + str(root.val)
        null_str = "null"

        queue = [root]
        q_val = []
        while queue:
            q_size = len(queue)
            for i in range(q_size):
                n = queue.pop(0)
                if n.left:
                    queue.append(n.left)
                    q_val.append(str(n.left.val))
                else:
                    q_val.append(null_str)
                if n.right:
                    queue.append(n.right)
                    q_val.append(str(n.right.val))
                else:
                    q_val.append(null_str)
        q_val_size = len(q_val)
        for i in range(q_val_size - 1, -1, -1):
            if q_val[i] == null_str:
                q_val.pop()
            else:
                break
        if len(q_val) > 0:
            ret_str += (',' + ','.join(q_val))
        return ret_str + ']'

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if not data or data == "[]":
            return None
        data = data.replace('[', '').replace(']', '')
        arr = data.split(',')
        null_str = "null"
        if not arr or arr[0] == null_str:
            return None
        root = TreeNode(arr[0])
        next_dep_start_idx = 0

        queue = [root]
        arr_size = len(arr)
        while queue:
            q_size = len(queue)
            for i in range(q_size):
                n = queue.pop(0)
                next_dep_start_idx += 1
                if next_dep_start_idx >= arr_size:
                    break
                left_str = arr[next_dep_start_idx]
                if left_str != null_str:
                    n.left = TreeNode(int(left_str))
                    queue.append(n.left)
                next_dep_start_idx += 1
                if next_dep_start_idx >= arr_size:
                    break
                right_str = arr[next_dep_start_idx]
                if right_str != null_str:
                    n.right = TreeNode(int(right_str))
                    queue.append(n.right)
        return root


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))

# LC：剑指 Offer 68 - I
class Solution24:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root or not p and not q:
            return None
        if not p:
            return q
        if not q:
            return p
        p_val = p.val
        q_val = q.val
        cur = root
        while cur:
            if cur.val >= p_val and cur.val >= q_val:
                if cur.val == p_val or cur.val == q_val:
                    break
                cur = cur.left
            elif cur.val <= p_val and cur.val <= q_val:
                if cur.val == p_val or cur.val == q_val:
                    break
                cur = cur.right
            elif p_val <= cur.val <= q_val or p_val >= cur.val >= q_val:
                break
        return cur


# LC：剑指 Offer 68 - II
class Solution25:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if not root or not p and not q:
            return None
        if not p:
            return q
        if not q:
            return p
        node_queue = []

        def find_node(node: TreeNode, val: int) -> bool:
            if not node:
                return False
            node_queue.append(node)
            if node.val == val:
                return True
            if not find_node(node.left, val) and not find_node(node.right, val):
                node_queue.pop()
                return False
            else:
                return True

        find_node(root, p.val)
        p_queue = list(node_queue)
        node_queue.clear()
        find_node(root, q.val)
        q_queue = list(node_queue)
        idx = 0
        for i in range(min(len(p_queue), len(q_queue))):
            if p_queue[i].val == q_queue[i].val:
                idx = i
            else:
                break
        return node_queue[idx]


if __name__ == '__main__':
    print("Hello World!")
    # m = [
    #     [1, 4, 7, 11, 15],
    #     [2, 5, 8, 12, 19],
    #     [3, 6, 9, 16, 22],
    #     [10, 13, 14, 17, 24],
    #     [18, 21, 23, 26, 30]
    # ]
    # print(Solution1().findNumberIn2DArray(m, 7))

    # head = ListNode(1, ListNode(2, ListNode(3)))
    # print(Solution2().reversePrint(head))
    # head = ListNode(1, ListNode(2, ListNode(3)))
    # head = Solution2().reverse2(head)
    # while head:
    #     print(head.val, end=" ")
    #     head = head.next

    # head = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))
    # head = Solution3().getKthFromEnd(head, 2)
    # while head:
    #     print(head.val, end=" ")
    #     head = head.next

    # l1 = ListNode(1, ListNode(2, ListNode(4)))
    # l2 = ListNode(1, ListNode(3, ListNode(4)))
    # head = Solution4().mergeTwoLists(l1, l2)
    # while head:
    #     print(head.val, end=" ")
    #     head = head.next

    # head = Solution7().deleteDuplication(ListNode(2, ListNode(1, ListNode(2, ListNode(4)))))
    # while head:
    #     print(head.val, end=" ")
    #     head = head.next

    pre = [1, 2, 3, 4, 5, 6, 7]
    tin = [3, 2, 4, 1, 6, 5, 7]
    head = Solution9().buildTree(pre, tin)
    # Solution9().bfs_print(head)

    # print(Solution13().verifyPostorder([1, 3, 2, 6, 5]))
    # print(Solution13().verifyPostorder([1, 6, 3, 2, 5]))

    # root = TreeNode(5, TreeNode(2), TreeNode(3, TreeNode(2, TreeNode(3), TreeNode(1)), TreeNode(4)))
    root = TreeNode(1)
    codec = Codec()
    data = codec.serialize(root)
    print(data)
    root = codec.deserialize(data)
    print(codec.serialize(root))
