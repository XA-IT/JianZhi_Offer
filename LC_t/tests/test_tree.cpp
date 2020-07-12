#include "../public_utils/public_utils.h"

int main()
{
    vector<vector<int>> tests = {
        {1, 2, 3, 4, 5, 6},
        {1, 2, -2, 3, 4, 5},
        {1},
        {2, -2, 1, -111, 43}};
    for (vector<int> te : tests)
    {
        // TreeNode *root = buildTreeFromBFSVec(te);
        // printBFSBinTree(root);
        // printPreorderBinTree(root);
        ListNode *head = buildListFromVec(te);
        printListNode(head);
    }
    return 0;
}