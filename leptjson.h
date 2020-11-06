#ifndef LEPTJSON_H__
#define LEPTJSON_H__

#include <assert.h>
#include <stdlib.h>

#define lept_init(v) do { (v)->type = LEPT_NULL; } while(0)
#define lept_set_null(v) lept_free(v)

/*
 *  Enum lept_type
 *
 *  代表的json值类型：
 *  1. NULL值
 *  2. Boolean的true与false
 *  3. 数字类型
 *  4. 字符串类型
 *  5. 数组类型
 *  6. json对象
 */
typedef enum {
    LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER,
    LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT
} lept_type;

/*
 * 匿名Enum
 *
 * 分别代表：
 * 1. 解析成功
 * 2. 解析了一个空json文本
 * 3. 非法的json值
 * 4. json值结尾有非空字符
 */
enum {
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,
    LEPT_PARSE_INVALID_VALUE,
    LEPT_PARSE_ROOT_NOT_SINGULAR,
    LEPT_PARSE_NUMBER_TOO_BIG
};

/*
 *  Struct lept_value
 *
 *  一个存储json值的结构体
 */
typedef struct {
    union {
        struct { char* s; size_t len; }s; /* string */
        double n;                         /* number */
    }u;
    lept_type type;
} lept_value;

/*
 *  Fuction lept_parse
 *
 *  json文本解析入口Api
 *
 *  para1: 传入一个json值指针  para2: 传入一个json文本字符串指针
 */
int lept_parse(lept_value* v, const char* json);

/*
 *  Fuction lept_get_type
 *
 *  返回一个json值的类型
 *
 *  para1: 传入一个json值指针
 */
lept_type lept_get_type(const lept_value* v);

/*
 *  Fuction lept_get_number
 *
 *  返回一个json值的double域
 *
 *  para1: 传入一个json值指针
 */
double lept_get_number(const lept_value* v);
void lept_set_number(lept_value* v, double n);

int lept_get_boolean(const lept_value* v);
void lept_set_boolean(lept_value* v, int b);

const char* lept_get_string(const lept_value* v);
size_t lept_get_string_length(const lept_value* v);
void lept_set_string(lept_value* v, const char* s, size_t len);

#endif