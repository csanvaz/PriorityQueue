// priorityqueue.h
//
// 
/*
Cynthia Sanchez Vazquez Project 3: Priority Que
The goal of this header file is to create a priorityque that uses inorder
traversal to keep the data sorted from lowest to highest. The data collected are
priority numbers and data that can vary from strings to other intergers. In this case
the lowest number has the highest priority. A binary is created to store the data with
the priority. 
*/
#pragma once

#include <iostream>
#include <sstream>
#include <set>
#include <map>


using namespace std;

template<typename T>
class priorityqueue {
private:
    struct NODE {
        int priority;  // used to build BST
        T value;  // stored data for the p-queue 
                  // TEMPLATE ACKNOWLEDGING THAT THERE COULD BE DIFFERENT TYPE OF 
                  //DATA THAT NEED STORING OR DISPLAYED
        bool dup;  // marked true when there are duplicate priorities
        NODE* parent;  // links back to parent
        NODE* link;  // links to linked list of NODES with duplicate priorities
        NODE* left;  // links to left child
        NODE* right;  // links to right child
    };
    NODE* root;  // pointer to root node of the BST
    int size;  // # of elements in the pqueue
    NODE* curr;  // pointer to next item in pqueue (see begin and next)
    
    //Below are functions that help public functions
    void clearHelper(struct NODE* node) {
        if (node != nullptr) {
            clearHelper(node->left);
            clearHelper(node->right);
            delete node;
        }
    }

    void copyHelper(struct NODE** node, struct NODE* other) {
        if (other != nullptr) {
            (*node) = new struct NODE;
            (*node)->priority = other->priority;
            (*node)->value = other->value;
            (*node)->dup = other->dup;
            (*node)->left = nullptr;
            (*node)->right = nullptr;
            (*node)->parent = nullptr;
            (*node)->link = nullptr;
            copyHelper(&((*node)->left), other->left); //recursively going into left node and copying values
            copyHelper(&((*node)->right), other->right);
            if ((*node)->left != nullptr) {
                (*node)->left->parent = *node;
            }

            if ((*node)->right != nullptr) {
                (*node)->right->parent = *node;
            }
        }
    }


    void insertHelper(struct NODE** node, struct NODE* newNode) {
        if (*node == nullptr) {
            *node = newNode; // create root
        }
        else {

            if (newNode->priority == (*node)->priority)
            {
                if ((*node)->dup == true) {
                    newNode->link = (*node)->link->link; //point newNode link to what is existing
                    (*node)->link->link = newNode;
                    newNode->dup = true;
                    newNode->left = (*node)->link->left;
                    newNode->right = (*node)->link->right;
                    newNode->parent = (*node)->link->parent;
                }
                else {
                    newNode->link = (*node)->link; //point newNode link to what is existing
                    (*node)->link = newNode;
                    (*node)->dup = true;
                    newNode->dup = true;
                    newNode->left = (*node)->left;
                    newNode->right = (*node)->right;
                    newNode->parent = *node;
                }

            }


            if (newNode->priority < (*node)->priority) {
                insertHelper(&((*node)->left), newNode); //just inserting node to left side
                (*node)->left->parent = (*node);

            }

            if (newNode->priority > (*node)->priority) {
                insertHelper(&((*node)->right), newNode); //just inserting node to right side
                (*node)->right->parent = (*node);

            }

        }
    }

    //find the lowest priority number in the que
    struct NODE* lowestHelper(struct NODE* node) {
      
       if (node->dup == true && node->link != nullptr && node->parent == nullptr) {
            
            return node;
        }
        
        if (node->dup == true && node->link == nullptr) {
            return node;
        }


        while (node->left) {
            node = node->left;
        }
      
        

        return node;
    }



public:
    //
    // default constructor:
    //
    // Creates an empty priority queue.
    // O(1)
    //
    priorityqueue() {      
        size = 0;
        root = nullptr;  
        curr = nullptr;
       
    }
    
    //
    // operator=
    //
    // Clears "this" tree and then makes a copy of the "other" tree.
    // Sets all member variables appropriately.
    // O(n), where n is total number of nodes in custom BST
    //
    priorityqueue& operator=(const priorityqueue& other) {
        
        if (this == &other)
        {
            return *this;
        }

        clear(); //clear any existing contents in queue

        copyHelper(&root, other.root);
        size = other.size;



        
        return *this;
        
        
    }
    
    //
    // clear:
    //
    // Frees the memory associated with the priority queue but is public.
    // O(n), where n is total number of nodes in custom BST
    //
  

    void clear() {
        
        
        clearHelper(root);

        root = nullptr;
        size = 0;
        curr = nullptr;
            
    }
    
    //
    // destructor:
    //
    // Frees the memory associated with the priority queue.
    // O(n), where n is total number of nodes in custom BST
    //
    ~priorityqueue() {
        
        
        
        clear();
        
        
    }
    
