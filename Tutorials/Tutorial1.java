// Question 1
// Classes: Student, Person, Engine, Book, Liquid, Transformer
// Object: Person1, MichaelJackson, NTU
// Attribute: Age, Result, Color
// Behaviour: Shoot, Work, Force
//

// Question 2

// Question 3

import java.util.Scanner;
import java.util.Arrays;

public class Tutorial1 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n, i;
    System.out.println("Enter number of Integer elements to be sorted.");
    n = scanner.nextInt();
    int a[] = new int[n];
    for (i = 0; i < n; i++) {
      System.out.println("Enter integer value for element no. : " + (i + 1));
      a[i] = scanner.nextInt();
    }
    scanner.close();
    System.out.println(Arrays.toString(a));
    bubble(a);
    System.out.println(Arrays.toString(a));
  }

  public static void bubble(int a[]) {
    int i, j, t;
    int n = a.length;
    for (i = n - 2; i >= 0; i--) {
      for (j = 0; j <= i; j++) {
        if (a[j] > a[j + 1]) {
          t = a[j];
          a[j] = a[j + 1];
          a[j + 1] = t;
        }
      }
    }
  }
}
