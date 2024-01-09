void build(){
    // 根据线序找到根节点
    root = in[0]

    int rootVal = pre[preStart];
    


    // 在中序中找到位置 i
    // 递归

    root.left = build(0,i-1)
    build(i+1, len);

}