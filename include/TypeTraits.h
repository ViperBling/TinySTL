//
// Created by zero on 1/6/19.
//

#ifndef TYPETRAITS_H
#define TYPETRAITS_H

namespace mySTL {
    namespace {
        template <bool, class Ta, class Tb>
        struct IfThenElse;
        template <class Ta, class Tb>
        struct IfThenElse < true, Ta, Tb > {
            using result = Ta;
        };
        template <class Ta, class Tb>
        struct IfThenElse < false, Ta, Tb > {
            using result = Tb;
        };
    }

    struct _true_type {};
    struct _false_type {};

    
}

#endif // TYPETRAITS_H
