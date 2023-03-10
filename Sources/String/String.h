/**
 * @file String.h
 * @author 青羽 (chen_qingyu@qq.com, https://chen-qingyu.github.io/)
 * @brief 字符串 (String)
 * @version 1.0
 * @date 2022.11.03
 *
 * @copyright Copyright (c) 2022
 *
 * Functions:
 * - Constructor / Destructor:
 *   - String_Create        Create an empty string.
 *   - String_From          Create a string from null-terminated byte string.
 *   - String_Copy          Copy constructor.
 *   - String_Move          Move constructor.
 *   - String_Destroy       Destroy a string.
 * - Assignment:
 *   - String_CopyAssign    Copy assignment operation.
 *   - String_MoveAssign    Move assignment operation.
 * - Getter / Setter:
 *   - String_Get           Get the copy of the contents of the string.
 *   - String_Set           Set the contents of the string using null-terminated byte string.
 * - Examination (will not change the object itself):
 *   - String_Size          Find the size of the string.
 *   - String_IsEmpty       Determine whether the string is empty.
 *   - String_Print         Print the contents of the string.
 *   - String_At            Take the i-th character of the string.
 *   - String_Equal         Determine whether the two strings have the same contents.
 *   - String_Compare       Compare two strings lexicographically.
 *   - String_Find          Find the position of the pattern.
 *   - String_ToDecimal     Convert the string to a double-precision floating-point decimal number.
 *   - String_ToInteger     Convert the string to an integer number based on 2-36 base.
 *   - String_Count         Count the number of occurrences of a specified character.
 * - Manipulation (will change the object itself):
 *   - String_Lower         Convert the string to lowercase.
 *   - String_Upper         Convert the string to uppercase.
 *   - String_Append        Append new string to the tail.
 *   - String_Erase         Erase the contents of a range of string.
 *   - String_Reverse       Reverse the string in place.
 *   - String_Replace       Replace the string.
 *   - String_Strip         Remove leading and trailing blank characters of the string.
 *   - String_Swap          Swap the contents of two strings.
 *   - String_Clear         Clear the contents of the string.
 * - Production (will produce new object):
 *   - String_Split         Split string with separator.
 *   - String_Slice         Return slice of the string from start to stop with certain step.
 * - Auxiliary (helper functions):
 *   - String_DestroyArray  Destroy a string array. For String_Split().
 */

#ifndef STRING_H
#define STRING_H

/*******************************
 * Type declaration.
 *******************************/

// For `true` and `false`.
#include <stdbool.h>

// For `HUGE_VAL`, `NAN` and `INFINITY`.
// HUGE_VAL: Indicate the value is too big to be representable.
// NAN: Not a number.
// INFINITY: Positive infinity.
#include <math.h>

// String structure declaration.
typedef struct String String;

// Used for string comparison.
enum Order
{
    // Less Than.
    LT = -1,

    // Equal.
    EQ = 0,

    // Grater Than.
    GT = 1,
};

/*******************************
 * Interface function declaration.
 *******************************/

/**
 * Constructor / Destructor
 */

/**
 * @brief Create an empty string. Constructor. O(1)
 *
 * Like `string new_str();` in C++.
 *
 * Example: string *new_str = String_Create();
 *
 * @return A pointer to the empty string.
 */
String* String_Create(void);

/**
 * @brief Create a string from null-terminated byte string. O(N)
 *
 * Like `string new_str("hello");` in C++.
 *
 * Example: string *new_str = String_From("hello");
 *
 * @param chars A pointer to a null-terminated byte string.
 * @return A pointer to the new string.
 */
String* String_From(const char* chars);

/**
 * @brief Create a line of string from standard input. O(N)
 *
 * @return A pointer to the new string.
 */
String* String_Input(void);

/**
 * @brief Copy constructor. O(N)
 *
 * Like `string new_str(str);` in C++.
 *
 * Example: string *new_str = String_Copy(str);
 *
 * @param str A pointer to the string.
 * @return A pointer to the copied string.
 */
String* String_Copy(const String* str);

/**
 * @brief Move constructor. O(1)
 *
 * Like `string new_str(std::move(str));` in C++.
 *
 * Example: string *new_str = String_Move(str); // after moved, `str` is an empty string
 *
 * @param str A pointer to the string to be moved.
 * @return A pointer to the moved string.
 */
