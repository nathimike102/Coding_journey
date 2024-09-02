/*
GUI:
    - Graphical User Interface
    - Java's GUI package is javax.swing

    import javax.swing.JOptionPane;
    public class GUI1 {
        public static void main(String[] args){
            String name = JOptionPane.showInputDialog("Enter your name");
            JOptionPane.showMessageDialog(null, "Hello " + name);
        }
    }

    import javax.swing.JOptionPane;
    class Employee{
        int id, salary;
        String name;
        Employee(){
            name = JOptionPane.showInputDialog("Enter your name: ");
            id = Integer.parseInt(JOptionPane.showInputDialog("Enter your id: "));
            salary = Integer.parseInt(JOptionPane.showInputDialog("Enter your salary: "));
            showDetails();
        }
        void showDetails(){
            String outputString = "ID: " + id + "\nName: " + name + "\nSalary: " + salary;
            JOptionPane.showMessageDialog(null, outputString);
        }
    }
    public class GUI1 {
        public static void main(String[] args){
            new Employee();
            new Employee();
        }
    }

    this keyword in Java:
        this keyword in Java represents the current object
        this keyword has several uses in Java
            1. Used to access instance members of the class within the class
            2. used to distinguish instance variables and local variables
            3. used in constructor chaining

    import javax.swing.JOptionPane;
    class Point{
        int x,y;
        Point(int x, int y){
            this.x = x;
            this.y = y;
        }
        void showPoint(){
            JOptionPane.showMessageDialog(null, "Value of x = " + x + "\nValue of y = " + y);
            // System.out.println(this); this will print the address of the object
        }
    }
    public class GUI1{
        public static void main(String[] args){
        p1.showPoint();
        }
    }
*/
class Student{
    int id;
    String name, branch;
    Student(String name, int id, String branch){
        this.name = name;
        this.branch = branch;
        this.id = id;
    }
    void printDetails(){
        System.out.println("Name: " + name + "\nID: " + id + "\nBranch: " + branch);
    }
}
public class GUI1{
    public static void main(String[] args){
        Student s1 =new Student("Nathi", 23, "CSE");
        s1.printDetails();

    }
}