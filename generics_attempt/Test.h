//
// Created by Bay Foley-Cox on 5/29/22.
//

#ifndef WEAKLY_QUEUEISH_STRUCTURES_TEST_H
#define WEAKLY_QUEUEISH_STRUCTURES_TEST_H


template<class A> class Test {
A a;
public:
    Test(A a);
};

template<class A>
Test<A>::Test(A a) {
    this->a = a;
}


#endif //WEAKLY_QUEUEISH_STRUCTURES_TEST_H
