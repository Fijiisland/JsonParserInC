cmake_minimum_required(VERSION 3.17)

project(JsonParser C)

add_executable(JsonParse test.c leptjson.h leptjson.c)