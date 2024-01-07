// Created by Simon_Shi on 2024/1/5.
#include "../Header/business.h"
#include "../Header/file management.h"

flightData::flightData() {
    long int n = 0;
//    cout << "num_block is " << file_management::num_block<data_flight>("data_flight.dat") << endl;  //测试
    data_flight *pt = new data_flight();
    head = pt;
    for (llu i = 0; i < file_management::num_block<data_flight>("data_flight.dat"); i++) {
        if (file_management::read(pt, "data_flight.dat", &n)) {
            if (i == file_management::num_block<data_flight>("data_flight.dat") - 1) break;  //最后一个节点不要创建下一节点
            data_flight *nextnode = new data_flight();
            pt->next = nextnode;
            pt = nextnode;
        } else {
            cerr << "error in reading !" << endl;
            break;
        }
    }
//    cout << "The link list builds up correctly!" << endl;
}

flightData::~flightData() {
    data_flight *p = head;
    while (p != nullptr) {
        data_flight *nextnode = p->next;
        delete p;
        p = nextnode;
    }
    head = nullptr;
}

void flightData::Add() {
    data_flight *nextnode = new data_flight();  // 创建新节点
    nextnode->next = nullptr;

    if (head == nullptr) head = nextnode;  // 如果链表为空，将新节点作为头节点
    else {
        data_flight *temp = head; // 找到链表末尾，将新节点连接到链表末尾
        while (temp->next != nullptr) temp = temp->next;
        temp->next = nextnode;
    }

    cin >> *nextnode;

    cout << "over!" << endl;

}

void flightData::Query() {
    data_flight *p = head;
    int n = 1;  //节点数

    while (p != nullptr) {
        cout << n++ << ":";  //同上，节点数

        cout << *p << endl;

        p = p->next;
    }
}

void flightData::Update() {
    data_flight *p = head;
    int num = 1;
    while (p != nullptr) {
        p = p->next;
        num++;
    }

    flightData::Query();

    cout << "choose one flight to update" << endl;

    cin >> num;
    p = head;
    for (int i = 0; i < num - 1; i++) p = p->next;

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

    cout << "Please update rated_passengers" << endl;
    cin >> p->rated_passengers;

    cout << "Please update remaining_ticket" << endl;
    cin >> p->remaining_ticket;

    cout << "Please update remaining_firstclass" << endl;
    cin >> p->remaining_firstclass;

    cout << "Please update remaining_businessclass" << endl;
    cin >> p->remaining_businessclass;

    cout << "Please update remaining_economyclass" << endl;
    cin >> p->remaining_economyclass;

    cout << "Please update candidate_number" << endl;
    cin >> p->candidate_number;

    cout << "over!" << endl;
}

void flightData::Delete() {
    data_flight *p = head;  //p是删除节点前一个
    data_flight *r = head;  //p是删除节点
    data_flight *b = head;  //p是删除节点后一个
    int num = 1;
    while (p != nullptr) {
        p = p->next;
        num++;
    }

    flightData::Query();

    cout << "choose one flight to delete" << endl;

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

ostream &operator<<(ostream &out, const flightData::data_flight &p) {  //提供给query函数
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
    out << p.rated_passengers;
    out << " ";
    out << p.remaining_ticket;
    out << " ";
    out << p.remaining_firstclass;
    out << " ";
    out << p.remaining_businessclass;
    out << " ";
    out << p.remaining_economyclass;
    out << " ";
    out << p.candidate_number;
    out << " ";

    return out;
}

istream &operator>>(istream &in, flightData::data_flight &p) {  //提供给add函数
    cout << "Please add starting station" << endl;
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
    cout << "Please add rated_passengers" << endl;
    in >> p.rated_passengers;
    cout << "Please add remaining_ticket" << endl;
    in >> p.remaining_ticket;
    cout << "Please add remaining_firstclass" << endl;
    in >> p.remaining_firstclass;
    cout << "Please add remaining_businessclass" << endl;
    in >> p.remaining_businessclass;
    cout << "Please add remaining_economyclass" << endl;
    in >> p.remaining_economyclass;
    cout << "Please add candidate_number" << endl;
    in >> p.candidate_number;

    //>> std::setw(20)

    return in;
}