String* String_Move(String* str);

/**
 * @brief Destroy a string. O(1)
 *
 * Like `str.~string();` in C++.
 *
 * Example: String_Destroy(self);
 *
 * @param self A pointer to the string to be destroyed.
 */
void String_Destroy(String* self);

/**
 * Assignment
 */

/**
 * @brief Copy assignment operation. O(N)
 *
 * Like `self = that;` in C++.
 *
 * Example: String_CopyAssign(self, that);
 *
 * @param self A pointer to the left hand side string.
 * @param that A pointer to the right hand side string.
 */
void String_CopyAssign(String* self, const String* that);

/**
 * @brief Move assignment operation. O(1)
 *
 * Like `self = std::move(that);` in C++.
 *
 * Example: String_MoveAssign(self, that);
 *
 * @param self A pointer to the left hand side string.
 * @param that A pointer to the right hand side string.
 */
void String_MoveAssign(String* self, String* that);

/**
 * Getter / Setter
 */

/**
 * @brief Get the copy of the contents of the string. O(N)
 *
 * Example: char *chars = String_Get(self);
 *
 * @param self A pointer to the string.
 * @return A pointer to a null-terminated byte string.
 */
char* String_Get(const String* self);

/**
 * @brief Set the contents of the string using null-terminated byte string. O(N)
 *
 * Example: String_Set(self, "hello");
 *
 * @param self A pointer to the string to be set.
 * @param chars A pointer to a null-terminated byte string.
 */
void String_Set(String* self, const char* chars);

/**
 * Examination (will not change the object itself)
 */

/**
 * @brief Find the size of the string. O(1)
 *
 * @param self A pointer to the string.
 * @return The size of the string.
 */
int String_Size(const String* self);

/**
 * @brief Determine whether the string is empty. O(1)
 *
 * @param self A pointer to the string.
 * @return Returns true if the string is empty, false otherwise.
 */
bool String_IsEmpty(const String* self);

/**
 * @brief Print the contents of the string. O(N)
 *
 * @param self A pointer to the string to be printed.
 */
void String_Print(const String* self);

/**
 * @brief Take the i-th character of the string. O(1)
 *
 * If i is negative, the index is relative to the end of the string.
 *
 * @param self A pointer to the string.
 * @param i Index (-String_Size(self) <= i < String_Size(self)).
 * @return The i-th character.
 */
char String_At(const String* self, int i);

/**
 * @brief Determine whether the two strings have the same contents. O(N)
 *
 * @param self A pointer to the first string.
 * @param that A pointer to the second string.
 * @return Returns true if the contents of the two strings are the same, false otherwise.
 */
bool String_Equal(const String* self, const String* that);

/**
 * @brief Compare two strings lexicographically. O(N)
 *
 * @param self A pointer to the first string.
 * @param that A pointer to the second string.
 * @return An enumeration value: order{LT, EQ, GT}.
 */
enum Order String_Compare(const String* self, const String* that);

/**
 * @brief Return the index of the first occurrence of the specified pattern in the string (at or after index start and before index stop). O(N + M)
 *
 * Or -1 if the string does not contain the pattern (in the specified range).
 *
 * Implemented by the KMP algorithm.
 *
 * @param self A pointer to the string.
 * @param pattern A pointer to the pattern string.
 * @param start At or after index start.
 * @param stop Before index stop.
 * @return Returns the starting substring index or -1 if the string does not contain the pattern.
 */
int String_Find(const String* self, const String* pattern, int start, int stop);

/**
 * @brief Convert the string to a double-precision floating-point decimal number. O(N)
 *
 * If the string is too big to be representable will return `HUGE_VAL`.
 * If the string represents nan ("[+-]?(nan, NaN, NAN)") will return `NAN`.
 * If the string represents infinity ("[+-]?(inf, Inf, INF, infinity, Infinity, INFINITY)") will return `[+-]?INFINITY`.
 *
 * Example: string *str1 = String_From("233.33");
 *          double number1 = String_ToDecimal(str1); // => 233.33
 *
 *          string *str2 = String_From("1e+600");
 *          double number2 = String_ToDecimal(str2); // => HUGE_VAL
 *
 *          string *str3 = String_From("nan");
 *          double number3 = String_ToDecimal(str3); // => NAN
 *
 *          string *str4 = String_From("inf");
 *          double number4 = String_ToDecimal(str4); // => INFINITY
 *
 * @param self String to be parsed.
 * @return A number that can represent the string or HUGE_VAL or NAN or [+-]?INFINITY.
 */
