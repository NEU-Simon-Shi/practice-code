// Created by Simon_Shi on 2024/1/5.

#ifndef COURSE_DESIGN_BUSINESS_H
#define COURSE_DESIGN_BUSINESS_H

#include "iostream"
#include "iomanip"
#include "vector"
#include "queue"
#include "cstring"

using namespace std;

//业务基类
class business {
public:
    virtual void Add() = 0;

    virtual void Query() = 0;

    virtual void Update() = 0;

    virtual void Delete() = 0;

};

class flightData : public business {
private:
//  存放数据的链表 data_flight(link list);
    typedef struct data_flight {
        char starting_station[20];  //起点站
        char terminal[20];  //终点站
        char flight_number[20];  //航班号
        char aircraft_number[20];  //飞机号
        char departure_time[20];  //起飞时间
        char landing_time[20];  //落地时间

        int rated_passengers = 0;  //乘员定额
        int remaining_ticket = 0;  //总余票量
        int remaining_firstclass = 0;  //头等舱余票量
        int remaining_businessclass = 0;  //商务舱余票量
        int remaining_economyclass = 0;  //经济舱余票量

        int candidate_number = 0;  //候补人数

        data_flight *next = nullptr;

    } data_flight;

    data_flight *head = nullptr;

public:
    flightData();  //初始化

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
//  存放数据的链表  data_customer(link list);
    typedef struct data_customer {
        char name[20];  //客户姓名
        unsigned long long int phonenumber = 0;  //手机号码
        int ticket_number;  //订票量
        char Class[20];  //舱位等级

        char starting_station[20];  //起点站
        char terminal[20];  //终点站
        char flight_number[20];  //航班号
        char aircraft_number[20];  //飞机号
        char departure_time[20];  //起飞时间
        char landing_time[20];  //落地时间

        data_customer *next = nullptr;
    } data_customer;

    data_customer *head = nullptr;

public:
    customer_list();  //初始化

    ~customer_list();

    virtual void Add();

    virtual void Query();

    virtual void Update();

    virtual void Delete();

    friend ostream &operator<<(ostream &, const data_customer &);

    friend istream &operator>>(istream &, data_customer &);
};


class waiting_list : public business {  //还是放到航班里头吧
private:
//  存放数据的队列(最后还是考虑用链表)  data_waiting(queue);
    typedef struct data_waiting {
        char name[20];  //客户姓名
        unsigned long long int phonenumber = 0;  //手机号码
        int ticket_number;  //订票量
        char Class[20];  //舱位等级

//        char flight_number[20];  //航班号

        data_waiting *next = nullptr;
    } data_waiting;

    data_waiting *head = nullptr;

public:
    waiting_list(char flight_number[20]);  //初始化
    ~waiting_list();
    virtual void Add();

    virtual void Query();

    void Delete(int *ticket);

    friend ostream &operator<<(ostream &, const data_waiting &);

    friend istream &operator>>(istream &, data_waiting &);

};

class transferData : public business {
private:
//  存放数据的链表 data_transfer(link list);
public:
//    transferData();  初始化
    virtual void Query();

};

#endif //COURSE_DESIGN_BUSINESS_H