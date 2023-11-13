import java.util.Scanner;

class Employee {
    int empNumber;
    String empName;
    double basicPay;

    // Method to accept employee details
    void getEmployeeDetails() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter Employee Number: ");
        empNumber = scanner.nextInt();

        scanner.nextLine(); // Consume the newline character left by nextInt()

        System.out.print("Enter Employee Name: ");
        empName = scanner.nextLine();

        System.out.print("Enter Basic Pay: ");
        basicPay = scanner.nextDouble();
    }

    // Method to calculate and display gross salary
    void calculateGrossSalary() {
        double DA = 0.2 * basicPay;
        double HRA = 0.05 * basicPay;
        double grossSalary = basicPay + DA + HRA;

        System.out.println("\nEmployee Details:");
        System.out.println("Employee Number: " + empNumber);
        System.out.println("Employee Name: " + empName);
        System.out.println("Basic Pay: " + basicPay);
        System.out.println("DA (20% of Basic Pay): " + DA);
        System.out.println("HRA (5% of Basic Pay): " + HRA);
        System.out.println("Gross Salary: " + grossSalary);
    }
}

public class EmployeeDetailsProgram {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of employees: ");
        int n = scanner.nextInt();

        // Create an array of Employee objects
        Employee[] employees = new Employee[n];

        // Input details for each employee
        for (int i = 0; i < n; i++) {
            System.out.println("\nEnter details for Employee " + (i + 1) + ":");
            employees[i] = new Employee();
            employees[i].getEmployeeDetails();
        }

        // Calculate and display gross salary for each employee
        for (Employee employee : employees) {
            employee.calculateGrossSalary();
        }

        scanner.close();
    }
}
