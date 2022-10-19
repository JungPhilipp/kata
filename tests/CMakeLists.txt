add_executable(UnitChop test_chop.cpp)

target_link_libraries(UnitChop PRIVATE src)

add_test(UnitChop UnitChop)
