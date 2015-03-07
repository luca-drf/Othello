MESSAGE ( STATUS ${CMAKE_SOURCE_DIR} )

INCLUDE_DIRECTORIES ( ${CMAKE_SOURCE_DIR}/src )

INCLUDE_DIRECTORIES ( ${GTEST_INCLUDE_DIRS} )

ADD_EXECUTABLE ( AllTests
    AllTests.cpp
    BoardTest.cpp
    DiskTest.cpp
    ${CMAKE_SOURCE_DIR}/src/board.h
    ${CMAKE_SOURCE_DIR}/src/disk.h
    ${CMAKE_SOURCE_DIR}/src/disk.cpp    
    ${CMAKE_SOURCE_DIR}/src/color.h
    ${CMAKE_SOURCE_DIR}/src/coordinates.h
)

TARGET_LINK_LIBRARIES ( AllTests
    ${GTEST_LIBRARIES}
)

INSTALL (TARGETS AllTests DESTINATION bin)
