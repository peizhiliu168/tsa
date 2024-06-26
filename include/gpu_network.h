#pragma once

#include <vector>

#include "nccl.h"

class GPUNetwork {
public:
    void Initialize();
    void Cleanup();

    const int kBufferSize = 1 << 23;

    int size_;
    int node_rank_;
    int local_rank_;

    ncclUniqueId id_;
    ncclComm_t comm_;
    cudaStream_t stream_;
    char* buffer_;
    char* host_buffer_;
    cudaEvent_t start_timer_;
    cudaEvent_t stop_timer_;

private:
    void SetGPU();
};
