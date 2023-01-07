cmake_minimum_required(VERSION 3.0.0)
project(BookingSystem VERSION 0.1.0)

include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(./src SRC_LIST)
add_executable(BookingSystem ${SRC_LIST})
