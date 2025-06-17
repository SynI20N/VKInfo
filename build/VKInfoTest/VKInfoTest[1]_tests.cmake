add_test([=[AtomicMetricTest.TestFlush]=]  /home/leonid/Projects/VKInfo/build/VKInfoTest/VKInfoTest [==[--gtest_filter=AtomicMetricTest.TestFlush]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[AtomicMetricTest.TestFlush]=]  PROPERTIES WORKING_DIRECTORY /home/leonid/Projects/VKInfo/build/VKInfoTest SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  VKInfoTest_TESTS AtomicMetricTest.TestFlush)
