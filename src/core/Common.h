#pragma once

#define SafeRelease(ptr)\
    if ((ptr) != nullptr && (ptr) != ((void*)-1))\
        delete (ptr);\
        (ptr) = nullptr

#define SafeReleaseArray(ptr)\
    if ((ptr) != nullptr && (ptr) != ((void*)-1))\
        delete[] (ptr);\
        (ptr) = nullptr