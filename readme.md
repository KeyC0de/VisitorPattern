<h1 align="center">
	<a href="https://github.com/KeyC0de/VisitorPattern">Visitor Pattern</a>
</h1>
<hr>


I have to agree that this designed pattern confused me for a longer time than I'd want to admit. But your confusion is now over! This cancer curing project will solve all mysteries for the Visitor pattern.

A decent example works wonders! The project provides an example that is implemented without a vistor and then with a visitor. Compare and contrast and imagine the possibilities of what you and a Visitor can accomplish if you work togethearoar!

I've used Windows 8.1 x86_64, Visual Studio 2017, C++17 to compile


*Definition*:
Represent an operation to be performed on elements of an object structure. Visitor lets you define a new operation without changing (recompiling) the classes of the elements on which it operates.

Did you understand anything yet? No, I didn't think so; keep on reading. I never understood those definitions either!

Visitor is a behavioral software design pattern is a good choice if you would want to perform similar kinds of operations on objects of different types that are grouped inside a structure.

**Design**

- Create a `Visitor` Class Hierarchy that defines a pure virtual `visit()` method. Each `visit` method accepts a single argument, a pointer or reference to an original `Element` derived class.
- Create `Visitor` sub-classes, one subclass for a single operation you want to perform on the `Element` objects.
- Add a single pure virtual `accept(Visitor& v)` method to the base class of the `Element` hierarchy. `accept` is defined to receive a single argument, a (non-const) pointer or reference to the abstract base class of the `Visitor` hierarchy. Preferably a reference such that you can also pass it temporaries.
- Each concrete derived class of `Element` implements the `accept` method by simply calling the `visit` method on the concrete derived of the `Visitor` hierarchy that was passed, passing its ``this` pointer as the sole argument.
- When a client needs an operation to be performed on a derived `Element` class he creates an instance of the `Visitor` object, calls the `accept` method on the `Element` object and passes the visitor. If the client wants a new operation to be performed on `Element` types he simply creates a new sublcass of `Visitor`.

I urge you to look at the example (make sure main\_visited.cpp and with\_visitor.cpp are excluded from compilation first by selecting them in Visual Studio -> right click -> properties -> General -> Excluded from Build: write "Yes" ).
Then compile check the code and question yourself. Then do the same with the other two .cpp files. Use the visitor. You can do this. I believe in you.

*Advanced case*: For a visitor with additional arguments in his visit method. For example when you'd want to supply more data to perform your desired operation on an `Element` then you'd best pass these arguments to your particular concrete `Visitor` object instead on its constructor.


### When to use it?

You should use visitors when the following conditions hold:

- you have a well-defined, known set of classes which will be visited.
- operations on said classes are not well-defined or known in advance. For example, if someone is consuming your API and you want to give consumers a way to add new ad-hoc functionality to objects. They're also a convenient way to extend sealed classes with ad-hoc functionaity.
- you perform operations of a class of objects and want to avoid run-time type testing. This is usually the case when you traverse a hierarchy of disparate objects having different properties.


### Notes

When the accept method is called in the program, its implementation is chosen based on both the dynamic type of the element and the dynamic type of the visitor. When the associated visit method is called, its implementation is chosen based on both the dynamic type of the visitor and the dynamic type of the element, as known from within the implementation of the accept method, which is the same as the dynamic type of the element. Plus if the visitor can't handle an argument of the given element's type, then the compiler will catch the error.

This is known as *double dispatch*. Double-dispatch is the ability to choose which version of a function to call based on the runtime type of the object performing the call as well as the runtime type of the arguments passed to the function call.

Without double dispatch we are left with the traditional algorithm for virtually dispatching objects in OOP languages. This algorithm is used by the compiler to figure out know which overriden and/or overloaded method will be chosen upon a virtual function call. You can apply that yourself. It's not that hard.

In ascending level of precedence:

1. We look at the static type of the object that makes the call (left of the `.` or `->`)
2. We look at the dynamic type of the object that makes the call
3. We look (only) at the static type of the arguments

With double dispatch we can also look at the dynamic/runtime type of the argument! YEEHAH!

Oh by the way, Visitor adheres to the open/closed principle. Keep that in mind.


# Contribute

Please submit any bugs you find through GitHub repository 'Issues' page with details describing how to replicate the problem. If you liked it or you learned something new give it a star, clone it, laugh at it, contribute to it whatever. I appreciate all of it. Enjoy.


# License

Distributed under the GNU GPL V3 License. See "GNU GPL license.txt" for more information.


# Contact

email: *nik.lazkey@gmail.com*</br>
website: *www.keyc0de.net*

