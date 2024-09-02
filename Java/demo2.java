/*
Arrays:
    package --> util
    
    Methods:
    toString():
        parameters - an array
        return type - string
        Description - Return a string which array elements are separated using commas and enclosed within square brackets
        Syntax: Arrays.toString(array_name);

        ###
        import java.util.Arrays;
        public class demo2{
            public static void main(String[] args){
                int[] arr = {10,20,30};
                String[] str = {"abc", "def", "ghi"};
                String res = Arrays.toString(str);
                System.out.println(res);
                System.out.println(Arrays.toString(arr));
            }
        }

    fill():
        parameters - an array, value
        return type - void
        Description - Fill the array with the given value

        Syntax: Arrays.fill(array_name, value);
        ###
        import java.util.Arrays;
        public class demo2{
            public static void main(String[] args){
                int[] arr = new int[5];
                String[] str = new String[10];
                Arrays.fill(arr, -1);
                Arrays.fill(str, "Mike");
                System.out.println(Arrays.toString(arr));
                System.out.println(Arrays.toString(str));
            }
        }

        Syntax: Arrays.fill(array_name, startIndex, endIndex, Value) # startIndex inclusive, endIndex exclusive
        ###
        import java.util.Arrays;
        public class demo2{
            public static void main(String[] args){
                String[] str = new String[10];
                Arrays.fill(str, 1, 4, "Mike");
                Arrays.fill(str, 6, 9, "ekiM");
                System.out.println(Arrays.toString(str)); # [null, Mike, Mike, Mike, null, null, ekiM, ekiM, ekiM, null]
            }
        }

    sort();
        parameters - an array
        return type - void
        Description - Performs a sort in ascending order of the values in-place. To perform sorting internally this method uses dual-pivot quick sort.
        Syntax - Arrays.sort(array_name);
            
        ###
        import java.util.Arrays;
        public class demo2{
            public static void main(String[] args){
                int[] arr = {20,50,10,30,40};
                Arrays.sort(arr);
                System.out.println(Arrays.toString(arr)); # [10, 20, 30, 40, 50]
            }
        }
    
    equals():
        parameters - two arrays
        return type - boolean
        Description - Compares two arrays lexicographically and returns true if first array and second array are same else false
        Syntax: Arrays.equals(array1, array2);

        ###
        import java.util.Arrays;
        public class demo2{
            public static void main(String[] args){
                int[] arr = {20,50,10,30,40};
                int[] arr2 = {20,50,10,30,40};
                System.out.println(Arrays.equals(arr, arr2)); # true
            }
        }
    
    compare():
        parameters - two arrays
        return type - int
        Description - Compares two arrays lexicographically and returns -ve if first array < second array, +ve if first array > second array and 0 if both arrays are equal
        Syntax: Arrays.compare(array1, array2);

        ###
        import java.util.Arrays;
        public class demo2{
            public static void main(String[] args){
                int[] arr = {20,50,20,30,40};
                int[] arr2 = {20,50,10,30,40};
                System.out.println(Arrays.compare(arr, arr2)); # -1
            }
        }

        ###
        import java.util.Arrays;
        public class demo2{
            public static void main(String[] args){
                char[] arr = {'a', 'd'};
                char[] arr2 = {'a', 'a', 'x'};
                System.out.println(Arrays.compare(arr, arr2)); # 3
            }
        }

    mismatch():
        parameters - two arrays
        return type - int
        Description - Compares two arrays lexicographically and returns the index of first mismatching element or -1 if both arrays are same
        Syntax: Arrays.mismatch(array1, array2);

        ###
        import java.util.Arrays;
        public class demo2{
            public static void main(String[] args){
                char[] arr = {'a', 'd', 'e'};
                char[] arr2 = {'a', 'a', 'a'};
                System.out.println(Arrays.compare(arr, arr2));
                System.out.println(Arrays.mismatch(arr,arr2));
            }
        }

    copyof():

    binarySearch():
        parameters - an array, value
        return type - int
        Description - Returns the index of the first occurrence of the given value or -1 if not found
        Syntax: Arrays.binarySearch(arr, value);

 */
 import java.util.Arrays;
public class demo2{
    public static void main(String[] args){
        char[] arr = {'a', 'd', 'e'};
        char[] arr2 = {'a', 'a', 'a'};
        System.out.println(Arrays.compare(arr, arr2));
        System.out.println(Arrays.mismatch(arr,arr2));
    }
}