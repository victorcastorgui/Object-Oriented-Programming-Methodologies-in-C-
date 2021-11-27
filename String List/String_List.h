// Student ID: 20399730
// String_List.h
//
#ifndef String_List_h
#define String_List_h

#include <iostream>
#include <sstream>

class String_List {
private:
    struct Node {
        std::string data;
        Node *next;
        Node(std::string s = "") : data(s), next(nullptr) {}
    };
    
    Node *_head, *_tail, *_prev_to_current;
    size_t _size;
    
public:
    String_List() {
        struct Node* temp = new Node ("_SENTINEL_");
        _head = temp;
        _tail = temp;
        _prev_to_current = _head;
        _size = 0;
    }
    
    ~String_List() {
        delete _head;
    }
    
    String_List *insert_at_current(std::string s) {
        struct Node* newNode = new Node;
        newNode -> data = s;
        newNode -> next = _prev_to_current -> next;
        
        if(_prev_to_current -> next == nullptr){
            _prev_to_current -> next = newNode;
            _tail = _prev_to_current -> next;
        }
        else{
            _prev_to_current -> next = newNode;
        }
        _size++;
        
        return this;
    }
    
    String_List* push_back(std::string s) {
        Node* original = _prev_to_current;
        _prev_to_current = _tail;
        insert_at_current(s);
        _tail = _prev_to_current->next;
        _prev_to_current = original;
        return this;
    }
    
    String_List* push_front(std::string s) {
        Node* ori = _prev_to_current;
        _prev_to_current = _head;
        insert_at_current(s);
        _prev_to_current = ori;

        return this;
    }
    
    String_List* advance_current() {
        if (_prev_to_current->next == nullptr) {
            return nullptr;
        }
        _prev_to_current = _prev_to_current->next;
        return this;
    }
    std::string get_current() const {
        if (_prev_to_current->next != nullptr) {
            return _prev_to_current->next->data;
        }
        return "_SENTINEL_";
    }
    
    String_List* remove_at_current() {
        struct Node* removedNode = _prev_to_current->next;
        _prev_to_current->next = removedNode->next;
        _size--;
        return this;
    }
    
    size_t get_size() const {
        return _size;
    }
    
    String_List* rewind() {
        _prev_to_current = _head;
        return this;
    }
    
    void clear() {
        size_t total = _size;
        _prev_to_current = _head;
        for (size_t i = 0; i < total; i++) {
            if (!(_prev_to_current->next == nullptr)) {
                remove_at_current();
            }
        }
        _prev_to_current = _head;
        _tail = _head;
        _head->next = nullptr;
    }
    
    std::string& find_item(std::string s) const {
        static std::string SENTINEL = "_SENTINEL_";
        Node* temp = _head;

        for (size_t i = 0; i < _size; i++) {
            if (temp->next == nullptr) {
                return SENTINEL;
            }
            if (temp->next->data == s) {
                return temp->next->data;
            }else {
                temp = temp->next;
            }
        }
        return SENTINEL;
    }
    
    std::string to_string() const {
        static int unsigned MAX_LINES = 25;
        std::string print = "# String_List - " + std::to_string(_size);
        print += " entries total. Starting at cursor:\n";
        Node* temp = _head -> next;
        
        if(_size != 0)
        {
            for(size_t i=0; i < MAX_LINES; i++)
            {
                print += temp -> data + "\n";
                if(temp -> next == nullptr)
                {
                    break;
                }
                temp = temp -> next;
            }
            if(_size > MAX_LINES)
            {
                print +="...\n";
            }
        }
        return print;
    }
    friend class Tests; // Don't remove this line
};

#endif /* String_List_h */
