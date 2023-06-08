#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct LinkedList{
    Node *head;
    LinkedList(){
        head=NULL;
    }

    bool is_empty(){
        return head == NULL;
    }

    void tambahdepan(int databaru){
        Node *baru;
        baru=new Node;
        baru->data=databaru;
        baru->next=NULL;
        if(is_empty()){
            head=baru;
        }else{
            baru->next=head;
            head=baru;
        }
    }

    void tambahbelakang(int databaru){
        Node *baru;
        baru=new Node;
        baru->data=databaru;
        baru->next=NULL;
        if(is_empty()){
            head=baru;
        }else{
            Node *bantu;
            bantu=head;
            while(bantu->next != NULL){
                bantu=bantu->next;
            }
            bantu->next=baru;
        }
    }

    void hapusdepan(){
        if(is_empty()){
            cout<<"list kosong";
        }else{
            Node *hapus=head;
            head = head->next;
            delete hapus;
        }
    }

    void hapusbelakang(){
        if(is_empty()){
            cout<<"list kosong";
        }else if(head->next == NULL){
            delete head;
            head=NULL;
        }else{
            Node *bantu = head;
            while(bantu->next->next != NULL){
                bantu=bantu->next;
            }
            delete bantu->next;
            bantu->next=NULL;
        }
    }

    void display(){
        if(is_empty()){
            cout<<"list kosong";
        }else{
            Node *bantu;
            bantu=head;
            while(bantu != NULL){
                cout<<bantu->data<<" -> ";
                bantu=bantu->next;
            }
            cout<<"NULL";
        }
    }
};

int main(){
    LinkedList *LL;
    LL =new LinkedList;
    LL->tambahdepan(5);
    LL->tambahdepan(6);
    LL->tambahdepan(7);
    LL->tambahbelakang(4);
    LL->hapusbelakang();
    LL->hapusbelakang();
    LL->display();
    
    return 0;
}

