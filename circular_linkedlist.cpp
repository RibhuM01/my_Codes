#include<iostream>
using namespace std;

template<typename T>class Node{
    private:
        T data;
        Node<T>* next;
        template<typename U>friend class LinkedList;
    public:
        Node(){
            this->next = NULL;
        }
};

template<typename T>class LinkedList{
    private:
        Node<T>* head;
    public:
        LinkedList(){
            this->head = NULL;
        }

        void add(T item){
            Node<T>* node = new Node<T>[1];
            node->data = item;
            if(head == NULL){
                head = node;
                head->next = node;
                cout<<"New node added(firstnode) !"<<endl;
                return;
            }
            Node<T>* temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = node;
            node->next = head;
            cout<<"New node added !"<<endl;
        }

        void displayAll(){
            if(head == NULL){
                cout<<"Linked list is empty"<<endl;
                return;
            }
            cout<<endl<<"----Linked list items------"<<endl;
            Node<T>* temp = head;
            while(true){
                cout<<temp->data<<" | ";
                temp = temp->next;
                if(temp == head) break;
            }
            cout<<endl;
        }

        int length(){
            if(head == NULL) return 0;
            int len = 1;
            Node<int>* temp = head;
            while(temp->next != head){
                len++;
                temp = temp->next;
            }
            return len;
        }

        void remove(){
            if(head == NULL){
                cout<<"Linked list is empty !"<<endl;
                return;
            }

            if(length() == 1){
                removeFront();
                return;
            }

            Node<T>* temp = head;
            while(temp->next != head){
                if(temp->next->next == head){
                    temp->next = head;
                    cout<<"Last item removed"<<endl;
                    break;
                }
                temp = temp->next;
            }
            
        }

        void removeFront(){
            if(head == NULL){
                cout<<"Linked list is empty !"<<endl;
                return;
            }
            if(length() == 1){
                head = NULL;
                cout<<"First item removed"<<endl;
                return;
            }
            Node<T>* temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;
            cout<<"Front item removed"<<endl;
        }
};

int main(){
    LinkedList<int> list;
    int ch, item, index;
    bool quit = false;
    do{
        cout<<"===================================="<<endl;
        cout<<"Select Option :"<<endl;
        cout<<"1: Insert"<<endl;
        cout<<"2: Display items"<<endl;
        cout<<"3: Delete from back"<<endl;
        cout<<"4: Delete from front"<<endl;
        cout<<"5: Exit"<<endl;
        cin>>ch;
        cout<<"===================================="<<endl;
        switch (ch)
        {
        case 1:
            cout<<"Enter item to insert:"<<endl;
            cin>>item;
            list.add(item);
            break;
        case 2:
            list.displayAll();
            break;
        case 3:
            list.remove();
            break;
        case 4:
            list.removeFront();
            break;
        case 5:
            quit = true;
            break;
        default:
            cout<<"Invalid Selection"<<endl;
            break;
        }
    }while(!quit);
    return 0;
}