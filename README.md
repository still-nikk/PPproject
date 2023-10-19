# PPproject

## Project Overview
### This project is all about creating a Bookshop Inventory System using Object-Oriented Programming (OOP) concepts in C++. The system is designed to store information about books and movies available in a shop, their availability status, prices, and other relevant details. The primary goal of this system is to help shop owners efficiently manage their inventory and allow them to check the availability of specific books and movie tapes.

## OOP Concepts in Implementation
## Data Encapsulation
### Data encapsulation is achieved by defining classes for product, movie, book, and inventory. Each class encapsulates its data and methods, keeping data and operations together.
## Inheritance
### The movie and book classes inherit from the product class, allowing them to reuse common attributes and methods. Inheritance promotes code reusability and reduces redundancy.
## Polymorphism
### Polymorphism is used through the display method in the product, movie, and book classes. It allows the same method to behave differently based on the class of the object.
## Virtual Functions
### The display method in the product, movie, and book classes is a virtual function. It's overridden in the derived classes to provide specific implementations, ensuring that the correct version of the method is called at runtime.
## Classes and Objects
### Classes like product, movie, book, and inventory are created to represent real-world entities and their interactions. Objects of these classes are instantiated to manage the inventory and product details.

## Conclusion
### In conclusion, the Bookshop Inventory System is a practical application of OOP concepts in C++. It serves as an efficient tool for shop owners to manage their inventory and quickly check the availability of specific books and movie tapes. By encapsulating data, using inheritance, achieving polymorphism, and employing virtual functions, the project demonstrates the power of OOP in simplifying complex real-world problems.
### The code provides an interactive interface for shop owners to list books and movies, search for products by ID, and check their availability. The exact output of the code will vary depending on the user's input. Here's a simplified example of how it works:
### The user chooses to list books or movies.
### The system displays the available products with their details.
### The user can search for a specific product by entering its ID.
### The system checks the availability and provides product details.

### The code allows for efficient inventory management and provides a user-friendly way for shop owners to handle their bookshop operations.


