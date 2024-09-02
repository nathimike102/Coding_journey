public class numberRep{
	public static void main(String[] args){
		// Changing string to integer
		String s="123";
		int num = Integer.parseInt(s); //Converts the string to base 10
		System.out.println(num * num);

		String binaryString="10111";
		int num2=Integer.parseInt(binaryString, 2); //converts the string to base 2 representation
		System.out.println(num2);

		String octalString="123";
		int num3=Integer.parseInt(octalString, 8); //Converts the string to base 8 representation
		System.out.println(num3);

		String hexaDecimalString="ABCD";
		int num4=Integer.parseInt(hexaDecimalString, 16); //Converts the string to base 16 representation
		System.out.println(num4);

		//Changing from integer to string
		int num5 = 123;
		String s1 = Integer.toString(num5); //Converts integer to string
		System.out.println(s1);
		System.out.println(Integer.toString(num5, 2)); //Binary of num in the form of string
		System.out.println(Integer.toString(num5, 8)); //Octal of num in the form of string
		System.out.println(Integer.toString(num5, 16));//HexaDecial of num in the form of string
	}
}