// Created by Simon_Shi on 2024/1/8.
#include "../Header/business.h"
#include "../Header/file management.h"

customer_list::customer_list() {
    long int n = 0;
//    cout << "num_block is " << file_management::num_block<data_customer>("data_customer.dat") << endl;  //测试
    data_customer *pt = new data_customer();
    head = pt;
    for (llu i = 0; i < file_management::num_block<data_customer>("data_customer.dat"); i++) {
        if (file_management::read(pt, "data_customer.dat", &n)) {
            if (i == file_management::num_block<data_customer>("data_customer.dat") - 1) break;  //最后一个节点不要创建下一节点
            data_customer *nextnode = new data_customer();
            pt->next = nextnode;
            pt = nextnode;
        } else {
            cerr << "error in reading !" << endl;
            break;
        }
    }
//    cout << "The link list builds up correctly!" << endl;
}

customer_list::~customer_list() {
    data_customer *p = head;
    while (p != nullptr) {
        data_customer *nextnode = p->next;
        delete p;
        p = nextnode;
    }
    head = nullptr;
}

void customer_list::Add() {
    data_customer *nextnode = new data_customer();  // 创建新节点
    nextnode->next = nullptr;

    if (head == nullptr) head = nextnode;  // 如果链表为空，将新节点作为头节点
    else {
        data_customer *temp = head; // 找到链表末尾，将新节点连接到链表末尾
        while (temp->next != nullptr) temp = temp->next;
        temp->next = nextnode;
    }

    cin >> *nextnode;

    cout << "over!" << endl;

}

void customer_list::Query() {
    data_customer *p = head;
    int n = 1;  //节点数

    while (p != nullptr) {
        cout << n++ << ":";  //同上，节点数

        cout << *p << endl;

        p = p->next;
    }
}

void customer_list::Update() {
    data_customer *p = head;
    int num = 1;
    while (p != nullptr) {
        p = p->next;
        num++;
    }

    customer_list::Query();

    cout << "choose one customer to update" << endl;

    cin >> num;
    p = head;
    for (int i = 0; i < num - 1; i++) p = p->next;

    cout << "Please update name" << endl;
    cin >> p->name;

    cout << "Please update phonenumber" << endl;
    cin >> p->phonenumber;

    cout << "Please update ticket_number" << endl;
    cin >> p->ticket_number;

    cout << "Please update Class" << endl;
    cin >> p->Class;

    cout << "Please update starting_station" << endl;
    cin >> p->starting_station;

    cout << "Please update terminal" << endl;
    cin >> p->terminal;

    cout << "Please update flight_number" << endl;
    cin >> p->flight_number;

    cout << "Please update aircraft_number" << endl;
    cin >> p->aircraft_number;

    cout << "Please update departure_time" << endl;
    cin >> p->departure_time;

    cout << "Please update landing_time" << endl;
    cin >> p->landing_time;

    cout << "over!" << endl;
}

void customer_list::Delete() {
    data_customer *p = head;  //p是删除节点前一个
    data_customer *r = head;  //p是删除节点
    data_customer *b = head;  //p是删除节点后一个
    int num = 1;
    while (p != nullptr) {
        p = p->next;
        num++;
    }

    customer_list::Query();

    cout << "choose one customer to delete" << endl;

    cin >> num;
    p = head;
    for (int i = 0; i < num - 2; i++) p = p->next;
    for (int i = 0; i < num - 1; i++) r = r->next;
    for (int i = 0; i < num; i++) b = b->next;

    if (num == 1) head = b;
    else p->next = b;

    delete r;

    cout << "over!" << endl;
}

ostream &operator<<(ostream &out, const customer_list::data_customer &p) {  //提供给query函数
    out << p.name;
    out << " ";
    out << p.phonenumber;
    out << " ";
    out << p.ticket_number;
    out << " ";
    out << p.Class;
    out << " ";
    out << p.starting_station;
    out << " ";
    out << p.terminal;
    out << " ";
    out << p.flight_number;
    out << " ";
    out << p.aircraft_number;
    out << " ";
    out << p.departure_time;
    out << " ";
    out << p.landing_time;
    out << " ";

    return out;
}

istream &operator>>(istream &in, customer_list::data_customer &p) {  //提供给add函数
    cout << "Please add name" << endl;
    in >> p.name;
    cout << "Please add phonenumber" << endl;
    in >> p.phonenumber;
    cout << "Please add ticket_number" << endl;
    in >> p.ticket_number;
    cout << "Please add Class" << endl;
    in >> p.Class;
    cout << "Please add starting_station" << endl;
    in >> p.starting_station;
    cout << "Please add terminal" << endl;
    in >> p.terminal;
    cout << "Please add flight_number" << endl;
    in >> p.flight_number;
    cout << "Please add aircraft_number" << endl;
    in >> p.aircraft_number;
    cout << "Please add departure_time" << endl;
    in >> p.departure_time;
    cout << "Please add landing_time" << endl;
    in >> p.landing_time;

    //>> std::setw(20)

    return in;
}