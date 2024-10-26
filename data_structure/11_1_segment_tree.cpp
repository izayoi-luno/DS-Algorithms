// 线段树 
// segment tree

#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<long long> tree, mark;
    int n;

    // * 将标记下传
    void push_down(int p, int len) {
        if (len <= 1) return;
        tree[p << 1] += mark[p] * (len - len / 2);
        mark[p << 1] += mark[p];
        tree[p << 1 | 1] += mark[p] * (len / 2);
        mark[p << 1 | 1] += mark[p];
        mark[p] = 0;
    }

    // * 递归构建线段树
    void build(const vector<long long>& A, int p, int cl, int cr) {
        if (cl == cr) {
            tree[p] = A[cl];
            return;
        }
        int mid = (cl + cr) >> 1;
        build(A, p << 1, cl, mid);
        build(A, p << 1 | 1, mid + 1, cr);
        tree[p] = tree[p << 1] + tree[p << 1 | 1];
    }

    // * 递归查询区间和
    long long query(int l, int r, int p, int cl, int cr) {
        if (cl >= l && cr <= r) return tree[p];
        push_down(p, cr - cl + 1);
        int mid = (cl + cr) >> 1;
        long long ans = 0;
        if (mid >= l) ans += query(l, r, p << 1, cl, mid);
        if (mid < r) ans += query(l, r, p << 1 | 1, mid + 1, cr);
        return ans;
    }

    // * 递归更新区间
    void update(int l, int r, int d, int p, int cl, int cr) {
        if (cl >= l && cr <= r) {
            tree[p] += d * (cr - cl + 1);
            mark[p] += d;
            return;
        }
        push_down(p, cr - cl + 1);
        int mid = (cl + cr) >> 1;
        if (mid >= l) update(l, r, d, p << 1, cl, mid);
        if (mid < r) update(l, r, d, p << 1 | 1, mid + 1, cr);
        tree[p] = tree[p << 1] + tree[p << 1 | 1];
    }

public:
    // * 初始化线段树的大小和相关数组
    SegmentTree(int size) : n(size) {
        tree.resize(4 * n);
        mark.resize(4 * n);
    }

    // * 公共接口，用于根据数组 A 构建线段树
    void build(const vector<long long>& A) {
        build(A, 1, 1, n);
    }

    // * 公共接口，用于查询区间 [l, r] 的和
    long long query(int l, int r) {
        return query(l, r, 1, 1, n);
    }

    // * 公共接口，用于将区间 [l, r] 的每个元素增加 d
    void update(int l, int r, int d) {
        update(l, r, d, 1, 1, n);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<long long> A(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> A[i];
    
    SegmentTree segTree(n);
    segTree.build(A);
    
    while (m--) {
        int o, l, r, d;
        cin >> o >> l >> r;
        if (o == 1) {
            cin >> d;
            segTree.update(l, r, d);
        } else {
            cout << segTree.query(l, r) << '\n';
        }
    }
    return 0;
}
