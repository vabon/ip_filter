#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE test_filter

#include "lib.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_filter)

BOOST_AUTO_TEST_CASE(test_filter_1)
{
	BOOST_CHECK(filter(1));
}

BOOST_AUTO_TEST_SUITE_END()
