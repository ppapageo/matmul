add_library(matmul BaseMM.cpp GEMM.cpp VanillaMM.cpp CgenMM.cpp MMUtils.cpp)

add_executable(time_mm time_mm.cpp)
target_link_libraries(time_mm matmul string_exec dl openblas)