double String_ToDecimal(const String* self);

/**
 * @brief Convert the string to an integer number based on 2-36 base. O(N)
 *
 * Numeric character in 36 base: 0, 1, ..., 9, A(10), ..., F(15), G(16), ..., Y(34), Z(35).
 *
 * Example: string *str1 = String_From("233");
 *          long long number1 = String_ToInteger(str1, 10); // => 233
 *
 *          string *str2 = String_From("cafebabe");
 *          long long number2 = String_ToInteger(str2, 16); // => 3405691582
 *
 *          string *str3 = String_From("z");
 *          long long number3 = String_ToInteger(str3, 36); // => 35
 *
 * @param self String to be parsed.
 * @param base The base of an integer (2 <= base <= 36).
 * @return An integer number that can represent the string.
 */
long long String_ToInteger(const String* self, int base);

/**
 * @brief Count the number of occurrences of a specified character. O(N)
 *
 * @param self A pointer to the string.
 * @param ch Character.
 * @return The total number of occurrences of ch in the string.
 */
int String_Count(const String* self, char ch);

/**
 * Manipulation (will change the object itself)
 */

/**
 * @brief Convert the string to lowercase. O(N)
 *
 * @param self A pointer to the string.
 */
void String_Lower(String* self);

/**
 * @brief Convert the string to uppercase. O(N)
 *
 * @param self A pointer to the string.
 */
void String_Upper(String* self);

/**
 * @brief Append new string to the tail. O(N)
 *
 * @param self A pointer to the string.
 * @param str A pointer to the new string.
 */
void String_Append(String* self, const String* str);

/**
 * @brief Erase the contents of a range of string. O(N)
 *
 * @param self A pointer to the string to be erased.
 * @param begin Begin range subscript (included).
 * @param end End range subscript (not included).
 */
void String_Erase(String* self, int begin, int end);

/**
 * @brief Reverse the string in place. O(N)
 *
 * @param self A pointer to the string.
 */
void String_Reverse(String* self);

/**
 * @brief Replace the string. O(N)
 *
 * @param self A pointer to the string to be replaced.
 * @param old_str Old substring.
 * @param new_str New substring.
 */
void String_Replace(String* self, const String* old_str, const String* new_str);

/**
 * @brief Remove leading and trailing blank characters of the string. O(N)
 *
 * @param self A pointer to the string.
 */
void String_Strip(String* self);

/**
 * @brief Swap the contents of two strings. O(1)
 *
 * @param self A pointer to the first string.
 * @param that A pointer to the second string.
 */
void String_Swap(String* self, String* that);

/**
 * @brief Clear the contents of the string. O(1)
 *
 * @param self A pointer to the string.
 */
void String_Clear(String* self);

/**
 * Production (will produce new object)
 */

/**
 * @brief Split string with separator. O(N)
 *
 * Example: string *str = String_From("one, two, three");
 *          string *sep = String_From(", ");
 *          string **str_arr = String_Split(str, sep); // => ["one", "two", "three", NULL]
 *
 * Don't forget use String_DestroyArray(return-value).
 *
 * @param self String to be split.
 * @param sep Separator string.
 * @return A null-terminated array of split string pointers.
 */
String** String_Split(const String* self, const String* sep);

/**
 * @brief Return slice of the string from start to stop with certain step. O(N)
 *
 * Index and step length can be negative.
 *
 * @param self A pointer to the string.
 * @param start Start index (included).
 * @param stop Stop index (excluded).
 * @param step Step length.
 * @return The slice of the string.
 */
String* String_Slice(const String* self, int start, int stop, int step);

/**
 * Auxiliary (helper functions)
 */

/**
 * @brief Destroy a string array. Helper function for String_Split(). O(N)
 *
 * @param str_arr A pointer to the string array to be destroyed.
 */
void String_DestroyArray(String** str_arr);

#endif // STRING_H
