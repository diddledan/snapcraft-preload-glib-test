project(glib-test)
cmake_minimum_required(VERSION 3.5)

find_package (PkgConfig REQUIRED)
pkg_search_module(GLIB REQUIRED glib-2.0)
pkg_search_module(GIO REQUIRED gio-2.0)

include_directories(${GLIB_INCLUDE_DIRS})
include_directories(${GIO_INCLUDE_DIRS})
link_directories(${GLIB_LIBRARY_DIRS})
link_directories(${GIO_LIBRARY_DIRS})

add_executable(glib-test main.c)
add_definitions(${GLIB_CFLAGS_OTHER})
target_link_libraries(glib-test ${GLIB_LIBRARIES} ${GIO_LIBRARIES})

install(TARGETS glib-test RUNTIME DESTINATION bin)