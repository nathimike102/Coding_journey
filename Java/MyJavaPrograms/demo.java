import java.util.Scanner;
public class demo{
	public static void main(String[] args){
		// int a,b,c;
		//Object of Scanner class
		// Scanner read = new Scanner(System.in);
		// a = read.nextInt();
		// b = read.nextInt();
		// c = a + b;
		// System.out.println("The sum of "+a+" and "+b+" is : "+ c);
		// System.out.printf("The total of %d and %d is %d", a,b,c);
		// System.out.println((float)a /b);

		// java.lang packages will be imported in every java program.
		// java.lang.*; --> Math belongs to java.lang packages
		// Math.sqrt() --> return type Double
		// Math.pow() --> return type Double

		// Scanner read = new Scanner(System.in);
		// String name = read.nextLine(); //read a string with spaces
		// //next(), nextLine(), nextInt(), nextFloat() -> methods
		// System.out.println("You entered:" + name);

		Scanner read = new Scanner(System.in);
		//Reading a character
		char ch = read.next().charAt(0);
		// ASCII Character
		// a-z --> 97 - 122
		// A-Z --> 65 - 90
		// 0-9 --> 48 - 57
		// SPACE --> 32
		System.out.println(ch);
	}
}