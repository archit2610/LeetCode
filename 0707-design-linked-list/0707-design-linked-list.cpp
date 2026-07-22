class MyLinkedList {
public:
     struct Node {
        int val;
        Node* next;

        Node(int x) {
            val = x;
            next = nullptr;
        }
    };

    Node* head;
    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        int n = 0;
        Node* curr = head;
        while (curr != nullptr){
            if (n == index) return curr->val;
            curr = curr->next;
            n++;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
    }
    
    void addAtTail(int val) {
        Node* temp = new Node(val);
        Node* curr = head;
        if (head == nullptr) {
            head = temp;
            return;
        }
        while (curr->next != nullptr )  curr = curr->next;
        if (curr->next == nullptr)  curr->next = temp;
             
    }
    
    void addAtIndex(int index, int val) {
        int n = 0;
        Node* curr = head;
        Node* temp = new Node(val);
        if (index == 0) {
            addAtHead(val);
            return;
        }
        while (curr != nullptr){
            if (n == index-1){
                temp->next = curr->next;
                curr->next = temp;
                break;
            }
            ++n;
            curr = curr->next;
        }
    }
    
    void deleteAtIndex(int index) {
        int n = 0;
        Node* curr = head;
        if (index == 0) {
             head = head->next;
             return;
        }
        while (curr != nullptr && curr->next != nullptr){
            if (n == index - 1){
                curr->next = curr->next->next;
                break;
                
               
            }
            ++n;
            curr = curr->next;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */