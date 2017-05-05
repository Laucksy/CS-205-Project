#include "gtest/gtest.h"
#include "iostream"
#include "string.h"
#include "fstream"
#include "sstream"
#include "git.h"
using namespace std;

// The fixture for testing class Foo.
class GitTest : public ::testing::Test {
protected:
    GitTest() {
        // You can do set-up work for each test here.
    }

    virtual ~GitTest() {
    }

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

    // Objects declared here can be used by all tests in the test case for Foo.
};

//Test if testing works
TEST_F(GitTest, TESTTESTTEST) {
    if (true) {
        ASSERT_TRUE(true);
    }
}

TEST_F(GitTest, INITTEST) {
    Git::set_repo("ssh://spr2017_l1g3@139.147.9.185/home/spr2017_l1g3/unittest.git");
    Git::set_name("unittest");
    ASSERT_TRUE(Git::init());
}

TEST_F(GitTest, FINDFILEPATHTEST) {
    string filepath = Git::find_file_path("test.txt");
    //cout << filepath << endl;
    ASSERT_GT((int)filepath.length(), 8);
}

TEST_F(GitTest, FINDALLFILESTEST) {
    vector<string> files = Git::find_all_files("unittest");
    for(unsigned i = 0; i < files.size(); i++) {
        //cout << "FILE " << files.at(i) << endl;
    }
    ASSERT_EQ((int)files.size(), 1);
}

TEST_F(GitTest, STATUSTEST) {
    string status = Git::status();
    ASSERT_NE(status.find("nothing to commit"), string::npos);
}

TEST_F(GitTest, PUSHTEST) {
    ofstream file;
    file.open("unittest/test.txt", ios::app);
    file << "Adding another line." << endl;
    file.close();
    Git::add_file("unittest/test.txt");
    ASSERT_TRUE(Git::push());
}

TEST_F(GitTest, PULLTEST) {
    ASSERT_TRUE(Git::pull());
}

TEST_F(GitTest, RESETTEST) {
    ASSERT_TRUE(Git::reset());
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*int main(int argc, char *argv[])
{
    argc = 0;
    argv = nullptr;

    // cout << "Hello World!" << endl;
    //Git::init();
    //Git::add_file("test.txt");
    //Git::add_file("TestDB");
    //cout << Git::status() << endl;
    //system("clear");

    cout << Git::pull() << endl;
    cout << Git::push() << endl;
    //cout << Git::reset() << endl;
    //    Git* test;
    //cout << test->find_file_path("exampleImportant.pages") << endl;
    //    vector<string> res = test->find_all_files("/Users/swein/Desktop");

    //    for(unsigned long i = 0; i < res.size(); i++)
    //    {
    //        cout << res.at(i) << " working " <<  endl;
    //    }
    return 0;
}*/
