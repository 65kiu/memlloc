#include "shared_mem.h"

namespace smemlloc
{
    void* SMem::createSMem(const size_t &size)
    {
        if (key_ <= 0)
        {
            return nullptr;
        }

        shm_id_ = shmget(key_, size, IPC_CREAT | 0666);
        if ((shm_id_ = shmget(key_, size, IPC_CREAT | 0666)) < 0)
        {
            std::cout << "shmget failed ..." << std::endl;
            return nullptr;
        }

        void* ptr = shmat(shm_id_, 0, 0);
        return ptr;
    }
}