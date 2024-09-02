/*Java is an object oriented programming language.

Pillars of OOPs
1. Abstraction
2. Encapsulation
3. Inheritance
4. Polymorphism

poly - many
Morphism - forms

Polymorphism is the ability of an object to take on many forms.
1. Compile Time Polymorphism
2. Runtime Polymorphism

Method Overloading 
    (Compile Time Polymorphism)
    Where you can write method with same name but different parameters or data types
    1. Number of parameters
    2. Type of parameters
        e.g println() is a method overloading... can be used with different kinds of data types

    # Method cannot be overloaded by changing return types

    public class OOP1 {
        static void add(int a, int b){
            System.out.println(a+b);
        }

        static void add(double a, double b){
            System.out.println(a+b);
        }

        static void add(int[] arr, int n){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=arr[i];
            }
            System.out.println(sum);
        }

        static void add(int ... nums){
            int sum = 0;
            for(int i =0;i<nums.length;i++){
                sum += nums[i];
            }
            System.out.println(sum);
        }
        public static void main(String[] args){
            int a =10, b=20;
            add(a, b);
            double c = 10.6, d = 20.5;
            add(c, d);
            int arr[] = {10, 20, 30, 40};
            add(arr, 4);
            add(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
        }
    }


    public class 00P1 {
        // Create an overloaded method called prime, it should accepts the following arguments, return type is Boolean.
        // 1. 1 integer --> return true if the number is prime
        // 2. 2 integers --> return true if there are even numbers between the first and second numbers
        // 3. 3 integers --> return true if there are 3rd numbers between the first and second numbers

        static boolean prime(int n){
            if(n<2) return false;
            if(n==2 || n==3 || n==5) return true;
            if(n%2==0 || n%3==0) return false;
            for(int i=5;i*i<=n;i+=6){
                if(n%i==0 || n%(i+2)==0) return false;
            }
            return true;
        }

        static boolean prime(int a, int b){
            int count=0;
            for(int i=a;i<=b;i++){
                if(prime(i)){
                    count++;
                }
            }
            return count%2==0;
        }

        static boolean prime(int a, int b, int c){
            int count=0;
            for(int i=0;i<=b;i++){
                if(prime(i)){
                    count++;
                }
            }
            return count==c;
        }
        public static void main(String[] args){
            int a = 10, b = 20, c = 30;
            System.out.println(prime(a));
            System.out.println(prime(a, b));
            System.out.println(prime(a, b, c));
        }
    }

*/

public class OOP1 {
    // Create an overloaded method called prime, it should accepts the following arguments, return type is Boolean.
    // 1. 1 integer --> return true if the number is prime
    // 2. 2 integers --> return true if there are even numbers between the first and second numbers
    // 3. 3 integers --> return true if there are 3rd numbers between the first and second numbers

    static boolean prime(int n){
        if(n<2) return false;
        if(n==2 || n==3 || n==5) return true;
        if(n%2==0 || n%3==0) return false;
        for(int i=5;i*i<=n;i+=6){
            if(n%i==0 || n%(i+2)==0) return false;
        }
        return true;
    }

    static boolean prime(int a, int b){
        int count=0;
        for(int i=a;i<=b;i++){
            if(prime(i)){
                count++;
            }
        }
        return count%2==0;
    }

    static boolean prime(int a, int b, int c){
        int count=0;
        for(int i=0;i<=b;i++){
            if(prime(i)){
                count++;
            }
        }
        return count==c;
    }
    public static void main(String[] args){
        int a = 10, b = 20, c = 30;
        System.out.println(prime(a));
        System.out.println(prime(a, b));
        System.out.println(prime(a, b, c));
    }
}