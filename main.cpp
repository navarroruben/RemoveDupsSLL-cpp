// Ruben Navarro
// 02/13/2020
// Remove duplicates from singly linked list

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void displayList(ListNode* head) {

    if (head == NULL) {
        std::cout << "head is NULL\n";
        return;
    }

    std::cout << "[";
    while (head != NULL) {
        std::cout << head->val;
        if (head->next != NULL)
            std::cout << ", ";
        head = head->next;
    }
    std::cout << "]" << std::endl;
}

int main() {

    // value to be removed
    int val = 6;

    // list construction
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next->next = nullptr;

    // error checking: returns NULL is head is NULL
    if (head == NULL) {
        displayList(head);
        return 0;
    }

    // error checking:
    if (head->next == NULL && head->val == val) {
        // displays head only if a single node and values differ
        if (head->next == NULL && head->val != val) {
            displayList(head);
            return 0;
        }
        // displays head only if a single node and values differ
        else if (head->next == NULL && head->val == val) {
            head = NULL;
            displayList(head);
            return 0;
        }
    }

    // Pointers to ListNode for
    ListNode * curr = head;
    ListNode * prev = curr;

    // searches through the list to remove given value
    if (head->val == val && head->next != NULL) {

        while (head != NULL && head->val == val) {
            head->val = head->next->val;
            head->next = head->next->next;
            if (head->val == val && head->next == NULL) {
                head = NULL;
                displayList(head);
                return 0;
            }
        }
    }

    // searches through the list to remove given value using a second set of pointers
    if (curr != NULL && curr->val != val) {
        while (curr != NULL) {
            prev = curr;
            curr = curr->next;

            if (curr == NULL)
                break;

            while (curr != NULL &&  curr->val == val) {
                prev->next = curr->next;
                curr = prev->next;
            }
        }
    }
    // displays list;
    displayList(head);
    return 0;
}
