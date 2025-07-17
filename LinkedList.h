// LinkedList.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList {
private:
    struct Node {
        T item;
        Node* next;
        Node(T inputItem) {
            item = inputItem;
            next = nullptr;
        }
    };

    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        clear();
    }

    void insertBack(const T& itemToAdd) {
        Node* newNode = new Node(itemToAdd);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    T* find(const T& target) {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->item == target) {
                return &(curr->item);
            }
            curr = curr->next;
        }
        return nullptr;
    }

    void clear() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr->next;
            delete curr;
            curr = temp;
        }
        head = nullptr;
    }

    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* start) {
            current = start;
        }

        bool hasNext() const {
            return current != nullptr;
        }

        T& next() {
            T& value = current->item;
            current = current->next;
            return value;
        }
    };

    Iterator iterator() const {
        return Iterator(head);
    }
};

#endif
