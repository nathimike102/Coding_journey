// import java.util.Scanner;
// class Example1{
// 	static void sayHello(){
// 		System.out.println("Hello");
// 	}
// 	public static void main(String[] args){
// 		sayHello();
// 		sayHello();
// 		sayHello();
// 	}
// }

// class Example1{
// 	void sayHello(){
// 		System.out.println("Hello");
// 	}
// 	public static void main(String[] args){
// 		Example1 e1 = new Example1(); //object
// 		e1.sayHello();
// 		e1.sayHello();
// 		e1.sayHello();
// 	}
// }

/* Object Oriented Programming
Class is like a structure in c, classes are blue print

Class members:
variables, methods, classes

static member access doesnt require an object of that class

non-static/instance member access requires an object creation.

static members			|			non-static/instance

class Cat {
	String name;
	int age;
	static String speciesType; // only need memory once since same for all cats.
}
Cat c1 = new Cat();

Anything static can be directly accessed using class name.

1. In a single .java file you can write as many classes as you want, but you can only write one public class.
2. Upon successful compilation, you will get .class files for each class you created.
3. Through the creation of objects can classes be accessed.

class ArithmeticOperations {
	static void add(int a, int b){
		System.out.println(a + b);
	}
	static void subtract(int a, int b){
		System.out.println(a - b);
	}
	static void multiply(int a, int b){
		System.out.println(a * b);
	}
	static void divide(int a, int b){
		System.out.println(a / b);
	}
}
class Example2 {
	public static void main(String[] args) {
		//Object of ArithmeticOperations class
		// ArithmeticOperations ao = new ArithmeticOperations();
		// ao.add(12, 31);
		// ao.subtract(24332, 23);
		// ao.multiply(23, 324);
		// ao.divide(543, 32);

		ArithmeticOperations.add(12, 31);
		ArithmeticOperations.subtract(24332, 23);
		ArithmeticOperations.multiply(23, 324);
		ArithmeticOperations.divide(543, 32);

		final int SEE = 10; // constant --> all uppercase character, constants values can never be changed.
	}
}
*/

class Example3 {
	public static void main(String[] args) {
		// initialization, condition, update

		int i = 0; // Initialization
		while (i <= 10) { //Condition
			System.out.println(i+" ");
			i++; // update
		}
		System.out.println();
		for(int j=0;j<=10;j++){
			System.out.println(j+" ");
		}
	}
}
