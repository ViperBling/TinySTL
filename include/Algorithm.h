//
// Created by zero on 1/6/19.
//

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include ""
#include "Iterator.h"

namespace mySTL {
    // ********** [advance] **************
    // ********** [Algorithm Complexity: O(n)] *****************
    namespace {
        template <class InputIterator, class Distance>
        void _advance(InputIterator & it, Distance n, input_iterator_tag) {
            assert (n >= 0);
            while (n--)
                ++it;
        }

        template <class BidirectionIterator, class Distance>
        void _advance(BidirectionIterator & it, Distance n, bidirectional_iterator_tag) {
            if (n < 0)
                while (n++)
                    --it;
            else
                while (n--)
                    ++it;
        }

        template <class RandomIterator, class Distance>
        void _advance(RandomIterator & it, Distance n, random_access_iterator_tag) {
            if (n < 0)
                it -= -n;
            else
                it += n;
        }

        template <class InputIterator, class Distance>
        void advance(InputIterator & it, Distance n) {
            typedef typename iterator_traits<InputIterator>::iterator_category iterator_category;
            _advance(it, n, iterator_category());
        }
    }

}


#endif // ALGORITHM_H
