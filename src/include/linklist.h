//
// Created by zhanglinxing on 2022/5/22.
//

#ifndef HELLO_LINKLIST_H
#define HELLO_LINKLIST_H

#endif //HELLO_LINKLIST_H

template <typename  NodeT>
class LinkList{
    public:
        typedef NodeT* node_pointrt_type;
        typedef LinkList<NodeT> self_type;

    public:
    LinkList();
    ~LinkList();

    void append(NodeT* node);
    void remove(NodeT* node);
    void combine(const LinkList<NodeT> & al);
    void reset();

};