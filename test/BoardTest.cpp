#include "gtest/gtest.h"

#include "board.h"
#include "disk.h"
#include "color.h"
#include "coordinates.h"


class BoardTest : public ::testing::Test
{
protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    BoardTest() {
        // You can do set-up work for each test here.
    }

    virtual ~BoardTest() {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    virtual void SetUp() {
        // Code here will be called immediately after the constructor (right
        // before each test).

    }

    virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }

    // Objects declared here can be used by all tests in the test case.
    Board< Disk > board;        
    
};


TEST_F(BoardTest, UnitTest) 
{
    board.set_dim(8);
    coord coords = coord(3, 4);
    Color expected = Color::NONE;
    auto result = board.at(coords);
    ASSERT_EQ( expected, result.get_color() );
}


