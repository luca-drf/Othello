#include "gtest/gtest.h"

#include "board.h"
#include "disk.h"
#include "color.h"
#include "coordinates.h"
#include <vector>

using std::vector;


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
        board.set_dim(8);
        

    }

    virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }

    // Objects declared here can be used by all tests in the test case.
    Board< Disk > board;        
    
};


TEST_F(BoardTest, test_set_dim) 
{
    coord coords(3, 4);
    Color expected = Color::NONE;
    auto actual = board.at(coords);
    ASSERT_EQ( expected, actual.get_color() );
}

TEST_F(BoardTest, test_place_element) 
{
    coord coords(2, 2);
    board.place_element(Disk(Color::LIGHT), coords);
    auto actual = board.at(coords);
    Color expected = Color::LIGHT;    
    ASSERT_EQ( expected, actual.get_color() );
}

TEST_F(BoardTest, test_size) 
{
    ASSERT_EQ( 64, board.size() );
}

TEST_F(BoardTest, test_iterator) 
{
    coord coords(0, 1);
    board.place_element(Disk(Color::LIGHT), coords);
    vector< Disk > expected(63, Disk(Color::NONE));
    expected.insert(expected.begin() + 8, Disk(Color::LIGHT));
    vector< Disk > actual;
    for (auto d : board) {
        actual.push_back(d);
    }
    ASSERT_EQ( expected, actual );
}
 
