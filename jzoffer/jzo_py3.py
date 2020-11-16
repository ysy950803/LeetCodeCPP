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
        if head is None or head.next is None:
            return head
        cur = head
        while cur.next is not None:
            old_head = head  # cache old head
            head = cur.next  # update new head
            cur.next = cur.next.next
            head.next = old_head
        return head
        # if head is None or head.next is None:
        #     return head
        # lst = []
        # while head is not None:
        #     lst.append(head)
        #     head = head.next
        # lst[0].next = None
        # for i in range(1, len(lst)):
        #     lst[i].next = lst[i - 1]
        # return lst[-1]

    def reverse1(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        old_head = head
        while head.next is not None:
            old_next = head.next
            head.next = head.next.next
            old_next.next = old_head
            old_head = old_next
        return old_head

    def reversePrint(self, head: ListNode) -> List[int]:
        if head is None:
            return []
        if head.next is None:
            return [head.val]
        lst = []
        cur = self.reverse(head)
        while cur is not None:
            lst.append(cur.val)
            cur = cur.next
        return lst

    # 递归
    def reverse2(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
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
        # while cur.next is not None:
        #     cur = cur.next
        #     count += 1
        #     if count == k:
        #         cur.next = None
        #         break
        # return Solution2().reverse(r_head)
        if head is None or head.next is None:
            return head
        lst = []
        while head is not None:
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
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        if l1.val > l2.val:
            l_small = l2
            l_large = l1
        else:
            l_small = l1
            l_large = l2
        merge_head = l_small
        while l_small is not None:
            if l_large is not None and l_small.val <= l_large.val:
                if l_small.next is not None and l_large.val <= l_small.next.val or l_small.next is None:
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
        if head is None:
            return None
        old_lst = []
        while head is not None:
            old_lst.append(head)
            head = head.next
        rand_indexes = []
        new_lst = []
        for n in old_lst:
            if n.random is None:
                rand_indexes.append(None)
            else:
                rand_indexes.append(old_lst.index(n.random))
            new_n = Node(n.val)
            new_lst.append(new_n)
        for i in range(len(new_lst) - 1):
            n = new_lst[i]
            n.next = new_lst[i + 1]
            if rand_indexes[i] is not None:
                n.random = new_lst[rand_indexes[i]]
        last_n = new_lst[-1]
        if rand_indexes[-1] is not None:
            last_n.random = new_lst[rand_indexes[-1]]
        return new_lst[0]


# LC：剑指 Offer 52
# NC：JZ36
class Solution6:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if headA is None or headB is None:
            return None
        a_lst = []
        head1 = headA
        while head1 is not None:
            a_lst.append(head1)
            head1 = head1.next
        b_lst = []
        head2 = headB
        while head2 is not None:
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
        if ox_i is None:
            return None
        return a_lst[ox_i]

    # 入度
    def getIntersectionNode2(self, headA: ListNode, headB: ListNode) -> ListNode:
        if headA is None or headB is None:
            return None
        in_counts = {}
        head1 = headA
        while head1 is not None:
            in_counts[head1] = 1
            head1 = head1.next
        head2 = headB
        while head2 is not None:
            if head2 in in_counts:
                break
            head2 = head2.next
        return head2


# NC：JZ56
class Solution7:
    def deleteDuplication(self, pHead: ListNode):
        if pHead is None or pHead.next is None:
            return pHead
        dup_map = {}
        cur = pHead
        while cur is not None:
            if cur.val not in dup_map:
                dup_map[cur.val] = False
            else:
                dup_map[cur.val] = True
            cur = cur.next
        pPre = ListNode(-1)
        pPre.next = pHead
        new_head = None
        while pHead is not None:
            if dup_map[pHead.val] is True:
                pPre.next = pHead.next
                pHead.next = None
                pHead = pPre.next
            else:
                if new_head is None:
                    # cache first not dup node as new head
                    new_head = pHead
                pPre = pHead
                pHead = pHead.next
        return new_head


# LC：剑指 Offer 18
class Solution8:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        if head is None:
            return head
        if head.next is None:
            return None if head.val == val else head
        pre = ListNode(-1)
        pre.next = head
        new_head = None
        while head is not None:
            if head.val == val:
                pre.next = head.next
                head.next = None
                head = pre.next
            else:
                if new_head is None:
                    new_head = head
                pre = head
                head = head.next
        return new_head


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
    #
    # head = ListNode(1, ListNode(2, ListNode(3)))
    # print(Solution2().reversePrint(head))
    # head = ListNode(1, ListNode(2, ListNode(3)))
    # head = Solution2().reverse2(head)
    # while head is not None:
    #     print(head.val, end=" ")
    #     head = head.next
    #
    # head = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))
    # head = Solution3().getKthFromEnd(head, 2)
    # while head is not None:
    #     print(head.val, end=" ")
    #     head = head.next
    #
    # l1 = ListNode(1, ListNode(2, ListNode(4)))
    # l2 = ListNode(1, ListNode(3, ListNode(4)))
    # head = Solution4().mergeTwoLists(l1, l2)
    # while head is not None:
    #     print(head.val, end=" ")
    #     head = head.next

    head = Solution7().deleteDuplication(ListNode(2, ListNode(1, ListNode(2, ListNode(4)))))
    while head is not None:
        print(head.val, end=" ")
        head = head.next
