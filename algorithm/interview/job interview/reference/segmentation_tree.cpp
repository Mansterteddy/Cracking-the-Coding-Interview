struct SegTreeNode
{
    int val;
};

const int MAXNUM = 1000;

void build(int root, int arr[], int istart, int iend)
{
    if(istart = iend) segTree[root].val = arr[istart];
    else
    {
        int mid = (istart + iend) / 2;
        build(root * 2 + 1, arr, istart, mid);
        build(root * 2 + 2, arr, mid+1, iend);
        segTree[root].val = min(segTree[root*2 + 1].val, segTree[root*2+2].val);
    }

}

int query(int root, int nstart, int nend, int qstart, int qend)
{
    if(qstart > nend || qend < nstart) return INFINITE;
    if(qstart <= nstart && qend >= nend) return segTree[root].val;
    int mid = (nstart + nend) / 2;
    return min(query(root * 2 + 1, nstart, mid, qstart, qend),
                query(root *2 + 2, mid + 1, qstart, qend));

}

void updateOne(int root, int nstart, int nend, int index, int addVal)
{
    if(nstart == nend)
    {
        if(index == nstart) segTree[root].val += addVal;
        return;
    }

    int mid = (nstart + nend) / 2;
    if(index <= mid)
        updateOne(root * 2 + 1, nstart, mid, index, addVal);
    else updateOne(root * 2 + 2, mid+1, nend, index, addVal);

    segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
}

