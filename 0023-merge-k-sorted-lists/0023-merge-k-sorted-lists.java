import java.util.PriorityQueue;

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) return null;

        PriorityQueue<ListNode> pq = new PriorityQueue<>(
            (a, b) -> a.val - b.val
        );

        // Step 1: add first node of each list
        for (ListNode list : lists) {
            if (list != null) {
                pq.add(list);
            }
        }

        // Dummy node
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;

        // Step 2: process heap
        while (!pq.isEmpty()) {
            ListNode node = pq.poll();
            tail.next = node;
            tail = tail.next;

            // add next node of same list
            if (node.next != null) {
                pq.add(node.next);
            }
        }

        return dummy.next;
    }
}