#pragma once


#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif


extern "C" MATHLIBRARY_API int Test1(const int n, const int repeats);

extern "C" MATHLIBRARY_API void Calc(const int n, double* a, double* b, double* result);
