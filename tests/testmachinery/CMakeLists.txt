set(library_name testmachinery)

file(GLOB source_files "*.cpp")
file(GLOB include_files "*.h")

find_package(Qt5Core REQUIRED)
find_package(Qt5Test REQUIRED)

if(WIN32)
    add_definitions(-DGTEST_LINKED_AS_SHARED_LIBRARY)
endif()

add_library(${library_name} STATIC ${source_files} ${include_files})
target_link_libraries(${library_name} gtest gmock Qt5::Core Qt5::Test mvvm)
target_include_directories(${library_name} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR} > ${MVVM_PRIVATE_API})
