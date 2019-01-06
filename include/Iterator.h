//
// Created by zero on 1/6/19.
//

#ifndef ITERATOR_H
#define ITERATOR_H

#include <cstddef>

namespace mySTL {

    struct input_iterator_tag {};        // 返回输入迭代器
    struct output_iterator_tag {};       // 返回输出迭代器
    // 正向迭代器有输入和输出迭代器的所有功能，可以从输入迭代器继承
    // 这里体现了五种迭代器的层次结构
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    // 输入迭代器，通过解引用可以读取容器中元素的值，但不能修改，单向迭代器，只能递增，不能倒退，通常用于传递地址
    template <class T, class Distance>
    struct input_iterator {
        typedef input_iterator_tag iterator_category;   // 返回类型
        typedef T                  value_type;          // 所指对象类型
        // difference_type代表了容器的容量，如果需要返回一个容器的大小，那么就需要返回difference_type类型
        typedef Distance           difference_type;     // 迭代器间距离类型
        typedef T *                pointer;             // 指针操作结果类型
        typedef T &                reference;           // 解引用操作结果类型
    };

    // 输出迭代器，只写。通常用于返回地址
    struct output_iterator {
        typedef output_iterator_tag iterator_category;
        typedef void                value_type;
        typedef void                difference_type;
        typedef void                pointer;
        typedef void                reference;
    };

    // 正向迭代器，可以进行读写操作，在输入迭代器的基础上增加了输出迭代器的部分特性
    template <class T, class Distance>
    struct forward_iterator {
        typedef forward_iterator_tag iterator_category;
        typedef T                  value_type;          // 所指对象类型
        typedef Distance           difference_type;     // 迭代器间距离类型
        typedef T *                pointer;             // 指针操作结果类型
        typedef T &                reference;           // 解引用操作结果类型
    };

    // 双向迭代器，拥有正向迭代器的所有特性，在此基础上提供了向后迭代元素的能力
    template <class T, class Distance>
    struct bidirectional_iterator {
        typedef bidirectional_iterator_tag iterator_category;
        typedef T                          value_type;          // 所指对象类型
        typedef Distance                   difference_type;     // 迭代器间距离类型
        typedef T *                        pointer;             // 指针操作结果类型
        typedef T &                        reference;           // 解引用操作结果类型
    };

    // 随机迭代器，拥有上述所有迭代器的功能，可以像指针那样进行算术计算
    template <class T, class Distance>
    struct random_access_iterator {
        typedef random_access_iterator_tag iterator_category;
        typedef T                          value_type;          // 所指对象类型
        typedef Distance                   difference_type;     // 迭代器间距离类型
        typedef T *                        pointer;             // 指针操作结果类型
        typedef T &                        reference;           // 解引用操作结果类型
    };


}

#endif // ITERATOR_H
