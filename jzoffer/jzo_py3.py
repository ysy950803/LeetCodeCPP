from typing import List


class Solution4:
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


class Solution6:
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


class Solution22:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        r_head = Solution6().reverse(head)
        count = 0
        cur = ListNode(-1, r_head)
        while cur.next is not None:
            cur = cur.next
            count += 1
            if count == k:
                cur.next = None
                break
        return Solution6().reverse(r_head)


class Solution25:
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


if __name__ == '__main__':
    # Solution4
    # m = [
    #     [1, 4, 7, 11, 15],
    #     [2, 5, 8, 12, 19],
    #     [3, 6, 9, 16, 22],
    #     [10, 13, 14, 17, 24],
    #     [18, 21, 23, 26, 30]
    # ]
    # print(Solution4().findNumberIn2DArray(m, 7))

    # Solution6
    # head = ListNode(1, ListNode(2, ListNode(3)))
    # print(Solution6().reversePrint(head), end="\n")
    # head = ListNode(1, ListNode(2, ListNode(3)))
    # head = Solution6().reverse2(head)
    # while head is not None:
    #     print(head.val, end=" ")
    #     head = head.next

    # Solution22
    # head = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))
    # head = Solution22().getKthFromEnd(head, 2)
    # while head is not None:
    #     print(head.val, end=" ")
    #     head = head.next

    # Solution25
    l1 = ListNode(1, ListNode(2, ListNode(4)))
    l2 = ListNode(1, ListNode(3, ListNode(4)))
    head = Solution25().mergeTwoLists(l1, l2)
    while head is not None:
        print(head.val, end=" ")
        head = head.next
