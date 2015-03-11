ADD_EXECUTABLE ( test_board 
    test_board.cpp
    board.h
    disk.h
    disk.cpp
    coordinates.h
    color.h
)

INSTALL (TARGETS test_board DESTINATION bin)
