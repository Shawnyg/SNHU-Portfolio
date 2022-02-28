// Uncomment the next line to use precompiled headers
#include "pch.h"
// uncomment the next line if you do not use precompiled headers
//#include "gtest/gtest.h"
//
// the global test environment setup and tear down
// you should not need to change anything here
class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override
    {
        //  initialize random seed
        srand(time(nullptr));
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> collection;

    void SetUp() override
    { // create a new collection to be used in the test
        collection.reset(new std::vector<int>);
    }

    void TearDown() override
    { //  erase all elements in the collection, if any remain
        collection->clear();
        // free the pointer
        collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 99 count times to the collection
    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called
TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
    // is the collection created
    ASSERT_TRUE(collection);

    // if empty, the size must be 0
    ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer */
//TEST_F(CollectionTest, AlwaysFail)
//{
//    FAIL();
//}

// TODO: Create a test to verify adding a single value to an empty collection
TEST_F(CollectionTest, CanAddToEmptyVector)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);

    add_entries(1);

    // is the collection still empty?
    ASSERT_FALSE(collection->empty());

    // if not empty, what must the size be?
    ASSERT_EQ(collection->size(), 1);
}

// TODO: Create a test to verify adding five values to collection
TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
    // Get the starting size of the collection
    int startingSize = collection->size();

    // Add 5 entries to the collection
    add_entries(5);

    // Verify collection size increased by 5
    ASSERT_EQ(collection->size(), startingSize + 5);
}

// TODO: Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, EnsureMaxSizeIsGreaterOrEqualToSize)
{
    // is the size 0? is max size >= size?
    ASSERT_EQ(collection->size(), 0);
    ASSERT_TRUE(collection->max_size() >= collection->size());
    
    // Add 1 entry, is max size >= size ?
    add_entries(1);
    ASSERT_TRUE(collection->max_size() >= collection->size());

    // Add 4 more entries for a total of 5, is max size >= size?
    add_entries(4);
    ASSERT_TRUE(collection->max_size() >= collection->size());

    // Add 5 more entries for a total of 10, is max size >= size?
    add_entries(5);
    ASSERT_TRUE(collection->max_size() >= collection->size());
}


// TODO: Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, EnsureCapacityIsGreaterOrEqualToSize)
{
    // is the size 0? is max size >= size?
    ASSERT_EQ(collection->size(), 0);
    ASSERT_TRUE(collection->capacity() >= collection->size());

    // Add 1 entry, is max size >= size ?
    add_entries(1);
    ASSERT_TRUE(collection->capacity() >= collection->size());

    // Add 4 more entries for a total of 5, is max size >= size?
    add_entries(4);
    ASSERT_TRUE(collection->capacity() >= collection->size());

    // Add 5 more entries for a total of 10, is max size >= size?
    add_entries(5);
    ASSERT_TRUE(collection->capacity() >= collection->size());
}

// TODO: Create a test to verify resizing increases the collection
TEST_F(CollectionTest, EnsureResizingIncreasesSize)
{
    // Get the initial size of the collection
    int startingSize = collection->size();

    // Increase size by 1, verify the new size is greater than the initial size
    collection->resize(startingSize + 1);
    ASSERT_TRUE(collection->size() > startingSize);
}

// TODO: Create a test to verify resizing decreases the collection
TEST_F(CollectionTest, EnsureResizingDecreasesSize)
{
    // Add 1 entry so the size is >= 1
    add_entries(1);

    // Get the initial size of the collection before the resize
    int startingSize = collection->size();

    // Decrease size by 1, verify the new size is less than the initial size
    collection->resize(startingSize - 1);
    ASSERT_TRUE(collection->size() < startingSize);
}

// TODO: Create a test to verify resizing decreases the collection to zero
TEST_F(CollectionTest, EnsureResizingDecreasesSizeToZero)
{
    // Add 1 entry so the size is >= 1
    add_entries(1);

    // Get the initial size of the collection before the resize
    int startingSize = collection->size();

    // Decrease size by startingSize, verify the new size is equal to 0
    collection->resize(startingSize - 1);
    ASSERT_EQ(collection->size(), 0);
}

// TODO: Create a test to verify clear erases the collection
TEST_F(CollectionTest, EnsureClearErasesCollection)
{
    // Add 1 entry so the size is >= 1 so it doesn't start off as empty
    add_entries(1);

    // Clear the collection, verify the now cleared collection is empty
    collection->clear();
    ASSERT_TRUE(collection->empty());
}

// TODO: Create a test to verify erase(begin,end) erases the collection
TEST_F(CollectionTest, EnsureEraseErasesCollection)
{
    // Add 1 entry so the size is >= 1 so it doesn't start off as empty
    add_entries(1);

    // Clear the collection, verify the now cleared collection is empty
    collection->erase(collection->begin(), collection->end());
    ASSERT_TRUE(collection->empty());
}

// TODO: Create a test to verify reserve increases the capacity but not the size of the collection
TEST_F(CollectionTest, EnsureReserveIncreasesCapazityButNotSize)
{
    // Get the initial size and capacity
    int initialSize = collection->size();
    int initialCapacity = collection->capacity();

    // Reserve 5 spots
    collection->reserve(5);

    // Verify it increased capacity
    ASSERT_TRUE(collection->capacity() > initialCapacity);

    // Verify the size stayed the same
    ASSERT_EQ(initialSize, collection->size());
}

// TODO: Create a test to verify the std::out_of_range exception is thrown when calling at() with an index out of bounds
// NOTE: This is a negative test
TEST_F(CollectionTest, EnsureOutOfRangeIsThrownWithIndexOutOfBounds)
{
    // Clear the collection and verify it's empty
    collection->clear();
    ASSERT_TRUE(collection->empty());
    
    // Attempt to at() with an index out of bounds, verify it throws an exception
    ASSERT_THROW(collection->at(2), std::out_of_range); // It is fine that return value is ignored
    
}

// TODO: Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative

// Ensures shrink_to_fit reduces collection capacity to collection size
TEST_F(CollectionTest, EnsureShrinkToFitReducesCapacityToSize)
{
    // Resize to a number and get the capacity
    collection->resize(10);
    int initialCapacity = collection->capacity();

    // Resize to a smaller number, verify capacity hasn't changed
    collection->resize(5);
    ASSERT_EQ(initialCapacity, collection->capacity());

    // Call shrink verify the capacity is less than initial capacity AND equivalent to size
    collection->shrink_to_fit();
    int newCapacity = collection->capacity();

    ASSERT_TRUE(newCapacity < initialCapacity);
    ASSERT_EQ(collection->size(), newCapacity);
}

// Ensures a std::length_error is thrown if collection-reserve() is called with a negative number
TEST_F(CollectionTest, EnsureLengthErrorIsThrownIfReservingNegativeNumber)
{
    // Attempt to reserve a negative number
    ASSERT_THROW(collection->reserve(-1), std::length_error);
}