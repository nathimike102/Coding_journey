/*Arrays in Java
1. Java arrays are objects
2. Arrays are indexed
3. Arrays are mutable
4. Memory for arrays should be allocated using new keyword
5. Index bound checks will take place

Syntax of declaring an array:
Java style:
    datatype[] array_name = new datatype[size];
    int[] arr = new int[5]; //an array of 5 integers
    String[] names = new String[10]; //an array of 10 strings
    boolean[] values = new boolean[7]; //an array of 7 bool values

    Initializing an array:
    int[] arr = {10,20,30,40,50};
    arr.length --> Number of elements in the array

C Style:
    datatype array_name[] = new datatype[size]

public class demo1{
    public static void main(String[] args){
        int[] arr = {10,20,30,40,50};
        int len = arr.length;
        System.out.println(len);
        System.out.println(arr[0] + arr[3]);
        //running a loop on an array
        for (int i=0; i < len; i++){
            System.out.println(arr[i] * arr[i]);
        }
    }
}

import java.util.Scanner;
public class demo1{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); //length of array
        int[] A = new int[n]; //declaring
        //int -->0, long -->0l, float -->0.0f, double --> 0.0, boolean --> false, char --> null character
        //Reference types (Strings, own class objects) are defaulted to null.

        //Reading array Elements
        for (int i=0;i<n;i++){
            A[i] = sc.nextInt();
        }
        int min_val = A[0];
        for (int i=1;i<n;i++){
            if(A[i] < min_val){
                min_val = A[i];
            } 
        }
        System.out.println("THe minimum value if :" + min_val);
        sc.close();
    }
}


//Task:
    // Read an array of strings and print the ASCII code point values of first characters of each string.
    // Access strings from reverse in the given array

import java.util.Scanner;
public class demo1{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] arr = new String[n];
        for(int i=0;i<n;i++){
            arr[i] = sc.next();
        }
        for(int i = n-1;i>=0;i--){
            System.out.println(arr[i].charAt(0) + " --> " + (int)arr[i].charAt(0));
        }
        sc.close();
    }
}

Syntax of for-each loop
for (datatype loop_variable_name: array_name) {
    do something;
}

*/
import java.util.Scanner;
public class demo1{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int[] arr = {10,20,30,40,50};
        for(int eachValue: arr){
            System.out.println(eachValue);
        }

        String[] stringArray = {"tokyo", "rio", "berling"};
        for(String eachString: stringArray){
            System.out.println(eachString);
        }

        char[] charArray = {'x', 'y', 'z'};
        for(char eachChar: charArray){
            System.out.println(eachChar);
        }

        boolean[] boolArray = {false, true, false, 1>3, 4<5, 3+17>=4*3};
        for(boolean eachBool: boolArray){
            System.out.println(eachBool);
        }
        sc.close();
    }
}