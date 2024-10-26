//leetcode #2 两数相加-链表
// 迭代法 处理进位问题

#include <iostream>

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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL; // 用于移动当前指针和保存结果的链表节点
        ListNode* head = NULL;
        ListNode* next; // 用于新建下一节点
        int add = 0; // 解决进位问题 若8+4=12 在当前位节点应该保存2 然后记录进位1
        
        // 两个链表可能不等长
        // 当他们都没有结束时
        while(l1 != NULL && l2 !=NULL) {
            int value = l1->val + l2->val + add;
            // 检查value有无进位 并新建下一节点
            if(value >= 10){
                next = new ListNode(value % 10); // 超过10就取个位
                add = 1;
            } else {
                next = new ListNode(value);
                add = 0;
            }
            // 接链表
            if(result == NULL) {
                result = next; // 创建新接点
                head = next; // 记录头节点
            } else {
                result->next = next; // 接链表
                result = result->next; // 移动当前节点到最前端
            }
            l1 = l1->next;
            l2 = l2->next; // 递推链表
        }
        // 当他们不等长时 复制粘贴
        while(l1 != NULL) {
            int value = l1->val + add;
            // 检查value有无进位 并新建下一节点
            if(value >= 10){
                next = new ListNode(value % 10); // 超过10就取个位
                add = 1;
            } else {
                next = new ListNode(value);
                add = 0;
            }
            // 接链表
            if(result == NULL) {
                result = next; // 创建新接点
                head = next; // 记录头节点
            } else {
                result->next = next; // 接链表
                result = result->next; // 移动当前节点到最前端
            }
            l1 = l1->next;
        }
        while(l2 != NULL) {
            int value = l2->val + add;
            // 检查value有无进位 并新建下一节点
            if(value >= 10){
                next = new ListNode(value % 10); // 超过10就取个位
                add = 1;
            } else {
                next = new ListNode(value);
                add = 0;
            }
            // 接链表
            if(result == NULL) {
                result = next; // 创建新接点
                head = next; // 记录头节点
            } else {
                result->next = next; // 接链表
                result = result->next; // 移动当前节点到最前端
            }
            l2 = l2->next;
        }
        // 最后记得处理最后一位的进位问题
        if(add > 0) {
            next = new ListNode(1);
            result->next = next;
        }
        return head;
    }
};


/*
---
Solution2 优化版
在开始检查l1 l2是否为空 
若都不为空则开始循环 这样不用再在后两次循环的时候都重复检查result是否为NULL
---
*/

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL; // 用于移动当前指针和保存结果的链表节点
        ListNode* head = NULL;
        ListNode* next; // 用于新建下一节点
        int add = 0; // 解决进位问题 若8+4=12 在当前位节点应该保存2 然后记录进位1
        
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        // 两个链表可能不等长
        // 当他们都没有结束时
        while(l1 != NULL && l2 !=NULL) {
            int value = l1->val + l2->val + add;
            // 检查value有无进位 并新建下一节点
            if(value >= 10){
                next = new ListNode(value % 10); // 超过10就取个位
                add = 1;
            } else {
                next = new ListNode(value);
                add = 0;
            }
            // 接链表
            if(result == NULL) {
                result = next; // 创建新接点
                head = next; // 记录头节点
            } else {
                result->next = next; // 接链表
                result = result->next; // 移动当前节点到最前端
            }
            l1 = l1->next;
            l2 = l2->next; // 递推链表
        }
        // 当他们不等长时 复制粘贴
        while(l1 != NULL) {
            int value = l1->val + add;
            // 检查value有无进位 并新建下一节点
            if(value >= 10){
                next = new ListNode(value % 10); // 超过10就取个位
                add = 1;
            } else {
                next = new ListNode(value);
                add = 0;
            }

            result->next = next; // 接链表
            result = result->next; // 移动当前节点到最前端
            l1 = l1->next;
        }
        while(l2 != NULL) {
            int value = l2->val + add;
            // 检查value有无进位 并新建下一节点
            if(value >= 10){
                next = new ListNode(value % 10); // 超过10就取个位
                add = 1;
            } else {
                next = new ListNode(value);
                add = 0;
            }

            result->next = next; // 接链表
            result = result->next; // 移动当前节点到最前端
            l2 = l2->next;
        }
        // 最后记得处理最后一位的进位问题
        if(add > 0) {
            next = new ListNode(1);
            result->next = next;
        }
        return head;
    }
};