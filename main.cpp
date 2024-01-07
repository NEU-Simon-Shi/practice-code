// Created by Simon_Shi on 2024/1/5.

#include "Header/file management.h"
#include "Header/business.h"

using namespace std;

typedef struct data_flight1 {
    char starting_station[20];  //起点站
    char terminal[20];  //终点站
    char flight_number[20];  //航班号
    char aircraft_number[20];  //飞机号
    char departure_time[20];  //起飞时间
    char landing_time[20];  //落地时间

    int rated_passengers;  //乘员定额
    int remaining_ticket;  //总余票量
    int remaining_firstclass;  //头等舱余票量
    int remaining_businessclass;  //商务舱余票量
    int remaining_economyclass;  //经济舱余票量

    int candidate_number;  //候补人数
    data_flight1 *next = nullptr;

} data_flight1;

int main() {
/*
    //写入测试数据
    data_flight1 pointer1={"qinghuangdao","shenzhen","AH666","Z520","12:10","16:30"
    ,100,10,1,2,7,0};

    data_flight1 pointer2={"qinghuangdao","shenzhen","AH777","Z250","17:10","21:30"
            ,100,10,1,2,7,0};

    file_management::write(1,&pointer1,"data_flight.dat");
    file_management::write(1,&pointer2,"data_flight.dat");
*/
    flightData test;

    test.Query();

    while (1) {
        char x;
        cin >> x;
        switch (x) {
            case '1':
                test.Query();
                break;
            case '2':
                test.Add();
                break;
            case '3':
                test.Delete();
                break;
            case '4':
                test.Update();
                break;
            default:
                break;
        }
        if (x != '1' && x != '2' && x != '3' && x != '4') {
            cout << "finish! the program will close soon!" << endl;
            break;
        }
    }

    return 0;
}