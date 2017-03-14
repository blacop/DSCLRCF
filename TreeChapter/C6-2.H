 /* c6-2.h 二叉树的二叉链表存储表示 */
 typedef struct BiTNode
 {
   TElemType data; //数据域 
   struct BiTNode *lchild,*rchild; //引用域 /* 左右孩子指针 */
 }BiTNode,*BiTree;
