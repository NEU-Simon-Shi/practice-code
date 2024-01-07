// Created by Simon_Shi on 2024/1/5.

#ifndef COURSE_DESIGN_BUSINESS_H
#define COURSE_DESIGN_BUSINESS_H

#include "iostream"
#include "iomanip"
#include "vector"
#include "queue"
#include "cstring"

using namespace std;

//ҵ�����
class business {
public:
    virtual void Add() = 0;

    virtual void Query() = 0;

    virtual void Update() = 0;

    virtual void Delete() = 0;

};

class flightData : public business {
private:
//  ������ݵ����� data_flight(link list);
    typedef struct data_flight {
        char starting_station[20];  //���վ
        char terminal[20];  //�յ�վ
        char flight_number[20];  //�����
        char aircraft_number[20];  //�ɻ���
        char departure_time[20];  //���ʱ��
        char landing_time[20];  //���ʱ��

        int rated_passengers = 0;  //��Ա����
        int remaining_ticket = 0;  //����Ʊ��
        int remaining_firstclass = 0;  //ͷ�Ȳ���Ʊ��
        int remaining_businessclass = 0;  //�������Ʊ��
        int remaining_economyclass = 0;  //���ò���Ʊ��

        int candidate_number = 0;  //������

        data_flight *next = nullptr;

    } data_flight;

    data_flight *head = nullptr;

public:
    flightData();  //��ʼ��

    ~flightData();

    virtual void Add();

    virtual void Query();


    virtual void Update();

    virtual void Delete();

    friend ostream &operator<<(ostream &, const data_flight &);

    friend istream &operator>>(istream &, data_flight &);
};

class customer_list : public business {
private:
//  ������ݵ�����  data_customer(link list);
    typedef struct data_customer {
        char name[20];  //�ͻ�����
        unsigned long long int phonenumber = 0;  //�ֻ�����
        int ticket_number;  //��Ʊ��
        char Class[20];  //��λ�ȼ�

        char starting_station[20];  //���վ
        char terminal[20];  //�յ�վ
        char flight_number[20];  //�����
        char aircraft_number[20];  //�ɻ���
        char departure_time[20];  //���ʱ��
        char landing_time[20];  //���ʱ��

        data_customer *next = nullptr;
    } data_customer;

    data_customer *head = nullptr;

public:
    customer_list();  //��ʼ��

    ~customer_list();

    virtual void Add();

    virtual void Query();

    virtual void Update();

    virtual void Delete();

    friend ostream &operator<<(ostream &, const data_customer &);

    friend istream &operator>>(istream &, data_customer &);
};


class waiting_list : public business {  //���Ƿŵ�������ͷ��
private:
//  ������ݵĶ���(����ǿ���������)  data_waiting(queue);
    typedef struct data_waiting {
        char name[20];  //�ͻ�����
        unsigned long long int phonenumber = 0;  //�ֻ�����
        int ticket_number;  //��Ʊ��
        char Class[20];  //��λ�ȼ�

//        char flight_number[20];  //�����

        data_waiting *next = nullptr;
    } data_waiting;

    data_waiting *head = nullptr;

public:
    waiting_list(char flight_number[20]);  //��ʼ��
    ~waiting_list();
    virtual void Add();

    virtual void Query();

    void Delete(int *ticket);

    friend ostream &operator<<(ostream &, const data_waiting &);

    friend istream &operator>>(istream &, data_waiting &);

};

class transferData : public business {
private:
//  ������ݵ����� data_transfer(link list);
public:
//    transferData();  ��ʼ��
    virtual void Query();

};

#endif //COURSE_DESIGN_BUSINESS_H