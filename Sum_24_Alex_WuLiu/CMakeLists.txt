add_executable(BestGame main.cpp)

target_include_directories(BestGame PRIVATE ../Farming/include)

target_link_libraries(BestGame Farming)