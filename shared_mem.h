#pragma once

#include <sys/shm.h>

namespace smemlloc
{

class SMem
{
//´´½¨
public:
    void *createSMem();
    void *attachSMem();
    void *getFileKey();
public:
    SMem& get_instance()
    {
        static SMem smem;
        return smem;
    }


}

}