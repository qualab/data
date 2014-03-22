/// @author Владимир Керимов

#pragma once

#if !defined(WIN32) || defined(DATA_STATIC)
#   define DATA_API
#elif defined(DATA_EXPORTS)
#   define DATA_API __declspec(dllexport)
#else
#   define DATA_API __declspec(dllimport)
#endif

// sine qua non
