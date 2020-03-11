Compiling/running unit tests
------------------------------------

Unit tests will be automatically compiled if dependencies were met in configure
and tests weren't explicitly disabled.

After configuring, they can be run with 'make check'.

To run the happyleafd tests manually, launch src/test/test_happyleaf .

To add more happyleafd tests, add `BOOST_AUTO_TEST_CASE` functions to the existing
.cpp files in the test/ directory or add new .cpp files that
implement new BOOST_AUTO_TEST_SUITE sections.

To run the happyleaf-qt tests manually, launch src/qt/test/happyleaf-qt_test

To add more happyleaf-qt tests, add them to the `src/qt/test/` directory and
the `src/qt/test/test_main.cpp` file.
