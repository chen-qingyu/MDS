/**
 * @file LinkedStack.h
 * @author 青羽 (chen_qingyu@qq.com)
 * @brief 栈 链表实现 (Linked Stack)
 * @version 1.0
 * @date 2022.01.28
 *
 * @copyright Copyright (c) 2022
 */

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <stdbool.h> // bool

typedef int LinkedStackItem;

typedef struct LinkedStack LinkedStack;

/**
 * @brief 创建一个空栈
 *
 * @return 一个指向空栈的指针
 */
LinkedStack* LinkedStack_Create(void);

/**
 * @brief 销毁一个栈
 *
 * @param self 一个指向待销毁栈的指针
 */
void LinkedStack_Destroy(LinkedStack* self);

/**
 * @brief 求栈的长度
 *
 * @param self 一个指向栈的指针
 * @return 栈长度
 */
int LinkedStack_Size(const LinkedStack* self);

/**
 * @brief 判断栈是否已空
 *
 * @param self 一个指向栈的指针
 * @return 如果栈已空则返回 true ，否则返回 false
 */
bool LinkedStack_IsEmpty(const LinkedStack* self);

/**
 * @brief 入栈，将元素 data 压入到栈的顶部
 *
 * @param self 一个指向栈的指针
 * @param data 一个待入栈的元素
 */
void LinkedStack_Push(LinkedStack* self, LinkedStackItem data);

/**
 * @brief 出栈，将栈的顶部的元素弹出来
 *
 * @param self 一个指向栈的指针
 * @return 栈顶元素
 */
LinkedStackItem LinkedStack_Pop(LinkedStack* self);

/**
 * @brief 检查栈的顶部元素，不改变栈
 *
 * @param self 一个指向栈的指针
 * @return 栈顶元素
 */
LinkedStackItem LinkedStack_Top(const LinkedStack* self);

/**
 * @brief 清空栈的内容
 *
 * @param self 一个指向栈的指针
 */
void LinkedStack_Clear(LinkedStack* self);

#endif // LINKEDSTACK_H
