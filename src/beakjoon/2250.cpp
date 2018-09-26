#define LOCAL_TEST

#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct TreeNode {
    int level;

    TreeNode *parent = NULL;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
};

TreeNode trees[10001];
pair<int, int> maxmin[10001];
set<int> subroot;
int N;
int pos = 1;

void bfs(TreeNode& node, const int& level) {
    if (node.left != NULL) {
        bfs(*node.left, level + 1);
    }

    node.level = level; 

    if (maxmin[level].first < pos) {
        maxmin[level].first = pos;
    }

    if (maxmin[level].second > pos) {
        maxmin[level].second = pos;
    }

    pos++;

    if (node.right != NULL) {
        bfs(*node.right, level + 1);
    }
}

int main(void) {
#ifdef LOCAL_TEST
    freopen("2250.txt", "r", stdin);
#endif
    scanf("%d", &N);

    for (auto& p : maxmin) {
        p.first = -1;
        p.second = 1e9;
    }

    for (int i = 1; i <= N; i++) {
        int id, l, r;

        scanf("%d %d %d", &id, &l, &r);

        if (l != -1) {
            trees[id].left = &trees[l];
        }

        if (r != -1) {
            trees[id].right = &trees[r];
        }

        trees[l].parent = trees[r].parent = &trees[id];

        if (trees[id].parent == NULL) {
            subroot.insert(id);
        }
    }

    TreeNode root;

    for (auto& item : subroot) {
        if (trees[item].parent != NULL) {
            continue;
        }

        root = trees[item];
        break;
    }

    bfs(root, 1);

    int level = -1;
    int width = -1;
    for (int i = 1; i <= N; i++) {
        int sum = maxmin[i].first - maxmin[i].second + 1;
        if (sum > width) {
            width = sum;
            level = i;
        }
    }
    
    printf("%d %d", level, width);

    return 0;
}
