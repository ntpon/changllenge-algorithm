# Invert Binary Tree

## Problem

- คำอธิบาย

  - ให้ binary tree ของเลขจำนวนเต็มมา จงสร้างฟังก์ชันเพื่อทำการ reverse node ทุกตัว จากซ้ายไปขวา และ จากขวาไปซ้าย

- สิ่งที่โจทย์ให้มา

  - binary tree ของเลขจำนวนเต็ม

- ภาพรวมของการปัญหา
  - เริ่มจากดูปัญหาเล็กๆก่อนไปปัญหาใหญ่ การสลับตำแหน่งกันนั้น ให้เริ่มจากตัว root ว่ามีกี่ children ให้สลับ แค่ลูกสองตัวนั้นก่อน ยังไม่ต้องสลับภายใน
  - จากนั้นไล่สลับไปเรื่อยๆ ทีละ level ซ้ายไป ขวา และ ขวามาซ้าย
  - ปัญหานี้จะแก้ไขได้ง่ายด้วยการเขียนโปรแกรมแบบ Recusive

## Solution

```c++
#include<iostream>
using namespace std;
struct TreeNode {
     int val;
    TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

int main () {
    return 0;
}
```

### Ref

- https://leetcode.com/problems/invert-binary-tree/
- https://www.udemy.com/course/50-problems/
