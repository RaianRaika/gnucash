SET(TAX_US_TEST_INCLUDE_DIRS "")
SET(TAX_US_TEST_LIBS "")

GNC_ADD_TEST(test-link-module-tax-us test-link-module.c
  TAX_US_TEST_INCLUDE_DIRS TAX_US_TEST_LIBS
)

# This test not run in autotools build.
#GNC_ADD_SCHEME_TEST(test-load-module-tax-us test-load-module.in)
