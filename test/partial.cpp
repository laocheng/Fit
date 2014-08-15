#include <fit/partial.h>
#include "test.h"

fit::static_<fit::partial_adaptor<binary_class> > binary_partial = {};

fit::static_<fit::partial_adaptor<unary_class> > unary_partial = {};

fit::static_<fit::partial_adaptor<mutable_class> > mutable_partial = {};

fit::static_<fit::partial_adaptor<void_class> > void_partial = {};

fit::static_<fit::partial_adaptor<mono_class> > mono_partial = {};

FIT_TEST_CASE()
{
    fit::partial_adaptor<void_class>()(1);

    void_partial(1);
    void_partial()(1);
    FIT_TEST_CHECK(3 == binary_partial(1)(2));
    FIT_TEST_CHECK(3 == binary_partial(1, 2));
    FIT_TEST_CHECK(3 == unary_partial()(3));
    FIT_TEST_CHECK(3 == unary_partial(3));
    FIT_TEST_CHECK(3 == mono_partial(2));
    FIT_TEST_CHECK(3 == mono_partial()(2));

    int i1 = 1;
    FIT_TEST_CHECK(3 == binary_partial(2)(i1));
    FIT_TEST_CHECK(3 == mutable_partial(std::ref(i1))(2));
    FIT_TEST_CHECK(3 == i1);
    int i2 = 1;
    FIT_TEST_CHECK(3 == mutable_partial(i2, 2));
    FIT_TEST_CHECK(3 == i2);
    
}