#pragma once

#include <sys/shm.h>
#include <iostream>

namespace smemlloc
{
//shared memmory
class SMem
{
public:
    SMem(): shm_id_(0), key_(0), is_create_(false) {}
    void *createSMem(const size_t &size);
    void *attachSMem();
    void *getFileKey();
public:
    SMem& get_instance()
    {
        static SMem smem;
        return smem;
    }
private:
    //�����ڴ�id
    int shm_id_;
    //��
    key_t key_;
    //�Ƿ�ɹ����뵽�����ڴ�
    bool is_create_;
};

}