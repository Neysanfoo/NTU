package Lab1;

import java.util.Scanner;

/** P2 */
public class P2 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Salary: ");
    int salary = scanner.nextInt();
    System.out.print("Merit: ");
    int merit = scanner.nextInt();
    char grade = 'C';
    if (salary < 600) {
      grade = 'C';
    } else if (salary <= 649) {
      if (merit < 10) grade = 'C';
      else grade = 'B';
    } else if (salary < 700) {
      grade = 'B';
    } else if (salary < 799) {
      if (merit < 20) grade = 'B';
      else grade = 'A';
    } else grade = 'A';
    System.out.println("salary: $" + salary + ", merit " + merit + " - Grade " + grade);
    scanner.close();
  }
}
