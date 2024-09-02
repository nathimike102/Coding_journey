/*
Two Dimensional Arrays:
    Syntax:
        int[][] arr = new int[rows][columns];

    Example:
        import java.util.Scanner;
        import java.util.Arrays;
        public class demo3{
            public static void main(String[] args){
                Scanner sc = new Scanner(System.in); 
                int rows = sc.nextInt(); # 3
                int columns = sc.nextInt(); # 3
                int[][] matrix = new int[rows][columns];

                for(int i=0; i<rows; i++){
                    for(int j=0; j<columns; j++){
                        matrix[i][j] = sc.nextInt();      # 10 20 30 40 50 60 70 80 90
                    }
                }

                for(int i=0; i<arr.length; i++){
                    for(int j=0; j<arr[i].length; j++){
                        System.out.print(arr[i][j] + " ");  # 10 20 30 
                    }                                       # 40 50 60 
                    System.out.println();                   # 70 80 90
                }

                # Arrays.deepToString(matrix) will print the 2D array
                Arrays.deepToString(matrix); # [[10, 20, 30], [40, 50, 60], [70, 80, 90]]
            }
        }

    for-each loop on 2D arrays:
        public class demo3{
            public static void main(String[] args){
                String [][] seriesList = {{"professor","tokyo", "rio"}, {"harry potter", "ron", "hermoine"}, {"bhairava", "bujji", "yaskin"}};
                for(String[] eachSeries: seriesList){
                    for(String eachCharacter: eachSeries){
                        System.out.print(eachCharacter + "\t");
                    }
                    System.out.println();
                }
            }
        }
        

 */
public class demo3{
    public static void main(String[] args){
        String [][] seriesList = {{"professor","tokyo", "rio"}, {"harry potter", "ron", "hermoine"}, {"bhairava", "bujji", "yaskin"}};
        for(String[] eachSeries: seriesList){
            for(String eachCharacter: eachSeries){
                System.out.print(eachCharacter + "\t");
            }
            System.out.println();
        }
    }
}

/* 
import java.util.Arrays;
public class demo4 {
    // A function that takes integer array as argument
    static void change(int[] c){
        c[0] = 100;
    }
    public static void main(String[] args){
        //Cloning
        int[] a = {10, 20, 30};
        int[] b = a.clone(); //clone() gives a new copy of the array
        a[0] = 100; // will only apply on a
        System.out.println(Arrays.toString(a));
        System.out.println(Arrays.toString(b));

        // Sending Arrays to Methods is always call by reference
        int[] c = {10, 20, 30, 30, 40};
        System.out.println("Before changing "+ Arrays.toString(c));
        // Function call
        change(c); //Sending array c to the function
        System.out.println("After changing "+ Arrays.toString(c));
    }
}


import java.util.Arrays;
public class demo4{
    public static void main(String[] args){
        // Arrays of varying lengths, in multi-dimensional arrays
        // In multi-dimensional arrays in java, every dimension is optional when declaring except the first;

        int [][] arr = {{10, 20}, {30, 40, 50, 60}, {70, 80, 90}, {10, 20, 30, 40, 50, 60}};
        System.out.println(Arrays.deepToString(arr));
        for(int i=0;i<arr.length;i++){
            for(int j=0;j<arr[i].length;j++){
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }

        int[][] array = new int[3][];        int [][] arr = {{10, 20}, {30, 40, 50, 60}, {70, 80, 90}, {10, 20, 30, 40, 50, 60}};
        System.out.println(Arrays.deepToString(arr));
        for(int i=0;i<arr.length;i++){
            for(int j=0;j<arr[i].length;j++){
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
        array[0] = new int[10]; // 1st row contains 10 elements
        array[1] = new int[5]; // 2nd row contains 5 elements
        array[2] = new int[3]; // 3rd row contains 3 elements

        for(int i=0;i<10;i++){
            array[0][i] = i*i;
        }

        System.out.println(Arrays.deepToString(array));
    }
}
*/