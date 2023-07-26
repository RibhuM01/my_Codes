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
                cout<<"New node added(firstnode) !"<<endl;
                return;
            }
            Node<T>* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = node;
            cout<<"New node added !"<<endl;
        }

        void displayAll(){
            if(head == NULL){
                cout<<"Linked list is empty"<<endl;
                return;
            }
            cout<<endl<<"----link list items----"<<endl;
            Node<T>* temp = head;
            while(temp != NULL){
                cout<<temp->data<<" | ";
                temp = temp->next;
            }
            cout<<endl;
        }

        void remove(){
            if(head == NULL){
                cout<<"Linked list is empty !"<<endl;
                return;
            }
            if(head->next == NULL){
                head = NULL;
                cout<<"Last item removed"<<endl;
                return;
            }

            Node<T>* temp = head;
            while(temp != NULL){
                if(temp->next->next == NULL){
                    temp->next = NULL;
                    cout<<"Last item removed"<<endl;
                    break;
                }
                temp = temp->next;
            }
            
        }
};

int main(){
    LinkedList<int> list;
    int ch, item, index;
    bool quit = false;
    do{
        cout<<"===================================="<<endl;
        cout<<"select option :"<<endl;
        cout<<"1: Insert"<<endl;
        cout<<"2: Display items"<<endl;
        cout<<"3: Delete from back"<<endl;
        cout<<"4: Exit"<<endl;
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
            quit = true;
            break;
        default:
            cout<<"Invalid Selection"<<endl;
            break;
        }
    }while(!quit);
    return 0;
}