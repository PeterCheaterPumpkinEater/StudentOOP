#include <iostream>

void indent(int level) {
    // indent more at each level:
    for (int i = 0; i < level; i++) std::cout << "  ";
}

template <typename T>
class Bst {
    friend void print_bst(const Bst<T>& bst, int level=0) {
        indent(level);
        level++;
        
        std::cout << "data: " << bst.data << std::endl;
        indent(level + 1);
        std::cout << "left: ";
        
        if (!bst.left) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.left, level);
        }
        indent(level + 1);
        std::cout << "right: ";
        if (!bst.right) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.right, level);
        }
        std::cout << std::endl;
    }
    
    friend T min(const Bst<T>* bst){return bst -> get_min();}
    
    friend T max(const Bst<T>* bst){return bst -> get_max();}
    
public:
    Bst(T d, Bst* p=nullptr, Bst* l=nullptr, Bst* r=nullptr)
    : data(d), parent(p), left(l), right(r) {}
    
    Bst<T>* insert(const T d) {
        if (d == data) {return nullptr;}
        else if (d < data) {
            if (!left) {
                left = new Bst(d, this);
                return left;
            }
            else {return left -> insert(d);}
        }
        else {
            if (!right) {
                right = new Bst(d, this);
                return right;
            }
            else {return right -> insert(d);}
        }
    }
    
    T get_val() const {return data;}
    
    T get_min() const {
        if (!left) {return data;}
        else {return left -> get_min();}
    }
    
    T get_max() const {
        if (!right) {return data;}
        else {return right -> get_max();}
    }
    
    Bst<T>* search(T d) {
        if (d == data) {return this;}
        else if (d > data) {
            if (!right) {return nullptr;}
            else {return right -> search(d);}
        }
        else {
            if (!left) {return nullptr;}
            else {return left -> search(d);}
        }
    }

    Bst<T>* predecessor(T d) {
        Bst<T>* bst = this -> search(d);
        if (!bst) {return nullptr;}
        else if (!(bst -> left)) {
            Bst<T>* par = bst -> parent;
            while (par -> data > d) {par = par -> parent;}
            return par;
        }
        else {return bst -> search(max(bst -> left));}
    }
        
    Bst<T>* successor(T d) {
        Bst<T>* bst = this -> search(d);
        if (!bst) {return nullptr;}
        else if (!(bst -> left)) {
            Bst<T>* par = bst -> parent;
            while (par ->data < d) {par = par -> parent;}
            return par;
        }
        else {return bst -> search(min(bst -> right));}
    }

private:
    T data;
    Bst* parent;
    Bst* left;
    Bst* right;
};

