#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
private:
    T key;
    int color;
    Node<T> *left;
    Node<T> *right;
    Node<T> *parent;

public:
    Node(T _key, int _color)
    {
        parent = left = right = NULL;
        key = _key;
        color = _color;
    }

    T getKey()
    {
        return key;
    }

    int getColor()
    {
        return color;
    }

    Node<T> *getNodeLeft()
    {
        return left;
    }

    Node<T> *getNodeRight()
    {
        return right;
    }

    Node<T> *getNodeParent()
    {
        return parent;
    }

    void setNodeLeft(Node<T> *node)
    {
        left = node;
    }

    void setNodeRight(Node<T> *node)
    {
        right = node;
    }

    void setKey(T nkey)
    {
        key = nkey;
    }

    void setColor(int ncolor)
    {
        color = ncolor;
    }

    void setNodeParent(Node<T> *node)
    {
        parent = node;
    }

    friend std::ostream &operator<<(std::ostream &out, Node<T> &node)
    {
        out << node.key;
        return out;
    }
};

#endif