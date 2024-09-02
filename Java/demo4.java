/* STRINGS
    strings are objects in Java
    strings are immutable -> cannot change contents of the string after creation

    String to character Arrays
        char[] charArrayName = stringName.toCharArray();

    Character Array to String
        String stringName = new String(charArrayName);

    It's not possible to write a for-each loop on a string, but its possible to write on char array.

    equals() --> compare strings on lexicographical order
    equalIgnoreCase() --> compare strings ignoring character cases
    compareTo() --> returns -ve when s1 is less than s2, 0 when s1 and s2 are equals, +ve when s1 is greater than s2
    compareToIgnoreCases()

    import java.util.Scanner;
    public class demo4 {
        public static void main(String[] args){
            Scanner sc = new Scanner(System.in);
            String s1, s2;
            s1 = sc.next(); // Hello
            s2 = sc.next(); // hello
            System.out.println(s1.equals(s2)); # false
            System.out.println(s1.equalsIgnoreCase(s2)); # true
            System.out.println(s1.compareTo(s2)); # -32
            System.out.println(s1.compareToIgnoreCase(s2)); # 0
            sc.close();
        }
    }

    endsWith()
        checks if a string ends with a particular substring

    startsWith()
        checks if a string starts with a particular substring

    contains()
        checks if a string contains a particular substring

    import java.util.Scanner;
    public class demo4 {
        public static void main(String[] args){
            Scanner sc = new Scanner(System.in);
            String s1, s2, s3;
            s1 = sc.next();
            s2 = s1.toUpperCase();
            s3 = s1.toLowerCase();
            System.out.println(s1);
            System.out.println(s2);
            System.out.println(s3);
            System.out.println(s1.endsWith("llo")); // returns true is so, else false

            String email = "23mh1a05h9@acoe.edu.in";
            if(email.endsWith("acoe.edu.in")){
                System.out.println("Aditya College of Engineering");
            }
            if(email.startsWith("23mh1a05h9")){
                System.out.println("Aditya");
            }

            char ch = 'h';
            System.out.println(s1.contains(""+ch));

            sc.close();
        }
    }
*/
import java.util.Scanner;
public class demo4 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s1, s2, s3;
        s1 = sc.next();
        s2 = s1.toUpperCase();
        s3 = s1.toLowerCase();
        System.out.println(s1);
        System.out.println(s2);
        System.out.println(s3);
        System.out.println(s1.endsWith("llo")); // returns true is so, else false

        String email = "23mh1a05h9@acoe.edu.in";
        if(email.endsWith("acoe.edu.in")){
            System.out.println("Aditya College of Engineering");
        }
        if(email.startsWith("23mh1a05h9")){
            System.out.println("Aditya");
        }

        char ch = 'h';
        System.out.println(s1.contains(""+ch));

        sc.close();
    }
}