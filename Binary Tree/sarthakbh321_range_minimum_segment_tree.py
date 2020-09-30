import math
def buildTree(arr, tree, start, end, node):
    if (start == end):
        tree[node] = arr[start]
        return

    mid = (start + end) // 2

    buildTree(arr, tree, start, mid, 2 * node)
    buildTree(arr, tree, mid + 1, end, 2 * node + 1)

    tree[node] = min(tree[2 * node], tree[2 * node + 1])


def query(tree, node, qLow, qHigh, iLow, iHigh):
    if (iLow >= qLow and iHigh <= qHigh):
        return tree[node]
    elif (iLow > qHigh or iHigh < qLow):
        return math.inf

    else:
        mid = (iLow + iHigh) // 2

        q1 = query(tree, 2 * node, qLow, qHigh, iLow, mid)
        q2 = query(tree, 2 * node + 1, qLow, qHigh, mid + 1, iHigh)

        return min(q1, q2)


n = int(input())
arr = list(map(int, input().split()))

power = math.ceil(math.log(n, 2)) + 1

tree = [None] * (2 ** power)
buildTree(arr, tree, 0, n - 1, 1)

q = int(input())

for _ in range(q):
    l, r = map(int, input().split())

    res = query(tree, 1, l, r, 0, n - 1)
    print(res)