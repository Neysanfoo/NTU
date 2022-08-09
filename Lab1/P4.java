package Lab1;

import java.util.Scanner;

/** P4 */
public class P4 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Height: ");
    int height = scanner.nextInt();
    scanner.close();
    if (height < 1) {
      System.out.println("Height cannot be less than 1");
      return;
    }
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < i+1; j++) {
        if ((i + j) % 2 == 0) {
          System.out.print("AA");
        } else {
          System.out.print("BB");
        }
      }
      System.out.println("");
    }
  }
}
