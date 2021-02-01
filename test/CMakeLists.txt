add_executable(mm_test main.cpp mm_test.cpp)

target_link_libraries(mm_test matmul GTest::GTest GTest::Main pthread string_exec dl openblas)

add_test(NAME mm_test
	COMMAND mm_test)
