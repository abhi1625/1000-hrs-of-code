// #include<iostream> 
// using namespace std; 
// class Person { 
// public: 
//     Person(int x)  { cout << "Person::Person(int ) called" << endl;   } 
//     Person()     { cout << "Person::Person() called" << endl;   } 
// }; 
  
// class Faculty : virtual public Person { 
// public: 
//     Faculty(int x):Person(x)   { 
//        cout<<"Faculty::Faculty(int ) called"<< endl; 
//     } 
// }; 
  
// class Student : virtual public Person { 
// public: 
//     Student(int x):Person(x) { 
//         cout<<"Student::Student(int ) called"<< endl; 
//     } 
// }; 
  
// class TA : public Faculty, public Student  { 
// public: 
//     TA(int x):Faculty(x), Student(x), Person(x)   { 
//         cout<<"TA::TA(int ) called"<< endl; 
//     } 
// }; 
  
// int main()  { 
//     TA ta1(30); 
//     return 0;
// } 

// #include<iostream> 
// using namespace std; 
  
// class A 
// { 
//   int x; 
// public: 
//   void setX(int i) {x = i;}
//   void print() { cout << x; }
// }; 
  
// class B: virtual public A 
// { 
// public: 
//   B()  { setX(10); } 
// }; 
  
// class C:  virtual public A   
// { 
// public: 
//   C()  { setX(20); } 
// }; 
  
// class D: public B, public C { 
//     // { }
// }; 
  
// int main() 
// { 
//     D d;
//     d.print(); 
//     return 0; 
// } 

#include<iostream> 
using namespace std; 
  
class A 
{ 
  int x; 
public: 
  A(int i) { x = i; } 
  void print() { cout << x; } 
}; 
  
class B: virtual public A 
{ 
public: 
  B():A(10) {  } 
}; 
  
class C:  virtual public A  
{ 
public: 
  C():A(10) {  } 
}; 
  
class D: public B, public C { 
// public:
    // D() : B(),C() { }
}; 
  
int main() 
{ 
    D d; 
    d.print(); 
    return 0; 
} 
