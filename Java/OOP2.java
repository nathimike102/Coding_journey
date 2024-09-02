/*
OOP
1. Clean Code
2. Head First Design patterns
 
    import java.util.Scanner;
    class Student{
        # instance variables
        String name;
        int age, totalMarks;
        float percentage;
        int[] marksArray;
        #instance methods
        void calculateTotal(){
            for(int eachMark: marksArray){
                totalMarks += eachMark;
            }
        }
        void calculatePercentage(){
            percentage = 100 * totalMarks / (float) marksArray.length;
        }
        void printStudentDetails(){
            calculateTotal();
            calculatePercentage();
            System.out.println("Name : " + name + " Age : " + age + ", has total marks of " + totalMarks + " and percentage of " + percentage + "%");
        }
    }

    public class OOP2 {
        public static void main(String[] args){
            Scanner sc = new Scanner(System.in);
            # Class_name object_name = new Class_name()
            Student s1 = new Student();
            s1.name = "Nkosinathi";
            s1.age = 21;
            s1.marksArray = new int[]{10, 20, 30, 40, 50};
            s1.printStudentDetails();
            sc.close();
        }
    }

    import java.util.Scanner;
    class Student{
        String rollNumber, name, gender;
        int age, passOutYear;
        double cgpa;
        //Setter method - used to set values to instance variables
        //mutators
        void setAllValues(String r, String n, String g, int a, int p, double c){
            rollNumber = r;
            name = n;
            gender = g;
            age = a;
            passOutYear = p;
            cgpa = c;
        }
        void printAllDetails(){
            System.out.println("Roll Number :\t" + rollNumber + "\nName :\t\t" + name + "\nGender :\t" + gender + "\nAge :\t\t" + age + "\nCgpa :\t\t" + cgpa + "\nPass out year :\t" + passOutYear);
        }
    }

    public class OOP2 {
        public static void main(String[] args){
            Student s1 = new Student();
            s1.setAllValues("23mh1a05h9", "Nathi", "Male", 21, 2027, 9.4);
            s1.printAllDetails();
        }
    }

    Object: 
        SuperClass for every class you create by default
        Has useful method whoich can be used by any of sub-classes.
        eg... equals(), hashCode(), toString()

        class Cat{
            String name;
            int age;
        }

        public class OOP2 {
            public static void main(String[] args){
                Cat c1 = new Cat();
                System.out.println(c1 instanceof Cat); # true
                System.out.println(c1 instanceof Object); # true
                // Object --> SuperClass for every class you create by default
                //             Has useful method whoich can be used by any of sub-classes.
                //             eg... equals(), hashCode(), toString()
            }
        }

        class Dog{
            String name;
            int age;
            void setNameAndAge(String n, int a){
                name = n;
                age = a;
            }
            // An overriding method from Object class
            public String toString(){
                return "Dog("+name+", "+age+")";
            }
        }

        public class OOP2 {
            public static void main(String[] args){
                Dog d1 = new Dog();
                d1.setNameAndAge("Papa Pig", 12);
                System.out.println(d1); //prints the string representing the Dog object
            }
        }
    
    Constructors:
    - constructor is a special method
    - is used to construct an object while creating it
    - is to initialise instance variables with values, whle creating objects.
    Constrcutor name should be same as class name.
    Constructor should not have return type.

    Types of Constructor:
        1. Default Constructor
        2. Parametric Constructor (parameterised constructor)
        3. Copy Construstor

    Every class will have a default constrcutor and that will be triggered upon creation of each object of that class.

    Constructor Overloading:
        class Cat{
            String name;
            int age;
            Cat() {} //Default Constructor

            Cat(String n){
                name = n;
            }

            Cat(String n, int a) { // Parametric Construct
                name = n;
                age = a;
            }
            void printCatDetails(){
                System.out.println("Name is: "+name);
                System.out.println("Age is :"+age);
            }
        }

        public class OOP2 {
            public static void main(String[] args){
                Cat c1 = new Cat("Pussy");
                c1.age = 10;
                c1.printCatDetails();
                Cat c2 = new Cat("Harry", 13);
                c2.printCatDetails();
            }
        }

*/
class BankAccount{
    int balanceAmount; //instance variable
    //Default COnstructor
    BankAccount() {}
    //Constructor
    BankAccount(int initialBalance){
        balanceAmount = initialBalance;
    }
    void printBankBalance(){
        System.out.println("Your current Bank balance is: "+balanceAmount);
    }
}

public class OOP2 {
    public static void main(String[] args){
        BankAccount account1 = new BankAccount(500); // 500 initialAmount
        account1.printBankBalance();
        BankAccount account2 = new BankAccount(); // Empty BankAccount
        account2.printBankBalance();
    }
}