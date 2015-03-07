#include "gtest/gtest.h"

#include "disk.h"
#include "color.h"
#include <stdexcept>


class DiskTest : public ::testing::Test
{
protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    DiskTest() {
        // You can do set-up work for each test here.
    }

    virtual ~DiskTest() {
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
   Disk disk; 
};


TEST_F(DiskTest, TestColor) 
{
    ASSERT_EQ( Color::NONE, disk.get_color() );
    disk.set_color(Color::LIGHT);
    ASSERT_EQ( Color::LIGHT, disk.get_color() );
}

TEST_F(DiskTest, Test_flip) 
{
    ASSERT_THROW(disk.flip(), std::logic_error);
    disk.set_color(Color::LIGHT);
    disk.flip();
    ASSERT_EQ( Color::DARK, disk.get_color() );
    disk.flip();
    ASSERT_EQ( Color::LIGHT, disk.get_color() );
}

