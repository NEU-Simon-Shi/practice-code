// Created by Simon_Shi on 2024/1/5.

#ifndef COURSE_DESIGN_FILE_MANAGEMENT_H
#define COURSE_DESIGN_FILE_MANAGEMENT_H

#include "iostream"
#include "fstream"

#define llu unsigned long long int

using namespace std;


class file_management {
public:
    file_management();

    ~file_management();

    template<typename T>  //��ȡ����
    static bool read(T *head, string file_name, long int *n);  //n��λ�Ƶ�λ��

    template<typename T>  //д�뺯��
    static void write(int mod,T *head, string file_name);  //modΪ1��׷��д�룬2������д��

    template<typename T>  //��ȡnum_block����
    static llu num_block (string file_name);
};

template<typename T>
bool file_management::read(T *head, string file_name, long int *n) {
    ifstream Read(file_name, ios::binary | ios::in);

    if (!Read.is_open()) {
        cerr << "Unable to open file bad: " << file_name << endl;  //����Ƿ�������
        Read.close();
        return false;
    } else {
        Read.seekg((*n) * (sizeof(T) - sizeof(void *)), ios::beg);
        Read.read(reinterpret_cast<char *>(head), sizeof(T) - sizeof(void *));
        //cout << "Reach here:"<< sizeof(T)-sizeof(void *)<<" readcout:"<<Read.gcount()<<endl;
        // ����Ƿ��Ѿ���ȡ�������ĩβ
        if (Read.gcount() < sizeof(T) - sizeof(void *)) {
            Read.close();
            cerr << "Unable to open file: " << file_name << " error:" << errno << ' ' << Read.gcount()
                 << endl;  //����Ƿ�������
            return false;
        }

        (*n)++;
        Read.close();
        return true;
    }
}

template<typename T>
void file_management::write(int mod,T *head, string file_name) {
    ofstream Write;
    if(mod==1)  Write.open(file_name, ios::binary | ios::app);
    else    Write.open(file_name, ios::binary | ios::trunc);

    Write.write(reinterpret_cast<char *>(head), sizeof(T) - sizeof(void *));

    Write.close();
}

template<typename T>  //��ȡnum_block����
llu file_management::num_block (string file_name){
    ifstream file(file_name);
    file.seekg(0, ios::end);
    llu num = file.tellg() / (sizeof(T) - sizeof(void *));
    file.close(); // �ر��ļ���
    return num;
}

#endif //COURSE_DESIGN_FILE_MANAGEMENT_H