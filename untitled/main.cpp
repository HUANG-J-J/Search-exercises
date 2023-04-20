#include <iostream>

//作业：
//读取10个元素{87,7,60,80,59,34,86,99,21,3},然后建立二叉查找树并排序，中序遍历输出，针对有序后的元素，存入一个长度为10的数组中，通过折半查找找到21的下标。
//二叉排序树，中序遍历，折半查找
#define length 10

typedef struct BSTNode {
    int key;
    struct BSTNode* lchild,*rchild;
}BSTNode,*BST;

void BuildBST(BST& T,int*arr,int len);

bool InsertBST(BST& T,int key);

void InOrder(BST T,int*arr);

int BinarySearch(int* arr,int key,int len);

int main() {
    BST T=NULL;
    int pos=0;
    int *ARR=(int*) calloc(length,sizeof(int));
    int key=21;
    int i=0;
    for (i = 0; i < length; i++) {
        scanf("%d", &ARR[i]);
    }
    BuildBST(T, ARR, length);
    InOrder(T,ARR);
    printf("\n");
    for (i = 0; i < length; i++){
        printf("%3d", ARR[i]);
    }
    pos= BinarySearch(ARR,key,length);
    printf("\npos=%d\n",pos);
    return 0;
}

void BuildBST(BST& T,int*arr,int len){
    for(int i=0;i<len;i++) {
        InsertBST(T, arr[i]);
    }
}

bool InsertBST(BST& T,int key){
    if(T==NULL) {
        T = (BSTNode *) calloc(1, sizeof(BSTNode));
        if(T) T->key=key;
        return true;
    }
    if(key<T->key){
        return InsertBST(T->lchild,key);
    }else if (key>T->key){
        return InsertBST(T->rchild,key);
    }else{
        return false;
    }
}

void InOrder(BST T,int*a){
    static int c=0;
    if(T) {
        InOrder(T->lchild,a);
        printf("%3d",T->key);
        a[c++]=T->key;
        InOrder(T->rchild,a);
    }
}

int BinarySearch(int* arr,int key,int len){
    int low=0;
    int high=len-1;
    int mid=(low+high)/2;
    while(high>=low){
        if(key==arr[mid]){
            return mid;
        }else if(key<arr[mid]){
            high=mid-1;
        }else if(key>arr[mid]){
            low=mid+1;
        }
        mid=(low+high)/2;
    }
    return -1;
}
