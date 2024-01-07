// Created by Simon_Shi on 2024/1/8.

#include "../Header/business.h"
#include "../Header/file management.h"

waiting_list::waiting_list(char flight_number[20]) {
    long int n = 0;
    string file_name = flight_number;
    file_name += ".dat";
//    cout << "num_block is " << file_management::num_block<data_waiting>(file_name) << endl;  //测试
    data_waiting *pt = new data_waiting();
    head = pt;
    for (llu i = 0; i < file_management::num_block<data_waiting>(file_name); i++) {
        if (file_management::read(pt, file_name, &n)) {
            if (i == file_management::num_block<data_waiting>(file_name) - 1) break;  //最后一个节点不要创建下一节点
            data_waiting *nextnode = new data_waiting();
            pt->next = nextnode;
            pt = nextnode;
        } else {
            cerr << "error in reading !" << endl;
            break;
        }
    }
//    cout << "The link list builds up correctly!" << endl;
}

waiting_list::~waiting_list() {
    data_waiting *p = head;
    while (p != nullptr) {
        data_waiting *nextnode = p->next;
        delete p;
        p = nextnode;
    }
    head = nullptr;
}

void waiting_list::Add() {
    data_waiting *nextnode = new data_waiting();  // 创建新节点
    nextnode->next = nullptr;

    if (head == nullptr) head = nextnode;  // 如果链表为空，将新节点作为头节点
    else {
        data_waiting *temp = head; // 找到链表末尾，将新节点连接到链表末尾
        while (temp->next != nullptr) temp = temp->next;
        temp->next = nextnode;
    }

    cin >> *nextnode;

    cout << "over!" << endl;

}

void waiting_list::Query() {
    data_waiting *p = head;
    int n = 1;  //节点数

    while (p != nullptr) {
        cout << n++ << ":";  //同上，节点数

        cout << *p << endl;

        p = p->next;
    }
}

void waiting_list::Delete (int *ticket) {
    data_waiting *p = head;  //p是删除节点前一个
    data_waiting *r = head;  //r是删除节点
    data_waiting *b = head->next;  //b是删除节点后一个

    while (b != nullptr) {
        if (*ticket == 0) break;
        if (r != head) p = p->next;

        if (*ticket >= r->ticket_number) {
            *ticket -= r->ticket_number;
            p->next = b;
            delete r;
            r = b;
            b = b->next;
            continue;
        }
        r = r->next;
        b = b->next;
    }

    if (*ticket >= r->ticket_number) {
        *ticket -= r->ticket_number;
        delete r;
    }
    cout << "over!" << endl;
}

ostream &operator<<(ostream &out, const waiting_list::data_waiting &p) {  //提供给query函数
    out << p.name;
    out << " ";
    out << p.phonenumber;
    out << " ";
    out << p.ticket_number;
    out << " ";
    out << p.Class;
    out << " ";

    return out;
}

istream &operator>>(istream &in, waiting_list::data_waiting &p) {  //提供给add函数
    cout << "Please add name" << endl;
    in >> p.name;
    cout << "Please add phonenumber" << endl;
    in >> p.phonenumber;
    cout << "Please add ticket_number" << endl;
    in >> p.ticket_number;
    cout << "Please add Class" << endl;
    in >> p.Class;

    //>> std::setw(20)

    return in;
}