    //
    // enqueue:
    //
    // Inserts the value into the custom BST in the correct location based on
    // priority.
    // O(logn + m), where n is number of unique nodes in tree and m is number of
    // duplicate priorities
    //
    void enqueue(T value, int priority) {
      

        struct NODE* temp = new struct NODE;
        temp->priority = priority; 
        temp->value = value;
        temp->dup = false; 
        temp->parent = nullptr;
        temp->link = nullptr;
        temp->left = nullptr;
        temp->right = nullptr;
        

        
        insertHelper(&root, temp);

        size++;

        
    }
    //
    // dequeue:
    //
    // returns the value of the next element in the priority queue and removes
    // the element from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number of
    // duplicate priorities
    // pop function of queue--remove but check that right and left are pointing where they need to 
    // point. probalby replace curr value with right node, left of the right node will point to cur node
    T dequeue() {
        T valueOut;

       
        struct NODE* temp = lowestHelper(root);
        
        

        if (temp != nullptr) {
            valueOut = temp->value;
        }

        //If statements to check different cases of binary search tree
        //for when a node is deleted. There is also linked list traversal
        //that is based on safety checks
        if (temp->parent == nullptr && temp->right == nullptr &&
            temp->link == nullptr && temp->left == nullptr) {

            temp == nullptr;

        }else if (temp->dup == true && temp->link != nullptr) {
            root = temp->link;
            
            if (root != nullptr) {
                root->parent = nullptr;
            }

        }else if (temp->dup == true && temp->link == nullptr) {
            root = temp->right;

            if (root != nullptr) {
                root->parent = nullptr;
            }

        }else if (temp->parent != nullptr) {
            temp->parent->left = temp->right;
            if (temp->right != nullptr) {
                temp->right->parent = temp->parent;
            }
        }
        else {
            if (temp->right->left == nullptr) {
                root = temp->right;
            }
            else if (temp->right->left != nullptr) {
                root = temp->right->left;
                temp->right->parent = root;
                temp->right->left = nullptr;
                root->right = temp->right;
            }
            
       
            
            if (root != nullptr) {
                root->parent = nullptr;
            }
        }
      
        delete temp;
        size--;
 
       return valueOut; 
    }
    
    //
    // Size:
    //
    // Returns the # of elements in the priority queue, 0 if empty.
    // O(1)
    //
    int Size() {
        
        
        return size; // TO DO: update this return
        
        
    }
    
    //
    // begin
    //
    // Resets internal state for an inorder traversal.  After the
    // call to begin(), the internal state denotes the first inorder
    // node; this ensure that first call to next() function returns
    // the first inorder node value.
    //
    // O(logn), where n is number of unique nodes in tree
    // will set the current pointer to left most leaf in tree. start root then go to left branch
    // until null 
    // this is where parent comes in, traverse to parent
    // Example usage:
    //    pq.begin();
    //    while (tree.next(value, priority)) {
    //      cout << priority << " value: " << value << endl;
    //    }
    //    cout << priority << " value: " << value << endl;
    void begin() {
        //set the current node to the lowest priority node
        if (root != nullptr) {
            curr = lowestHelper(root);
        }
    }
    
    //
    // next
    //
    // Uses the internal state to return the next inorder priority, and
    // then advances the internal state in anticipation of future
    // calls.  If a value/priority are in fact returned (via the reference
    // parameter), true is also returned.
    //
    // False is returned when the internal state has reached null,
    // meaning no more values/priorities are available.  This is the end of the
    // inorder traversal.
    //
    // O(logn), where n is the number of unique nodes in tree
   
    bool next(T& value, int &priority) 
    {
        
        
        if (curr == nullptr) {
            return false;
        }

       
        if (curr != nullptr) {
            value = curr->value;
            priority = curr->priority;
        }
        
        if (curr->link != nullptr) {
            curr = curr->link;
        } else if (curr->right != nullptr) {
            curr = lowestHelper(curr->right);    
        }
        else {
            
            if (curr->parent != nullptr && curr->parent->right != curr) { 
                curr = curr->parent;    
            }
            else {
                curr = nullptr;
            }
        }
        
        
        return true;   
    }
    
    //
    // toString:
    //
    // Returns a string of the entire priority queue, in order.
    string toString() {
        
        stringstream streamer;
        int p = 0;
        T v;
        this->begin();


        while (this->next(v, p)) {
            streamer << p << " value: " << v << '\n';

        }
      
        return streamer.str(); // TO DO: update this return
             
    }
    
    //
    // peek:
    //
    // returns the value of the next element in the priority queue but does not
    // remove the item from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number of
    // duplicate priorities
    //
    T peek() {
        
        if (root == nullptr) {
            cout << "Priorityqueue is Empty" << endl;
        }
        
        T valueOut;

        struct NODE *temp = lowestHelper(root);

       
        if (temp != nullptr) {
            valueOut = temp->value;    
        }

        return valueOut; 
        
        
    }

    
    //
    // ==operator
    //
    // Returns true if this priority queue as the priority queue passed in as
    // other.  Otherwise returns false.
    // O(n), where n is total number of nodes in custom BST
    //
    bool operator==(const priorityqueue& other) const {
        
        if (this->Size() != other.Size()) {
            return false;
        }

        this->begin();
        other.begin();

        int p, pO = 0;
        T v, vO;

        while (this->next(v, p) && other.next(vO, pO)) {
            if (v != vO || p != pO) {
                return false;
           }
        }
        
        return true; 
        
        
    }
    
    //
    // getRoot - Do not edit/change!
    //
    // Used for testing the BST.
    // return the root node for testing.
    //
    void* getRoot() {
        return root;
    }
};