/*Composition - Fundamental OOP concept:
    A class can have other classes as its attributes and methods.

    class DateOfBirth{
        int day, month, year;
        DateOfBirth(int day, int month, int year){
            this.day = day;
            this.month = month;
            this.year = year;
        }public String toString(){
            return day + "-" + month + "-" + year;
        }
    }
    class Student{ //Student has a DateOfBirth reference
        String name, branch;
        DateOfBirth dob; //Composition
        Student(){}
        Student(String name, String branch, DateOfBirth dob){
            this.name = name;
            this.branch = branch;
            this.dob = dob;
        }
        void calculateAndPrintAge(){
            System.out.println("Age : " + (2024 - dob.year));
        }
    }
    class OOP3{
        public static void main(String[] args) {
            Student s1 = new Student();
            s1.branch = "CSE";
            s1.name = "Nathi";
            s1.dob = new DateOfBirth(20, 10, 2002);
            Student s2 = new Student("Nkosinathi", "CSE-DS", new DateOfBirth(1, 1, 1111));
            System.out.println(s1.dob);
            System.out.println(s2.dob);
            s1.calculateAndPrintAge();
            s2.calculateAndPrintAge();
        }
    }
    composition is called as "has-a" relationship

#_____________________________________________________________/#
Inheritance - Fundamental OOP concept:
    A process of one class acquiring properties of another.
    In java, we use extends keyword to perform inheritance
    Class Student extends Person
        #student        #Person
        -child          -parent
        -sub            -super
        -derived        -base

Inheritance is called as "is-a" relationship:

    //Parent class
    class Person{
        String name;
        int age;
        void introduce(){
            System.out.println("Hi, I am " + name + " and " + age +" years old." );
        }
    }
    //child class 1
    class Student extends Person{
        //instance variables of child class
        String sId;
        String branch;
    }
    //child class 2
    class Trainer extends Person{
        int empId;
        double salary;
    }
    public class OOP3{
        public static void main(String[] args) {
            Student s1 = new Student(); //Student Object
            Trainer t1 = new Trainer(); //Trainer Object
            s1.name = "Nathi";
            s1.age = 21;
            s1.sId = "23mh1a05h9";
            s1.branch = "CSE";
            t1.name = "Nkosinathi";
            t1.age = 21;
            s1.introduce();
            t1.introduce();
            Person p1 = new Person(); //Person Object
            System.out.println(p1 instance of Person); //true
            System.out.println(s1 instance of Person); //true
            System.out.println(t1 instance of Person); //true
        }
    }
    Every Student is a Person
    Every Trainer is a Person

Types of Inheritance:
    1. Single Inheritance
        one parent --> one child class
    2. Hierarchical Inheritance
        one parent --> multiple child classes
    3. Multilevel Inheritance
        Grand parent --> parent --> child
    4. Hybrid Inheritance
        combination of multiple inheritance
    5. Multiple Inheritance
        more than one parent class --> one child class (JAVA DOES NOT SUPPORT THIS due to DIAMOND PROBLEM)

*/
//Multiple Inheritance
class Person{ //Grand Parent (level 1)
    String name;
    int age;
    void introduce(){
        System.out.println("Hi, I am " + name + " and " + age +" years old." );
    }
}
class Student extends Person{ //Parent (level 2)
    String sId, branch, college;
}
class Intern extends Student{//Child (level 3)
    String iId;
    double salary;
}

public class OOP3 {
    public static void main(String[] args) {
        Intern t1 = new Intern();
        t1.name = "Nathi";
        t1.age = 21;
        t1.sId = "23mh1a05h9";
        t1.branch = "CSE";
        t1.college = "IIT";
        t1.iId = "23mh1a05h9";
        t1.salary = 100000;
        t1.introduce();
    }
}