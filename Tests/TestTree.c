#include "../Sources/Tree/BinarySearchTree.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

// for test traverse
static char str[64] = {0};

static void Visit(BinarySearchTreeItem n)
{
    char tmp[8] = {0};
    sprintf(tmp, "%d ", n);
    strcat(str, tmp);
}

void TestBinarySearchTree()
{
    // BinarySearchTree_Create BinarySearchTree_Size BinarySearchTree_IsEmpty
    BinarySearchTree* tree = BinarySearchTree_Create();
    assert(BinarySearchTree_Size(tree) == 0);
    assert(BinarySearchTree_IsEmpty(tree) == true);

    // BinarySearchTree_Find BinarySearchTree_FindMax BinarySearchTree_FindMin
    assert(BinarySearchTree_Find(tree, 0) == BINARY_SEARCH_TREE_NOT_FOUND);
    assert(BinarySearchTree_FindMax(tree) == BINARY_SEARCH_TREE_NOT_FOUND);
    assert(BinarySearchTree_FindMin(tree) == BINARY_SEARCH_TREE_NOT_FOUND);

    // BinarySearchTree_Insert
    BinarySearchTree_Insert(tree, 3);
    BinarySearchTree_Insert(tree, 1);
    BinarySearchTree_Insert(tree, 2);
    BinarySearchTree_Insert(tree, 4);
    BinarySearchTree_Insert(tree, 5);
    BinarySearchTree_Insert(tree, 5);
    BinarySearchTree_Insert(tree, 5);
    BinarySearchTree_Insert(tree, 1);
    assert(BinarySearchTree_Size(tree) == 5);

    // BinarySearchTree_Traverse
    BinarySearchTree_Traverse(tree, PRE_ORDER, Visit);
    assert(strcmp(str, "3 1 2 4 5 ") == 0);
    memset(str, 0, sizeof(str));

    BinarySearchTree_Traverse(tree, IN_ORDER, Visit);
    assert(strcmp(str, "1 2 3 4 5 ") == 0);
    memset(str, 0, sizeof(str));

    BinarySearchTree_Traverse(tree, POST_ORDER, Visit);
    assert(strcmp(str, "2 1 5 4 3 ") == 0);
    memset(str, 0, sizeof(str));

    BinarySearchTree_Traverse(tree, LEVEL_ORDER, Visit);
    assert(strcmp(str, "3 1 4 2 5 ") == 0);
    memset(str, 0, sizeof(str));

    // BinarySearchTree_Find
    assert(BinarySearchTree_Find(tree, 2) == 2);
    assert(BinarySearchTree_Find(tree, 0) == BINARY_SEARCH_TREE_NOT_FOUND);

    // BinarySearchTree_FindMin BinarySearchTree_FindMax
    assert(BinarySearchTree_FindMin(tree) == 1);
    assert(BinarySearchTree_FindMax(tree) == 5);

    // BinarySearchTree_Remove
    BinarySearchTree_Remove(tree, 1);
    assert(BinarySearchTree_FindMin(tree) == 2);
    BinarySearchTree_Remove(tree, 5);
    assert(BinarySearchTree_FindMax(tree) == 4);
    assert(BinarySearchTree_Size(tree) == 3);

    // BinarySearchTree_Destroy
    BinarySearchTree_Destroy(tree);

    printf("Binary Search Tree Test OK.\n");
}
