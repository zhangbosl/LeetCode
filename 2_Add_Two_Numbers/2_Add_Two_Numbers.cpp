#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#include <iterator>
//#include <numeric>
#include <map>
#include <variant>
#include <type_traits>
#include "../utils/printer.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
    ListNode* result;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* o1 = l1, * o2 = l2, * result = nullptr, * last = nullptr;
        int forward = 0;
        while (l1 != nullptr and l2 != nullptr) {
            auto add = l1->val + l2->val + forward;
            forward = add / 10;
            add %= 10;
            l1->val = l2->val = add;
            last = l2;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 == nullptr) {
            result = o2;
        }
        else {
            result = o1;
        }
        if (forward && last && l1 == nullptr && l2 == nullptr) {
            last->next = new ListNode(1);
        }
        this->result = result;
        while (l1 != nullptr) {
            auto add = l1->val + forward;
            forward = add / 10;
            add %= 10;
            l1->val = add;
            last = l1;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            auto add = l2->val + forward;
            forward = add / 10;
            add %= 10;
            l2->val = add;
            last = l2;
            l2 = l2->next;
        }
        if (forward) {
            last->next = new ListNode(1);
        }
        return result;
    }
    void printResult() {
        ListNode* it = result;
        while (it != nullptr) {
            cout << " -> " << it->val << endl;
            it = it->next;
        }
    }
};

int main() {
    //vector<size_t> l1 = { 2, 4, 3 };
    //vector<size_t> l2 = { 5, 6, 4 };
    //ListNode l1 = ListNode(2, &ListNode(4, &ListNode(3)));
    //ListNode l2 = ListNode(5, &ListNode(6, &ListNode(4)));
    ListNode l1 = ListNode(5);
    ListNode l2 = ListNode(5);

    Solution solution;
    auto result = solution.addTwoNumbers(&l1, &l2);

    solution.printResult();

    return 0;
}