package Lab1;

import java.util.Scanner;

/** P1 */
public class P1 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.println("Enter a choice: a,c,d");
    char input = scanner.next().charAt(0);
    switch (input) {
      case 'a':
      case 'A':
        System.out.println("Action move fan");
        break;
      case 'c':
      case 'C':
        System.out.println("Comedy movie fan");
        break;
      case 'd':
      case 'D':
        System.out.println("Drama movie fan");
        break;
      default:
        System.out.println("Invalid choice");
    }
    scanner.close();
    
  }
}
