#include <stdio.h>
#include <iostream>
using namespace std;

struct node
{
    int v, h;
    node* l;
    node* r;
    node(int x) { 
        v = x; 
        l = r = NULL; 
        h = 1; 
    }
};


class AVL {

    node* root;

    int height(node *p) {
        if(p) {
            return p->h;
        }
        else {
            return 0;
        }
    }

    int factor(node *p) {
        return height(p->r) - height(p->l);
    }

    void fix(node *p) {
        int tmpl = height(p->l);
        int tmpr = height(p->r);

        if(tmpl > tmpr) {
            p->h = tmpl + 1;
        }
        else {
            p->h = tmpr + 1;
        }
    }

    node* rotater(node *p) {
        node* q = p->l;
        p->l = q->r;
        q->r = p;
        fix(p);
        fix(q);
        return q;
    }

    node* rotatel(node *p) {
        node* q = p->r;
        p->r = q->l;
        q->l = p;
        fix(p);
        fix(q);
        return q;
    }

    node* balance(node *p) {
        fix(p);
        if( factor(p)==2 )
        {
            if( factor(p->r) < 0 )
                p->r = rotater(p->r);
            return rotatel(p);
        }
        if( factor(p)==-2 )
        {
            if( factor(p->l) > 0  )
                p->l = rotatel(p->l);
            return rotater(p);
        }
        return p;
    }

    node* _insert(node *p, int x) {
        if( !p ) {
            return new node(x);
        }
        if( x<p->v )
            p->l = _insert(p->l,x);
        else if(x>p->v)
            p->r = _insert(p->r,x);
        return balance(p);        
    }

    node* getmin(node *p) {
        if(p->l) {
            return getmin(p->l);
        }
        else {
            return p;
        }
    }

    node* removemin(node *p) {
        if( !p->l )
            return p->r;
        p->l = removemin(p->l);
        return balance(p);        
    }

    node* _remove(node* p, int x)
    {
        if( !p ) return 0;
        if( x < p->v )
            p->l = _remove(p->l, x);
        else if( x > p->v )
            p->r = _remove(p->r, x);  
        else //  k == p->key 
        {
            node* q = p->l;
            node* r = p->r;
            delete p;
            if( !r ) return q;
            node* min = getmin(r);
            min->r = removemin(r);
            min->l = q;
            return balance(min);
        }
        return balance(p);
    }

    bool _search(node *p, int x) {
        if(!p) return false;
        if( x < p->v )
            return _search(p->l, x);
        else if( x > p->v )
            return _search(p->r, x);  
        else
        {
            return true;
        }
    }

    void _inorder(node *p) {
        if(p) {
            _inorder(p->l);
            cout << p->v << " ";
            _inorder(p->r);
        }
    }

public:

    AVL() {
        root = 0;
    }

    void insert(int x) {
        root = _insert(root, x);
    }

    void remove(int x) {
        root = _remove(root, x);
    }

    bool search(int x) {
        _search(root, x);
    }

    void inorder() {
        _inorder(root);
    }
};