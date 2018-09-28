#include <iostream>
#include <vector>

#define MAX_V 10005

using namespace std;

struct TreeNode {
    int w;

    vector<TreeNode*> child;
};

TreeNode tree[MAX_V];
int N;

int result;

int getWeight(const TreeNode& node) {
    int first = 0, second = 0;

    for (auto& child : node.child) {
        int w = getWeight(*child);

        if (first < w) {
            second = first;
            first = w;
        } else if (second < w) {
            second = w;
        }
    }

    result = max(result, first + second);

    return first + node.w;
}

int main(void) {
#ifdef LOCAL_TEST 
    freopen("1967.txt", "r", stdin);
#endif
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        int node, ch, w;

        scanf("%d %d %d", &node, &ch, &w);

        tree[ch].w = w;
        tree[node].child.push_back(&tree[ch]);
    }

    TreeNode& root = tree[1];
    
    result = max(result, getWeight(root));

    printf("%d\n", result);

    return 0;
}
