
#include <iostream>
#include <string>
#include <memory>

#include "TryMemoryManagement.hpp"

using namespace TryCPPLangg::TryMemoryManagement;
using namespace std;

namespace {
}

void TryCPPLangg::TryMemoryManagement::TryUniquePtr()
{
    //try unique_ptr 
    unique_ptr<int> uniqInt = make_unique<int>(10);
    unique_ptr<int> uniqInt3 = make_unique<int>(10);
    cout << "uniqInt = " << *uniqInt << " ref count: " << endl;

    uniqInt3 = move(uniqInt);
    //this line will throw exception
    // cout << "uniqInt = " << *uniqInt << " ref count: " << endl;
    {
        //out of scope
        unique_ptr<int> uniqInt2 = make_unique<int>(10);
        cout << "uniqInt2 = " << *uniqInt2 << " ref count: " << endl;
        uniqInt2 = move(uniqInt);
    }
}

void TryCPPLangg::TryMemoryManagement::TryUniquePtr2()
{
    class MyClass{
        public:
            MyClass(){
                cout << "In constructor" << endl;
            }
            ~MyClass(){
                cout << "In destructor" << endl;
            }
        
    };

    // create a unique ptr using make_unique function
    unique_ptr<MyClass> p1 = make_unique<MyClass> ();

    //try copying -- should give error
    // unique_ptr<MyClass> p2 = p1;

    //With move function, we can transfer ownership
    unique_ptr<MyClass> p3 = move(p1);

}

void TryCPPLangg::TryMemoryManagement::TrySharedPtr()
{
    shared_ptr<int> sharedInt1 = make_shared<int>(5);
    cout << " sharedInt1= " << *sharedInt1 << " refCount: " << sharedInt1.use_count() << endl;

    {
        shared_ptr<int> sharedInt2 = sharedInt1;
        cout << " sharedInt2= " << *sharedInt2 << " refCount: " << sharedInt2.use_count() << endl;
        *sharedInt2 = 10;
        cout << " sharedInt1= " << *sharedInt1 << " refCount: " << sharedInt1.use_count() << endl;
    }
   cout << " sharedInt1= " << *sharedInt1 << " refCount: " << sharedInt1.use_count() << endl;
    unique_ptr<int> uniqInt1 = make_unique<int>(8);
    cout << " uniqInt1= " << *uniqInt1 << " uniqInt1: " << uniqInt1 << endl;
    // uniqInt1 = move(sharedInt1);
    *uniqInt1 = *sharedInt1;
    cout << " uniqInt1= " << *uniqInt1 << " uniqInt1: " << uniqInt1 << endl;

}

void TryCPPLangg::TryMemoryManagement::TrySharedPtr2()
{
    struct Node
    {
        int data;
        shared_ptr<Node> next;
        shared_ptr<Node> prev;
    };
    
    shared_ptr<Node> Node1 = make_shared<Node>();
    shared_ptr<Node> Node2 = make_shared<Node>();

    cout << " Node1 refCount: " << Node1.use_count() << endl;
    Node1->next = Node2;

    cout << " Node1 refCount: " << Node1.use_count() << endl;
    cout << " Node1->next refCount: " << Node1->next.use_count() << endl;
    cout << " Node2 refCount: " << Node2.use_count() << endl;
    cout << " Node2->next refCount: " << Node2->next.use_count() << endl;
    {
        shared_ptr<Node> Node3 = make_shared<Node>();
        Node2->next = Node3;
        cout << "Inside anotjer scope\n";
        cout << " Node2->next: " << Node2->next << "\n";
        cout << " Node1 refCount: " << Node1.use_count() << endl;
        cout << " Node1->next refCount: " << Node1->next.use_count() << endl;
        cout << " Node2 refCount: " << Node2.use_count() << endl;
        cout << " Node2->next refCount: " << Node2->next.use_count() << endl;

    }
   
    cout << "Resetting Node2->next anotjer scope\n";
    cout << " Node2->next: " << Node2->next << "\n";
    cout << " Node1 refCount: " << Node1.use_count() << endl;
    cout << " Node1->next refCount: " << Node1->next.use_count() << endl;
    cout << " Node2 refCount: " << Node2.use_count() << endl;
    cout << " Node2->next refCount: " << Node2->next.use_count() << endl;
    cout << " Node2->prev refCount: " << Node2->prev.use_count() << endl;
}

void TryCPPLangg::TryMemoryManagement::TestForUniquePtr()
{
    // 
    // TryUniquePtr();
    // TrySharedPtr();
    TrySharedPtr2();

}

void TryCPPLangg::TryMemoryManagement::MainForMemoryManagement(){

    TryCPPLangg::TryMemoryManagement::TestForUniquePtr();

}