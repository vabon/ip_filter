#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE test_filter_any

#include "lib.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_filter_any)

BOOST_AUTO_TEST_CASE(test_filter_46)
{
	BOOST_CHECK(filter(46));
}

BOOST_AUTO_TEST_SUITE_END()
