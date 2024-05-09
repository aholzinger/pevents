cmake_minimum_required(VERSION 3.20)

option(PEVENTS_SHARED "Build pevents as a shared library" ${BUILD_SHARED_LIBS})
if(PEVENTS_SHARED)
    set(PEVENTS_LIBTYPE SHARED)
else()
    set(PEVENTS_LIBTYPE STATIC)
endif()

add_library(pevents_lib ${PEVENTS_LIBTYPE})
message(VERBOSE "Building pevents as a ${PEVENTS_LIBTYPE} library")
add_library(pevents::lib ALIAS pevents_lib)

target_sources(pevents_lib
PUBLIC
    pevents.h
PRIVATE
    pevents.cpp
)

if(WIN32)
    set_target_properties(pevents_lib PROPERTIES
        WINDOWS_EXPORT_ALL_SYMBOLS ON
        POSITION_INDEPENDENT_CODE ON
        PUBLIC_HEADER "pevents.h"
    )
else()
    set_target_properties(pevents_lib PROPERTIES PUBLIC_HEADER "pevents.h")
endif()

target_include_directories(pevents_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

include(GNUInstallDirs)

install(TARGETS pevents_lib
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/pevents
)
