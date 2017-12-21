#include <iostream>

#include "../utils/utils.h"

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* genRandInput(size_t node_num, int kMinValue, int kMaxValue) {
  ListNode* head = NULL;
  if (!node_num) return head;

  head = new ListNode(randint(kMinValue, kMinValue));
  ListNode* cur_pos = head;

  for (size_t i = 1; i < node_num; ++i) {
    int val = randint(kMinValue, kMaxValue);
    cur_pos->next = new ListNode(val);
    cur_pos = cur_pos->next;
  }
  return head;
}

void emptyList(ListNode* head) {
  ListNode* cur = head;
  ListNode* next = cur;

  while (cur) {
    next = cur->next;
    delete cur;
    cur = next;
  }
}

void printLinkedList(ListNode* head) {
  ListNode* cur_pos = head;
  while (cur_pos) {
    std::cout << cur_pos->val << std::endl;
    cur_pos = cur_pos->next;
  }
}

ListNode* merge(ListNode* list1, ListNode* list2) {
  if (!list1)
    return list2;
  else if (!list2)
    return list1;
  else if (!list1 && list2)
    return NULL;

  ListNode dummy = ListNode(0);
  ListNode* p = &dummy;
  while (list1 && list2) {
    if (list1->val < list2->val) {
      p->next = list1;
      list1 = list1->next;
    } else {
      p->next = list2;
      list2 = list2->next;
    }
    p = p->next;
  }

  if (list1)
    p->next = list1;
  else if (list2)
    p->next = list2;
  return dummy.next;
}

ListNode* sortList(ListNode* start) {
  if (start == NULL || start->next == NULL) return start;

  ListNode* slow = start;
  ListNode* fast = start;
  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  fast = slow->next;
  slow->next = NULL;
  ListNode* list1 = sortList(start);
  ListNode* list2 = sortList(fast);
  return merge(list1, list2);
}

int main() {
  int kMinValue = -15;
  int kMaxValue = 15;

  int node_num = 10;
  ListNode* head = genRandInput(node_num, kMinValue, kMaxValue);
  printLinkedList(head);
  head = sortList(head);

  std::cout << "sorted :" << std::endl;
  printLinkedList(head);
  emptyList(head);
  return 0;
}
