# C++ Pool - 42

This repository is a comprehensive collection of Object-Oriented Programming (OOP) exercises in C++, designed to span from foundational to advanced programming concepts. As you navigate through the modules, you'll engage with various aspects such as container usage, class and inheritance implementation, polymorphism, iterators, and algorithm development.

Below are my notes, filled with essential information, and the learnings I've gathered on my journey of exploring the vast and powerful paradigm of OOP. These notes are crafted with the hope of aiding newcomers in navigating the complexities of OOP with greater ease and understanding.

## Useful Links
- [C++ Reference (cppreference.com)](https://en.cppreference.com/)
- [C++ Library Reference (cplusplus.com)](https://cplusplus.com/reference/)
- Great book: C++ Primer

## An introduction to C++ and OOP

- Different than **procedural programming →** can lead to *spaghetti code*, harder to maintain and expand, lot of function parameters
- Combines related variables and functions into an **object**
    - variables = **properties**
    - functions = **methods**
      
---

## 4 Pillars

1. **Encapsulation**
2. **Abstraction**
3. **Inheritance**
4. **Polymorphism** 

---

### I - Encapsulation

- Less and sometimes no parameters to functions → easy to expand or delete features, allowed by parameters that are direct properties of the object
    - *“ The best functions are those with no parameters”*

### **II - Abstraction**

- No need to understand everything to use objects → we can hide some **properties** and **methods** in an object
- Leads to object with simpler interface
- Reduce the impact of change

### III - Inheritance

- Define a base object with common properties and methods and let other objects inherit this attributes
- Eliminate *redundant* code

### IV - **Polymorphism**

- Allow for inherited objects to define or add unique behavior to the base object
- Eliminate if/else forest and redundant anesthetic switch cases with simple code :
    
    ```jsx
    object.execute() // will work for every object
    ```
    

---

### Benefits

**Encapsulation** → by grouping properties and methods in one object we reduce complexity and increase re-usability

**Abstraction →** also reduce complexity and reduce impact of changes in the code 

**Inheritance** → reduce redundant code

**Polymorphism** → prettier straight-forward code

---

### Implementations

- **Separation of Interface and Implementation**:
    - Keeps the class definition (header file) clean and focused on the interface, making it easier for other programmers to understand the class's API without getting bogged down in implementation details.
- **Reduced Compilation Dependency**:
    - When a function is defined outside the class definition, any change to the function's implementation does not require recompiling all the source files that include the class's header file.
    - This can significantly reduce build times in large projects.

---

### Encapsulation

Encapsulation is a fundamental concept in object-oriented programming (OOP). It involves bundling the **data** (variables) and the **methods** (**functions**) that operate on the data into a single unit, which in most OOP languages, is the class. Here are key aspects of encapsulation:

**Data Hiding**: Encapsulation allows restricting direct access to some of an object's components, which is a means of preventing accidental interference and misuse of the methods and data. This is usually achieved using access specifiers like `private`, `protected`, and `public` in C++.

**Controlled Access**: Through encapsulation, an object can control its internal state and can change it through specific methods known as *getters* and *setters*. This controlled access safeguards against unauthorized access and modification of data.

**Modularity**: By encapsulating related properties and behaviors within classes, a program's code becomes modular, making it easier to understand, maintain, and debug.

**Simplifying Complexity**: By hiding the internal workings of objects and exposing only what is necessary, encapsulation simplifies the complexity of software development. Users of a class don't need to understand its internal complexities to use it.

**Abstraction**: Encapsulation aids in abstraction by allowing the creation of a more abstract representation of a model. It emphasizes the behavior of an object, not how the behavior is implemented.

This approach leads to code that is more secure and robust, as well as easier to understand and maintain.

- `this` is a pointer that refers to the current instance (object) of a class. It is used within class member functions to access the members (variables and functions) of the **current instance**

---

### Canonical form

```cpp
class Span {
	private:
		;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &tocopy);
		~Span();

		Span& operator=(const Span &rhs);
};
```

**Declaration**

```cpp
Span::Span() : _N(1) {}

Span::Span(unsigned int N) : _N(N) {}

// Span::Span(const Span &tocopy) : _N(tocopy._N), _v(tocopy._v) {}
// equals to (for auto-memory management or not heap objects):
// but less efficient: additionnal steps!!
Span::Span(const Span &tocopy) {
	*this = tocopy;
}

Span::~Span() {}

Span& Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		this->_N = rhs._N;
		this->_v = rhs._v;
	}
	return (*this);
}

```

1. **Default Constructor**
    
    Assignation syntax
    
    ```cpp
    Animal::Animal(void) : _type("Animal")
    ```
    
2. **Destructor**: To deal with resource de-allocation.
3. **Copy Constructor**: To handle copying of resources correctly.
4. **Copy Assignment Operator**: To handle assignment of resources correctly.
    
    ```cpp
    Animal &Animal::operator=(Animal const &copy) {
    	if (this != &copy)
    		*this = copy;
    	return (*this);
    }
    ```
    

**Operator surcharge**

```cpp
std::ostream&   operator<<(std::ostream& *out*, const Class& obj);
bool operator>(const Fixed &rhs) const;
bool operator<(const Fixed &rhs)const;
bool operator>=(const Fixed &rhs) const;
bool operator<=(const Fixed &rhs) const;
bool operator==(const Fixed &rhs) const;
bool operator!=(const Fixed &rhs) const;
Fixed operator+(Fixed const &rhs) const;
Fixed operator-(Fixed const &rhs) const;
Fixed operator*(Fixed const &rhs) const;
Fixed operator/(Fixed const &rhs) const;
// prefix increment
T& operator++(int); // int = convention
T& operator--(int);
// postfix increment
T operator++();
T operator--();

// definition example
bool Fixed::operator>(const Fixed &rhs) const {
	return ((this->_fixPointValue > rhs.getRawBits()) ? true : false);
}
```

---

### Classes (example)

```cpp
#pragma once

#include ...

class Bureaucrat {
	private:
		const std::string	_name;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, unsigned int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat(void);
		Bureaucrat&			operator=(Bureaucrat const &rhs);
		const std::string	getName(void) const;
		void				upGrade(void);

		class	GradeTooHighException {
			public:
				virtual void what() const throw() {
					std::cerr << "Grade too high" << std::endl;
				}
		};
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat);
```

---

### Pointer vs Reference

both pointers and references are used to work with memory addresses and access objects indirectly

- Pointers → *
    - need to use the address-of operator (`&`) to obtain the address of an object that you want to point to

```cpp
int* ptr; // Declaration of a pointer
int x = 10;
ptr = &x; // Assign the address of 'x' to the pointer
```

- References → &
    - don't need to explicitly obtain an address because a reference is an alias to an existing object

```cpp
int y = 20;
int& ref = y; // Declaration and initialization of a reference
```

---

### Pointers vs. References in Function Parameters

Pointers are typically used for functions that need to modify the object they point to or work with arrays.

References are often used for function parameters when you want to pass an object by reference to avoid making a copy or when you want to enforce that the parameter cannot be null.

```cpp
void modifyValue(int* ptr) {
    (*ptr)++; // Modify the value pointed to by 'ptr'
}

void modifyValue(int& ref) {
    ref++; // Modify the value referred to by 'ref'
}
```

**Examples**

```cpp
std::string	str = "HI THIS IS BRAIN";
std::string	*stringPTR = &str;
std::string	&stringREF = str;

std::cout << &str << std::endl;
std::cout << stringPTR << std::endl;
std::cout << &stringREF << std::endl;
std::cout << str << std::endl;
std::cout << *stringPTR << std::endl;
std::cout << stringREF << std::endl;
```

```cpp
0x7fffcccf1618
0x7fffcccf1618
0x7fffcccf1618
HI THIS IS BRAIN
HI THIS IS BRAIN
HI THIS IS BRAIN
```

---

### Returning *this (reference convention)

*why do i need to return the *this and not this ?*

Returning `*this` instead of `this` in the assignment operator is an important convention in C++ that relates to the types involved and how they are used in expressions.

- `this` is a pointer to the current object. It's of type `Span*` in your case (a pointer to `Span`).
- `this` is a reference to the current object itself. It's of type `Span&` (a reference to `Span`).

The reason you return `*this` (a reference) rather than `this` (a pointer) is to enable the natural and expected usage of assignment in C++ expressions. When you write code like `a = b = c;`, you're relying on the assignment operator to return a reference to the left-hand object (`a` and `b` in this case), not a pointer. This allows the assignment to chain naturally, as each assignment operation returns a reference to the object it just assigned to, which then becomes the left-hand operand of the next assignment.

For example, consider the following code:

```cpp
Span a, b, c;
a = b = c;
```

Here's how it works:

1. `b = c` calls `b.operator=(c)`. This method modifies `b` to be a copy of `c` and returns a reference to  (`this`).
2. `a = (b = c)` is now effectively `a = b` (because `b = c` returned a reference to `b`). So, `a.operator=(b)` is called, which modifies `a` to be a copy of .

If the assignment operator returned a pointer (`this`), the code `a = b = c;` would not work as expected, because you can't assign a pointer to a `Span` object directly to another  object. The types wouldn't match up, and the natural chaining of assignments would be broken.

So, by returning `*this`, you're adhering to C++ conventions and enabling your class to be used in a way that C++ programmers would expect.

---

### Null-ability

Pointers can be null or uninitialized, which means they may not point to a valid object. You must check for null pointers before de-referencing them to avoid undefined behavior.

References must always be initialized when declared and cannot be null. They always refer to an existing object.

---

### Reassignment

**Pointers** **can** be reassigned to point to different objects or null pointers.

**References** **cannot** be reassigned after initialization. They remain bound to the object they were initialized with.

Syntax for Accessing Values:

Pointers use the de-reference operator (`*`) to access the value they point to.

References are used directly, without any additional syntax, to access the value they refer to.

```cpp
int value = *ptr; // Accessing the value through a pointer
int value = ref; // Accessing the value through a reference
```

---

### In-class accessibility

- `private`: Accessible only within the class it's defined. Not child!
- `public`: Accessible from anywhere the object is visible.
- `protected`: Middle ground, adds the ability for child classes to access.
    - `protected` makes class members accessible within the class itself and by derived (child) classes but not by other parts
        - Put `protected` before class members (variables, functions) in a class definition
        - **Access Level**:
            - **Within the Class**: Same as `private`, can use directly.
            - **In Derived Classes**: Can access `protected` members of the base class.
            - **Outside the Class**: Can't access, similar to `private`.
            
            Useful for *inheritance*. Allows child classes to use and modify these members, which are hidden from the rest of the program
            

---

### `const`

1. **`const` Member Functions** (at end):
    - Syntax: `ReturnType FunctionName() const;`
    - These functions **do not modify any member variables of the class** (except those marked as `mutable`).
    - Usage: Allows the function to be called on `const` instances of the class. Ensures the function won't change the object's state.
2. **`const` Member Variables**:
    - Syntax: `const DataType VariableName;`
    - These variables must be initialized when the object is created (at construction) and cannot be changed afterward.
    - Usage: Useful for defining immutable properties of the class.
3. **`const` in Constructor Parameters**:
    - Syntax: `ClassName(const DataType& ParameterName);`
    - Used to prevent modification of parameters passed by reference or pointer.
    - Usage: Protects input parameters from being accidentally modified inside the constructor.
4. **`const` Return Types**:
    - Syntax: `const ReturnType FunctionName();`
    - Prevents the caller from modifying the returned value, useful when returning references or pointers.
    - Usage: Ensures the integrity of the returned data, especially when returning references to internal class members.

---

### `static`

- **Static Member Variables**:
    - Syntax: `static DataType VariableName;`
    - Belong to the class, not any particular object instance.
    - Shared by all instances of the class.
    - Initialized once and retain their value between function calls.
    - Usage: Useful for values that should be shared across all instances, like counters or global settings within the class context.
- **Static Member Functions**:
    - Syntax: `static ReturnType FunctionName(Parameters);`
    - Also belong to the class rather than any object instance.
    - Can only access static members and other static functions, not non-static members.
    - Usage: Often used as utility functions that relate to the class but don't need to interact with instance-specific data.
    
    When you define a static member function outside the class in C++, you don't use the `static` keyword in the function definition. The `static` keyword is only used in the class declaration to specify that the member function is static. Here's why:
    
    1. **Class Declaration**: Inside the class declaration, the `static` keyword is necessary to tell the compiler that the function is a static member of the class. This affects how the function is called (i.e., **it can be called without an instance of the class**) and how it behaves (i.e., **it does not have access to instance-specific data**).
    2. **Function Definition**: When you define the function outside the class, you don't need to repeat the `static` keyword. At this point, the compiler already knows the function is static from the declaration in the class.
- **Static Local Variables in Functions**:
    - Syntax: `static DataType VariableName;` within a function.
    - Declared **within a function**.
    - Retain their value between function calls (preserve state).
    - Initialized only once, the first time the function is called.
    - Usage: Commonly used for implementing functions that need to remember a state or value between calls, such as in the case of a function that counts how many times it has been called.

---

### **`mutable`**

`mutable int mutableVar;`

- Normally, all member variables of a `const` object are read-only; they cannot be changed once the object is created.
- However, if a member variable is declared with the `mutable` keyword, it can be modified even if it belongs to a `const` object.

---

### **`virtual`**

- Indicates that a member function can be overridden in a derived class.
- Essential for achieving polymorphism in C++.
- When you declare a function as `virtual` in a base class, you are telling the C++ compiler that you want to allow derived classes to provide their **own specific implementation of that function**.

**virtual destructor:**

Here's why a virtual destructor is important in a class hierarchy:

- When you delete a derived class object through a base class pointer without a virtual destructor in the base class, the destructor of the derived class is not called. This can lead to resource leaks if the derived class is managing resources (like dynamic memory).
- A virtual destructor ensures that the correct destructor is called for derived class objects, even when they are referred to by a base class pointer or reference.

`virtual ~Animal(void);` ensures that when an object of a derived class (that inherits from `Animal`) is destroyed through a pointer or reference to `Animal`, both the destructor of the derived class and that of `Animal` are called in the correct order, thereby releasing all resources correctly.

---

### **`explicit`**

- Applied to constructors to prevent automatic type conversion.

---

### Pure virtual function

`virtual void show() = 0;  // Pure virtual function`

1. **Abstract Class**: A class with at least one pure virtual function becomes an abstract class. **You cannot instantiate an abstract class directly**.
2. **Interface Requirement**: The pure virtual function acts as a contract. Derived classes **must provide their own implementation of this function**. If they don't, they too become abstract classes.
3. **Polymorphism**: This is used to achieve polymorphism. A base class pointer or reference can be used to refer to objects of derived classes. When you call a pure virtual function through a base class pointer or reference, the version defined in the derived class is invoked.

---

### Type casting

**Implicit cast**: all the data types of the variables are upgraded to the data type of the variable with largest data type. → can lose information, signs (signed/unsigned), overflow (long long → float)

**Cast operators**

- **`static_cast`** : **compile-time cast**, allows casting from any pointer type to void pointer and vice versa, can call Class operators, not secure (does not verify validity of the cast)
    
    → Converting between related types, such as between base and derived classes or between numeric types
    
    - `static_cast<*dest_type*>(source);`
- `**dynamic_cast`** : mainly used for safe down-casting **at run time**, must be one virtual function in the base class or *“Source type is not polymorphic”* compiler error
    
    safest for downcasting in class hierarchies and throws a `bad_cast` exception (or returns a null pointer in case of pointers) if the cast is not valid.
    
    - `dynamic_cast<new_type>(source)`
    
    • **Downcasting:** Casting a base class pointer (or reference) to a derived class pointer (or reference) is known as downcasting
    
    • **Upcasting:** Casting a derived class pointer (or reference) to a base class pointer (or reference) is known as upcasting.
    
- `**const_cast`** : un-const an object
    - `const_cast<int>(source);`
    
    ```cpp
    const int num = 10;
    int* modifiable = const_cast<int*>(&num);
    // *modifiable = 20; // Undefined behavior if you modify the original const value
    ```
    
- `**reinterpret_cast`** : convert any pointer type to any other pointer type, even if the types are unrelated, treats the sequence of bits (the object representation) of one thing as if it were a sequence of bits of another type, without checking the safety or validity of such a conversion. **Compile time**.
    
    → **low-level reinterpreting of bit patterns**
    

---

### `try / throw / catch`

- **`try`**: This block tests a set of statements for errors.
- **`throw`**: When an error is detected, the `throw` statement is used to send an exception.
- **`catch`**: This block catches and handles exceptions thrown by the `try` block.

Inside class definition of what the what.e() function will call:

```cpp
class	AnException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error [...]";
				}
		};
```

Inside a function:

```cpp
if (condition) {
		throw Class::AnException();
```

Handling the exception:

```cpp
try {
        // do stuff
}
catch (const std::exception &e) {
			// if stuff fails
    std::cerr << e.what() << std::endl;
}
```

**Components**

`virtual const char* what() const throw()`

**`virtual`:**  indicates that the method can be overridden in a derived class. In the context of an exception class, `virtual` ensures that if a derived class provides its own implementation of `what()`,
 that implementation will be used instead of the base class version when
 the method is called through a reference or pointer to the base class

**`const char*`:** return type of the method. `const char*` means the function returns a pointer to a constant character array (C-style string). The content of this string typically describes the error that caused the exception. This return type is chosen for compatibility reasons, as C++ exceptions need to be usable even in contexts where C++ standard library types like `std::string` might not be available or desirable

**`what()`:** name of the method. `what()` is a standard method in C++ exceptions, used to provide a human-readable description of the exception.

`**const` :** method does not modify state of the object

**`throw()`:** exception specification. `throw()` indicates that the function is guaranteed not to throw any exceptions. In later versions of C++, this notation is deprecated in favor of `noexcept`, which serves a similar purpose. For the `what()` method, indicating that it will not throw any exceptions is important because this method is often called in a catch block, and throwing another exception in such a block would be problematic.

- Using the library example
    
    ```cpp
    #include <stdexcept>
    #include <string>
    
    class MyException : public std::runtime_error {
    public:
        MyException(const std::string& message)
            : std::runtime_error(message) {
        }
    };
    ```
    

---

### Templates

Allows to define generic classes or functions

Warning : *one typename by type!*

**Function templates**

Write a function that can operate on different data types

```cpp
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
```

**Class templates**

Define generic classes. For example, a `Box` class that can store any type of item.

```cpp
template <typename T>
class Box {
private:
    T content;
public:
    void setContent(T newContent) {
        content = newContent;
    }
    T getContent() {
        return content;
    }
};
```

**Template Specialization**

define a specific implementation for a particular data type. For example, a specialized version of `Box` for `int`

```cpp
template <>
class Box<int> {
// Special implementation for int
};
```

**Multiple typename** *(for multiple types and no cast when calling)*

```cpp
// apply function pointer to each index of an array
template <typename T, typename U, typename V>
void	iter(T *add, U size, V fp) {
	for (size_t	i = 0; i < size; i++)
		fp(add[i]);
}
```

---

### Containers

The Containers library is a generic collection of class templates and algorithms that allow programmers to easily implement common data structures like queues, lists and stacks

There are two(until C++11)three(since C++11) classes of containers:

- sequence containers
- associative containers
- unordered associative containers (C++11)

The container manages the storage space that is allocated for its elements and **provides member functions to access them**, **either directly or through iterators** (objects with properties similar to pointers).

Most containers have at least several member functions in common, and share functionalities. Which container is the best for the particular application depends not only on the offered functionality, but also on its efficiency for different workloads.

### Sequence Containers

Sequence containers implement data structures which can be accessed sequentially.

| Container | Description |
| --- | --- |
| [array (cppreference.com)](https://en.cppreference.com/w/cpp/container/array) | static contiguous array (class template) |
| [vector (cppreference.com)](https://en.cppreference.com/w/cpp/container/vector) | dynamic contiguous array (class template) |
| [deque (cppreference.com)](https://en.cppreference.com/w/cpp/container/deque) | double-ended queue (class template) |
| [forward_list (cppreference.com)](https://en.cppreference.com/w/cpp/container/forward_list) | singly-linked list (class template) |
| [list (cppreference.com)](https://en.cppreference.com/w/cpp/container/list) | doubly-linked list (class template) |

### Associative Containers

Associative containers implement sorted data structures that can be quickly searched (*O(log n)* complexity).

| Container | Description |
| --- | --- |
| [set (cppreference.com)](https://en.cppreference.com/w/cpp/container/set) | collection of unique keys, sorted by keys (class template) |
| [map (cppreference.com)](https://en.cppreference.com/w/cpp/container/map) | collection of key-value pairs, sorted by keys, keys are unique (class template) |
| [multiset (cppreference.com)](https://en.cppreference.com/w/cpp/container/multiset) | collection of keys, sorted by keys (class template) |
| [multimap (cppreference.com)](https://en.cppreference.com/w/cpp/container/multimap) | collection of key-value pairs, sorted by keys (class template) |

--- 

### Iterators

standard containers provide various types of iterators to enable different ways of *traversing* the container

**`iterator`**: This is a bidirectional iterator for a container, allowing both forward and backward traversal

**`const_iterator`**: Similar to `iterator` but provides read-only access to the container's elements

**`reverse_iterator`**: This is an iterator that moves backward through the container (from the end to the beginning). 
**`const_reverse_iterator`**

**5 types of iterators** *(defined in Standard Template Library)*

- **Input Iterators**:
    - These iterators can read from the pointed-to element.
    - They are the least powerful but most flexible iterators.
    - They support operations like increment (moving to the next element) and dereferencing (accessing the element).
    - Commonly used in single-pass algorithms and for reading from streams.
- **Output Iterators**:
    - These are used for writing to the pointed-to element.
    - Like input iterators, they support increment and dereferencing, but for writing instead of reading.
    - Commonly used for single-pass write algorithms and writing to streams.
- **Forward Iterators**:
    - They have all the capabilities of input iterators.
    - They can read and write (if they are not constant iterators) and move forward (like input and output iterators), but they can also go through the sequence multiple times (unlike input and output iterators).
    - Suitable for multi-pass algorithms on a sequence of elements.
- **Bidirectional Iterators**:
    - These iterators extend forward iterators with the ability to move backward (decrement).
    - They can be used in algorithms that need to iterate forwards and backwards through a sequence.
    - Common in containers like `std::list`, `std::set`, `std::map`, etc.
- **Random Access Iterators**:
    - The most powerful iterators, which combine the capabilities of bidirectional iterators with the ability to directly access any element in a sequence (like an array).
    - They support a wide range of operations, including addition, subtraction, and comparison of iterators.
    - Used with containers like `std::vector` and `std::deque`.
- **Examples**
    
    ### 1. Input Iterator
    
    Used for reading elements in a forward direction. Commonly used with input streams.
    
    ```cpp
    #include <iostream>#include <iterator>#include <vector>int main() {
        std::vector<int> vec = {1, 2, 3, 4, 5};
        std::istream_iterator<int> start(std::cin), end; // Input iterator from standard input
        std::copy(start, end, std::back_inserter(vec)); // Reads until end-of-file or invalid input
    
        for (int n : vec) {
            std::cout << n << " ";
        }
    }
    ```
    
    ### 2. Output Iterator
    
    Used for writing elements. Common with output streams.
    
    ```cpp
    #include <iostream>#include <iterator>#include <vector>int main() {
        std::vector<int> vec = {1, 2, 3, 4, 5};
        std::ostream_iterator<int> out_it(std::cout, ", "); // Output iterator to standard output
        std::copy(vec.begin(), vec.end(), out_it); // Writes elements of vec to standard output
    }
    ```
    
    ### 3. Forward Iterator
    
    Can read/write and move forward, suitable for multiple passes.
    
    ```cpp
    #include <forward_list>#include <iostream>int main() {
        std::forward_list<int> flist = {1, 2, 3, 4, 5};
        for (std::forward_list<int>::iterator it = flist.begin(); it != flist.end(); ++it) {
            std::cout << *it << " "; // Reading using forward iterator
        }
    }
    ```
    
    ### 4. Bidirectional Iterator
    
    Can move forwards and backwards. Common in `std::list`, `std::set`, etc.
    
    ```cpp
    #include <iostream>#include <list>int main() {
        std::list<int> mylist = {1, 2, 3, 4, 5};
        for (std::list<int>::reverse_iterator rit = mylist.rbegin(); rit != mylist.rend(); ++rit) {
            std::cout << *rit << " "; // Reverse iteration using bidirectional iterator
        }
    }
    ```
    
    ### 5. Random Access Iterator
    
    Supports direct element access, addition, subtraction, and comparison.
    
    ```cpp
    #include <iostream>#include <vector>int main() {
        std::vector<int> vec = {1, 2, 3, 4, 5};
        std::vector<int>::iterator it = vec.begin() + 2; // Direct access
        std::cout << "Third element: " << *it << std::endl;
    }
    ```
    

---

### Files interface

```cpp
#include <iostream>
#include <fstream>

std::ifstream	in;
std::ofstream	out;
```

---

### Function pointers

```cpp
// typedef
typedef void (Harl::*t_func) (void);

// point to the functions
t_func	fptr[] = {&Harl::debug, &Harl::info};

// call the function
this->*fptr[i])()
```

---

### Switch case

1. **`switch` Expression**: The `switch` statement evaluates an expression, typically a variable.
2. **`case` Labels**: These are specific values that the expression is compared against. If the expression matches a `case` value, the code following that `case` label is executed.
3. **`break` Keyword**: Typically, a `break` statement is used at the end of each `case` block. It exits the `switch` statement, preventing the execution from falling through to the next `case`.
4. **`default` Label**: This is an optional label that executes if none of the `case` labels match. It's like an "else" in an "if-else" ladder.

```cpp
void	Harl::complain(std::string level) {
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;

	while (i < 4 && levels[i].compare(level))
		i++;
	switch (i) {
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			std::cout << "A very human thing to make problems out of anything." << std::endl;
	}
}
```

- Omitting `break` can be useful in certain situations where you want multiple `case` labels to execute the same code block, but this should be used carefully to avoid errors.
- The `case` labels must be constant expressions, typically literals or `const` variables.

---

### Ternary

`condition ? expression1 : expression2;`

---

### Heap allocation

- `new` operator is used for dynamic memory allocation on the heap
- `delete` operator to free the heap when `new` was used
- `delete []` free multiples allocations

---

### Random

```cpp
#include <cstdlib>
#include <ctime>

srand(time(NULL)); // initialise random number generator
int i = rand(); // store pseudo-random number
// rand() % 100 would generate a random number between 0 and 99
```

`(srand(time(NULL))` → NULL is used as an argument to the time function. 
The time function, when passed NULL, returns the current calendar time (the number of seconds since the Unix epoch, January 1, 1970). 
The NULL in this case indicates that you don't need to store the result in a time structure, but are only interested in the numeric value it returns.

---

### Libs & co

- `std::string` string class, offers a dynamic and flexible way to handle strings without worrying about memory management
- `std::flush` explicitly flush or clear the output buffer, the output buffer is a temporary storage area where data is collected before being sent to the actual output device, such as the console or a file. When you write data to an output stream using `<<` the data is typically not immediately sent to the output device but buffered for performance reasons. This buffering can  improve efficiency by reducing the number of write operations to the output device. However, there are times when you may want to ensure that the data in the buffer is immediately written to the output device, and that's where `std::flush` comes in
- `std::cin.good()` is used to check the state of the input stream `std::cin` to determine if the input stream is in a good (valid) state for further input operations
